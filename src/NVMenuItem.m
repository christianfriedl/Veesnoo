#import "NVMenuItem.h"

@implementation NVMenuItem

@synthesize text;

-(id) initWithParent: (NVWidget *)aparent Text: (NSString *)atext X: (int)ax Y:(int)ay {
    self = [super initWithParent: aparent Rect: [[NVRect alloc] initWithX: ax Y: ay Width: [atext length] Height: 1]];
    if (self) {
        text = atext;
    }
    return self;
}
-(id) initWithText: (NSString *)atext X: (int)ax Y:(int)ay {
    self = [super initWithRect: [[NVRect alloc] initWithX: ax Y: ay Width: [atext length] Height: 1]];
    if (self) {
        text = atext;
    }
    return self;
}
-(void) dealloc {
    [self.text release];
}
-(void) refresh {
    [self addString: text atX: 0 Y: 0];
    [super refresh];
}

@end
