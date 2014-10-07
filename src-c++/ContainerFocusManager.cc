#include "ContainerFocusManager.h"

@implementation ContainerFocusManager

@synthesize widget;
@synthesize focusedWidget;
@synthesize subWidgets;
@synthesize isFocused;
@synthesize app;

-(id) initWithWidget: (Widget<KeyReceiving> *)awidget {
#ifdef DEBUG
    [Logger logText: [NSString stringWithFormat: @"ContainerFocusManager init: widget class=%@", NSStringFromClass([awidget class])]];
#endif
    self = [super init];
    if (self) {
        app = [App sharedInstance];
        widget = awidget;
        focusedWidget = nil;
        isFocused = NO;
        subWidgets = [[NSMutableArray alloc] initWithCapacity: 10];
        if ([widget respondsToSelector: @selector(subWidgets)]) {
            Widget<Containing> *container = (Widget<Containing> *) widget;
            NSMutableArray *wsw = [container subWidgets];
            int i, count = [wsw count];
            for (i=0; i < count; ++i)
                if ([[wsw objectAtIndex: i] conformsToProtocol: @protocol(KeyReceiving)]) {
                    id focusable = [wsw objectAtIndex: i];
                    [subWidgets addObject: focusable];
                }
        }
    }
    return self;
}

-(void) addWidget: (Widget *)awidget {
#ifdef DEBUG
    [Logger logText: [NSString stringWithFormat: @"ContainerFocusManager for %@ add widget of class: %@", NSStringFromClass([self.widget class]), NSStringFromClass([awidget class])]];
#endif
    if ([awidget conformsToProtocol: @protocol(KeyReceiving)]) {
#ifdef DEBUG
        [Logger logText: [NSString stringWithFormat: @"...is KeyReceiving!"]];
#endif
        Widget<KeyReceiving> *focusable = (Widget<KeyReceiving> *) awidget;
        [subWidgets addObject: focusable];
    }
}

-(BOOL) receiveKey: (int) ch {
#ifdef DEBUG
    [Logger logText: [NSString stringWithFormat: @"ContainerFocusManager receiveKey: widget class=%@ @ %ld, key='%c' (%i)", NSStringFromClass([self.widget class]), self.widget, ch, ch]];
#endif
    if (ch == ' ' || ch == '\t' || ch == KEY_STAB || ch == KEY_DOWN || ch == KEY_RIGHT || ch == 'j' || ch == 'l') {
        [self focusNext];
        return YES;
    }
    else if (ch == KEY_BACKSPACE || ch == KEY_BTAB || ch == KEY_UP || ch == KEY_LEFT || ch == 'k' || ch == 'h') {
        [self focusPrev];
        return YES;
    }
    return NO;
}

-(void) focusThis: (Widget<KeyReceiving>*) awidget {
    int i = 0, count = [subWidgets count];
    for (i=0; i < count; ++i) {
        Widget<KeyReceiving>* focusable = [subWidgets objectAtIndex: i];
        if (![focusable isEqual: awidget] && [focusable isFocused])
            [focusable deFocus];
    }
    [awidget focus];
    focusedWidget = awidget;
}

-(void) focus {
    isFocused = YES;
    [app setFocusedWidget: widget];
    [self focusFirst];
}

-(void) deFocus {
    [app setFocusedWidget: nil];
    isFocused = NO;
}

-(void) focusFirst {
    if ([subWidgets count] != 0)
        [self focusThis: [subWidgets objectAtIndex: 0]];
}

-(void) focusNext {
    int i = 0, count = [subWidgets count];
    if (count == 0)
        return;
    if (focusedWidget != nil)
        i = [subWidgets indexOfObject: focusedWidget];
    if (i == count - 1)
        i = 0;
    else
        ++i;
    [self focusThis: [subWidgets objectAtIndex: i]];
}

-(void) focusPrev {
    int i = 0, count = [subWidgets count];
    if (count == 0)
        return;
    if (focusedWidget != nil)
        i = [subWidgets indexOfObject: focusedWidget];
    if (i == 0)
        i = count - 1;
    else
        --i;
    [self focusThis: [subWidgets objectAtIndex: i]];
}

@end
