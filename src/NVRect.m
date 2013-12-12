#import"NVRect.h"

@implementation NVRect
@synthesize x, y, width, height;

-(id) initWithX: (int)ax Y: (int)ay Width: (int)awidth Height: (int)aheight {
    self = [super init];
    if (self) {
        self.x = ax;
        self.y = ay;
        self.width = awidth;
        self.height = aheight;
    }
    return self;
}
-(NVRect*) copy {
    return [[NVRect alloc] initWithX: self.x Y:self.y Width:self.width Height:self.height];
}
-(void) moveToX: (int)ax Y: (int)ay {
    self.x = ax;
    self.y = ay;
}
-(void) resizeToWidth: (int)awidth Height: (int)aheight {
    self.width = awidth;
    self.height = aheight;
}
@end
