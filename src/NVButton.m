#import<unistd.h>
#import"NVButton.h"

#pragma clang diagnostic ignored "-Wprotocol"

@implementation NVButton

@synthesize text;
@synthesize state;
@synthesize focusManager;

-(id) initWithText: (NSString *) atext X: (int)ax Y: (int)ay {
    self = [super initWithX: ax Y: ay Width: [atext length] + 4 Height: 1];
    if (self) {
        text = atext;
        state = NVButtonState_normal;
        focusManager = [[NVSingleFocusManager alloc] initWithWidget: self];
    }
    return self;
}

-(void) refresh {
    if (state == NVButtonState_pushed)
        [[self cw] attrOn: A_REVERSE];
    [self addString: [NSString stringWithFormat: @"[ %@ ]", self.text] atX: 0 Y: 0];
    if (state == NVButtonState_pushed)
        [[self cw] attrOff: A_REVERSE];
    [super refresh];
}

-(void) switchState {
    if (state == NVButtonState_pushed)
        state = NVButtonState_normal;
    else
        state = NVButtonState_pushed;
    [self refresh];
}

-(BOOL) receiveKey: (int)ch {
    if (ch == ' ' || ch == 13) {
        [self switchState];
        // Todo do stuff
        [self switchState];
        return true;
    }
    return false;
}

- (void)forwardInvocation:(NSInvocation *)anInvocation {
    if ([focusManager respondsToSelector: [anInvocation selector]])
        [anInvocation invokeWithTarget:focusManager];
    else
        [super forwardInvocation:anInvocation];
}

@end

