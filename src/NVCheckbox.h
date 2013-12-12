#import"NVWidget.h"
#import"NVKeyReceiver.h"

@interface NVCheckbox: NVWidget <NVKeyReceiver> { }

@property BOOL state;

-(BOOL) receiveKey: (int)ch;

-(void) refresh;

@end
