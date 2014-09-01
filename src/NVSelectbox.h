#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVKeyReceiving.h"
#import "NVPopupMenu.h"
#import "NVSingleFocusManager.h"

@interface NVSelectbox : NVContainer <NVPushDelegate> {}

@property (retain) NVPopupMenu *popupMenu;
@property (retain) NSDictionary *options;

-(id) initWithX: (int)ax Y: (int)ay Width: (int)awidth;
-(void) refresh;
-(BOOL) receiveKey: (int)ch;
-(void) forwardInvocation: (NSInvocation *) anInvocation;
-(BOOL) wasPushed: (NVWidget<NVKeyReceiving> *) target;
-(void) addOption: (id) avalue Text: (NSString*) atext;

@end
