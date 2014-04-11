#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVKeyReceiving.h"
#import "NVPopupMenu.h"
#import "NVSingleFocusManager.h"

@interface NVTextfield : NVWidget <NVKeyReceiving> { }

@property (retain) NVSingleFocusManager *focusManager;
@property (retain) NVPopupMenu *popupMenu;

-(id) initWithX: (int)ax Y: (int)ay Width: (int)awidth;
-(void) refresh;
-(BOOL) receiveKey: (int)ch;
-(void) forwardInvocation: (NSInvocation *) anInvocation;

@end
