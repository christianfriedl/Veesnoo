#import"NVContainer.h"
#import"NVWindow.h"
@implementation NVWindow

@synthesize title;

-(id)initWithX:(int)ax Y:(int)ay Width:(int)awidth Height:(int)aheight {
   self = [super initWithX: ax Y: ay Width: awidth Height: aheight];

    if (self != nil) {
        self.title = nil;
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
    if (self.title && [self.title length] > 0)
        [self addString: self.title atX: 2 Y: 0];
    [super refresh];
}

-(void) maximize {
    NVRect *screenRect = [[NVCursesManager sharedInstance] getMaxScreenRect];
    [self moveToX: 0 Y: 0];
    [self resizeToWidth: [screenRect width] Height: [screenRect height]];
}

@end
