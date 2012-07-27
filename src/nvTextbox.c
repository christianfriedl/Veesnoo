#include"nvTextbox.h"
static nvTextbox *nvTextbox__new_(int x, int y, cgString * text, unsigned int displaySize);

static void nvTextbox_insertChar_(nvWidget * this, char ch);

static void nvTextbox_revertChanges_(nvWidget * this);

static void nvTextbox_commitChanges_(nvWidget * this);

static nvTextbox *nvTextbox__new_(int x, int y, cgString * text, unsigned int displaySize) {
    nvTextbox *this = malloc(sizeof(*this));

    if (this != NULL) {
        this->text = text;
        this->oldText = cgString__new("");
        this->inputMode = nvInputMode_command;
        this->cursorPos = 0;
        this->displaySize = displaySize;
    } else
        cgAppState_THROW(cgAppState__getInstance(), Severity_fatal, cgExceptionID_CannotAllocate, "cannot allocate nvTextbox");
    return this;
}

nvWidget *nvTextbox__new(int x, int y, cgString * text, unsigned int displaySize) {
    nvWidget *this = nvWidget__new_(nvWidgetType_label, x, y, displaySize, 1,
                                    nvTextbox__new_(x, y, text, displaySize));

    nvWidget_setRefresh(this, (void (*)(nvWidget *))nvTextbox_refresh);
    nvWidget_setReceiveKey(this, (bool(*)(nvWidget *, int))nvTextbox_receiveKey);
    return this;
}

static void nvTextbox_insertChar_(nvWidget * this, char ch) {
    if (THIS(nvTextbox)->cursorPos == cgString_getSize(THIS(nvTextbox)->text))
        THIS(nvTextbox)->text = cgString_appendChar_I(THIS(nvTextbox)->text, ch);
    else
        THIS(nvTextbox)->text = cgString_insertChar_I(THIS(nvTextbox)->text, THIS(nvTextbox)->cursorPos, ch);
    THIS(nvTextbox)->cursorPos++;
}

void nvTextbox_delete(nvWidget * this) {
    nvWidget_delete_(this);
    cgString_delete(THIS(nvTextbox)->text);
    cgString_delete(THIS(nvTextbox)->oldText);
}

void nvTextbox_setInputMode(nvWidget * this, nvInputMode mode) {
    THIS(nvTextbox)->inputMode = mode;
    nvTextbox_refresh(this);
}

void nvTextbox_setText(nvWidget * this, cgString * text) {
    cgString_delete(THIS(nvTextbox)->text);
    THIS(nvTextbox)->text = text;
    nvTextbox_refresh(this);
}

void nvTextbox_refresh(nvWidget * this) {
    if (THIS(nvTextbox)->inputMode == nvInputMode_command)
        nvCursesWindow_attrOn(this->cw, A_REVERSE);

    if (THIS(nvTextbox)->cursorPos > THIS(nvTextbox)->displaySize)
        nvCursesWindow_addStringAt(this->cw, 0, 0,
                                   THIS(nvTextbox)->text + (THIS(nvTextbox)->cursorPos - THIS(nvTextbox)->displaySize));
    else
        nvCursesWindow_addStringAt(this->cw, 0, 0, THIS(nvTextbox)->text);

    if (THIS(nvTextbox)->inputMode == nvInputMode_command)
        nvCursesWindow_attrOff(this->cw, A_REVERSE);

    if (THIS(nvTextbox)->inputMode == nvInputMode_insert || THIS(nvTextbox)->inputMode == nvInputMode_replace)
        nvCursesWindow_moveCursorTo(this->cw, min(THIS(nvTextbox)->displaySize - 1, THIS(nvTextbox)->cursorPos), 0);
    else
        wmove(stdscr, 0, 0);    /* TODO this is hackery */
}

bool nvTextbox_receiveKey(nvWidget * this, int ch) {
    bool rv;

    mvaddstr(39, 0, cgString__newWithSprintf("---> mode, ch: %i,%i        ", THIS(nvTextbox)->inputMode, ch));
    if (THIS(nvTextbox)->inputMode == nvInputMode_insert) {
        mvaddstr(40, 0, cgString__newWithSprintf("---> insert mode: %i,%i        ", THIS(nvTextbox)->inputMode, ch));
        if (ch == NV_ESC) {
            THIS(nvTextbox)->inputMode = nvInputMode_command;
            nvTextbox_revertChanges_(this);
        } else if (ch == NV_ENTER) {
            THIS(nvTextbox)->inputMode = nvInputMode_command;
            nvTextbox_commitChanges_(this);
        } else
            nvTextbox_insertChar_(this, ch);
        rv = true;
    } else if (THIS(nvTextbox)->inputMode == nvInputMode_replace) {
        cgAppState_THROW(cgAppState__getInstance(), Severity_notice, cgExceptionID_GeneralNonfatalException,
                         "input mode replace not implemented yet");
        rv = false;
    } else if (THIS(nvTextbox)->inputMode == nvInputMode_command) {
        switch (ch) {
        case NV_COMMANDMODE_I:
            THIS(nvTextbox)->inputMode = nvInputMode_insert;
            rv = true;
            break;
        default:
            rv = false;
        }
    }
    nvTextbox_refresh(this);
    return rv;
}

cgString *nvTextbox_getText(nvWidget * this) {
    return THIS(nvTextbox)->text;
}

static void nvTextbox_revertChanges_(nvWidget * this) {
    cgString_delete(THIS(nvTextbox)->text);
    THIS(nvTextbox)->text = THIS(nvTextbox)->oldText;
    THIS(nvTextbox)->oldText = cgString__new("");
    THIS(nvTextbox)->cursorPos = 0;
}
static void nvTextbox_commitChanges_(nvWidget * this) {
    cgString_delete(THIS(nvTextbox)->oldText);
    THIS(nvTextbox)->oldText = cgString_clone(THIS(nvTextbox)->text);
}
