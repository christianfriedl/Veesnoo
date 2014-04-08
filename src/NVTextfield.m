#include <wctype.h>
#import"NVTextfield.h"
#import"NVColorAttribute.h"

#pragma clang diagnostic ignored "-Wprotocol"

@interface NVTextfield(Private)
- (void) cursorLeft;
- (void) cursorRight;
@end

@implementation NVTextfield

@synthesize text;
@synthesize editState;
@synthesize focusManager;
@synthesize cursorX;


-(id) initWithText: (NSString *) atext X: (int)ax Y: (int)ay Width: (int)awidth {
    self = [super initWithX: ax Y: ay Width: awidth Height: 1];
    if (self) {
        text = [[NSMutableString alloc] initWithString: atext];
        editState = NVEditState_none;
        focusManager = [[NVSingleFocusManager alloc] initWithWidget: self];
        cursorX = [atext length];
    }
    return self;
}

-(id) initWithX: (int)ax Y: (int)ay Width: (int)awidth {
    return [self initWithText: @"" X: ax Y: ay Width: awidth];
}

-(void) refresh {
    if ([self isFocused]) {
        if ([self editState] == NVEditState_none) {
            [self.focusedColAttr onCw: self.cw];
        } else {
            [self.activeColAttr onCw: self.cw];
        }
    }
    [self.cw fillBackground: ' '];
    int startX = max(0, cursorX - [[self rect] width]);
    int lenX = min([[self text] length] - startX, [[self rect] width] - startX);
    [self addString: [self.text substringWithRange: NSMakeRange(startX, lenX)] atX: 0 Y: 0];
    [self.cw resetColors];
    if (startX > 0)
        [self addCh: '<' atX: 0 Y: 0];
    if ([[self text] length] - startX > [[self rect] width])
        [self addCh: '>' atX: [[self rect] width] Y: 0];
    [[self cw] moveCursorToX: cursorX Y: 0];
    [super refresh];
}

-(BOOL) receiveKey: (int)ch {
#ifdef DEBUG
    [NVLogger logText: [NSString stringWithFormat: @"NVTextfield receiveKey: ch='%c'", ch]];
#endif
    if ([self editState] == NVEditState_none) {
        switch (ch) {
            case NVKEY_ENTER:
                self.editState = NVEditState_insert;
                return YES;
                break;
            default:
                return NO;
                break;
        }
    } else if ([self editState] == NVEditState_insert || [self editState] == NVEditState_replace) {
        switch (ch) {
            case NVKEY_ENTER:
                self.editState = NVEditState_none;
                return YES;
            case KEY_RIGHT:
                [self cursorRight];
                return YES;
            case KEY_LEFT:
                [self cursorLeft];
                return YES;
            case KEY_HOME:
            case KEY_UP:
                cursorX = 0;
                return YES;
            case KEY_END:
            case KEY_DOWN:
                cursorX = [[self text] length];
                return YES;
            default:
                if (iswprint(ch)) {
                    if ([self editState] == NVEditState_insert)
                        [self.text insertString: [NSString stringWithFormat: @"%c", ch] atIndex: self.cursorX];
                    else
                        [self.text replaceCharactersInRange: NSMakeRange(self.cursorX, 1) 
                                 withString: [NSString stringWithFormat: @"%c", ch]];
                    [self cursorRight];
                    return YES;
                } else
                    return NO;
                break;
        }
    } else
        @throw [NSException exceptionWithName: @"NVTextfieldException" reason: @"unknown edit state" userInfo: nil];
    return NO;
}

- (void) cursorRight {
    if (self.cursorX < [self.text length] - 1)
        ++cursorX;
}

- (void) cursorLeft {
    if (self.cursorX > 0)
        --cursorX;
}

- (void)forwardInvocation:(NSInvocation *)anInvocation {
    if ([focusManager respondsToSelector: [anInvocation selector]])
        [anInvocation invokeWithTarget:focusManager];
    else
        [super forwardInvocation:anInvocation];
}

@end


