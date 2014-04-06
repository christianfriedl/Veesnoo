#include<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVSingleFocusManager.h"

@interface NVMenuItem: NVWidget <NVKeyReceiving> { }

@property (retain) NSString *text;
@property (retain) NVSingleFocusManager *focusManager;

-(id) initWithText: (NSString *)atext X: (int)ax Y:(int)ay;
-(id) initWithParent: (NVWidget *)aparent Text: (NSString *)atext X: (int)ax Y:(int)ay;
-(void)refresh;
-(void) forwardInvocation: (NSInvocation *)anInvocation;

@end

