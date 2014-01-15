#import"NVWidget.h"
#import"NVKeyReceiving.h"
#import"NVSimpleFocusManager.h"
#pragma clang diagnostic ignored "-Wprotocol"

@interface NVCheckbox: NVWidget <NVKeyReceiving> { }

@property BOOL state;
@property (retain) NVSimpleFocusManager* focusManager;

-(id) init;
-(BOOL) receiveKey: (int)ch;
-(void) refresh;
-(void) forwardInvocation: (NSInvocation *)anInvocation;

@end
