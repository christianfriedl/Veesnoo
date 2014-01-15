#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVKeyReceiving.h"
#import "NVSimpleFocusManager.h"

typedef enum { NVEditState_none, NVEditState_insert, NVEditState_replace } NVEditState;

@interface NVTextfield : NVWidget <NVKeyReceiving> { }

@property (retain) NSMutableString *text;
@property NVEditState editState;
@property (retain) NVSimpleFocusManager *focusManager;
@property int cursorX;

-(id) initWithParent: (NVWidget *) aparent Text: (NSString *) atext X: (int)ax Y: (int)ay Width: (int)awidth;
-(id) initWithParent: (NVWidget *) aparent X: (int)ax Y: (int)ay Width: (int)awidth;
-(void) refresh;
-(BOOL) receiveKey: (int)ch;
-(void) forwardInvocation: (NSInvocation *) anInvocation;

@end
