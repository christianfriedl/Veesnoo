#import"NVCheckbox.h"


@implementation NVCheckbox

@synthesize state;

-(BOOL) receiveKey: (int)ch {
    self.state = !self.state;
    return true;
}

-(void) refresh {
    [self addString: [NSString stringWithFormat: @"[%c]", (self.state ? 'x' : ' ')] atX: 0 Y: 0];
    [super refresh];
}

@end
