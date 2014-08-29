#import "NVLabel.h"

@implementation NVLabel

@synthesize text;

-(id) initWithText: (NSString *)atext X: (int)ax Y:(int)ay {
    self = [super initWithX: ax Y: ay Width: [atext length] Height: 1];
    if (self) {
        text = atext;
    }
    return self;
}
-(void) refresh {
    [self addString: text atX: 0 Y: 0];
    [super refresh];
}

@end
