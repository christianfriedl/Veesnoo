#include<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVSingleFocusManager.h"
#import "NVPushDelegate.h"

@interface NVMenuItem: NVWidget <NVKeyReceiving> { }

@property (retain) NSString *text;
@property (retain) NVSingleFocusManager *focusManager;
@property BOOL isPushed;
@property (retain) NSObject<NVPushDelegate> *delegate;

-(id) initWithText: (NSString *)atext X: (int)ax Y:(int)ay;
-(void)refresh;
-(BOOL) receiveKey: (int) ch;
-(void) forwardInvocation: (NSInvocation *)anInvocation;

@end

