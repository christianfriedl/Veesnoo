#import"NVContainer.h"
#import"NVWindow.h"
@implementation NVWindow

-(id)initWithX:(int)ax Y:(int)ay Width:(int)awidth Height:(int)aheight {
   self = [super initWithX: ax Y: ay Width: awidth Height: aheight];

    if (self != nil) {
    }

    return self;
}

-(void) pack {
    int i;
    [super pack];
    self.contentRect = [[NVRect alloc] initWithX: 1 Y: 1 Width: [self.rect width] -2 Height: [self.rect height] -2];
}

-(void) refresh {
    [self.cw addBorder];
    [super refresh];
}

@end
