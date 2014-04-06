#import "NVContainer.h"
#import "NVVerticalMenu.h"
#import "NVMenuItem.h"

@interface NVPopupMenu : NVContainer {}

@property (retain) NVVerticalMenu *menu;

-(id)initWithX: (int) ax Y: (int) ay;
-(void) refresh;
-(void) addMenuItem: (NVMenuItem *) anitem;
-(void) pack;

@end
