#import"NVCheckbox.h"
#pragma clang diagnostic ignored "-Wprotocol"


@implementation NVCheckbox

@synthesize state;
@synthesize focusManager;

-(id) init {
    self = [super init];
    if (self) {
        state = NO;
        focusManager = [[NVSimpleFocusManager alloc] initWithWidget: self];
    }
    return self;
}
-(BOOL) receiveKey: (int)ch {
    self.state = !self.state;
    return true;
}

-(void) refresh {
    [self addString: [NSString stringWithFormat: @"[%c]", (self.state ? 'x' : ' ')] atX: 0 Y: 0];
    [super refresh];
}

-(void) forwardInvocation: (NSInvocation *)anInvocation {
    if ([focusManager respondsToSelector: [anInvocation selector]])
        [anInvocation invokeWithTarget:focusManager];
    else
        [super forwardInvocation:anInvocation];
}


@end
