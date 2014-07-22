#import "NVMenuItem.h"

#pragma clang diagnostic ignored "-Wprotocol"

@implementation NVMenuItem

@synthesize text;
@synthesize focusManager;
@synthesize isPushed;
@synthesize delegate;

-(id) initWithText: (NSString *)atext X: (int)ax Y:(int)ay {
    self = [super initWithX: ax Y: ay Width: [atext length] Height: 1];
    if (self) {
        text = atext;
        focusManager = [[NVSingleFocusManager alloc] initWithWidget: self];
    }
    return self;
}

-(void) refresh {
    if ([focusManager isFocused])
        [[self cw] attrOn: A_REVERSE];
    [self addString: text atX: 0 Y: 0];
    if ([focusManager isFocused])
        [[self cw] attrOff: A_REVERSE];
    [super refresh];
}

-(BOOL) receiveKey: (int) ch {
#ifdef DEBUG
    [NVLogger logText: [NSString stringWithFormat: @"NVMenuItem receiveKey: ch='%c' (%i) ... ", ch, ch]];
#endif
    if (ch == NVKEY_ENTER || ch == ' ') {
        self.isPushed = YES;
        [self.delegate wasPushed: self];
        self.isPushed = NO;
        return YES;
    } else
        return NO;
}

-(void) forwardInvocation: (NSInvocation *)anInvocation {
    if ([focusManager respondsToSelector: [anInvocation selector]])
        [anInvocation invokeWithTarget:focusManager];
    else
        [super forwardInvocation:anInvocation];
}


@end
