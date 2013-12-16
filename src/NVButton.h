#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVKeyReceiving.h"
#import "NVSimpleFocusManager.h"

typedef enum { NVButtonState_normal, NVButtonState_pushed } NVButtonState;

@interface NVButton : NVWidget <NVKeyReceiving> { }

@property (retain) NSString *text;
@property NVButtonState state;
@property (retain) NVSimpleFocusManager *focusManager;

-(id) initWithParent: (NVWidget *) aparent Text: (NSString *) atext X: (int)ax Y: (int)ay;
-(void) refresh;
-(BOOL) receiveKey: (int)ch;
-(void) forwardInvocation: (NSInvocation *) anInvocation;

@end
