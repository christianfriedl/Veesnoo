#import"NVContainer.h"
#import"NVWindow.h"
@implementation NVWindow

-(id)initWithParent: (NVWidget*)aparent X:(int)ax Y:(int)ay Width:(int)awidth Height:(int)aheight {
   self = [super initWithParent: aparent Rect: [[NVRect alloc] initWithX: ax Y: ay Width: awidth Height: aheight]];

    if (self != nil) {
    }

    return self;
}
@end
