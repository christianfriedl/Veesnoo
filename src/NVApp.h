#import<Foundation/Foundation.h>
#import"NVKeyReceiving.h"
@class NVWidget;

@interface NVApp: NSObject { }

@property (retain) NVWidget<NVKeyReceiving>* focusedWidget;

+(NVApp *) sharedInstance;
-(void) receiveKey: (int) ch;

@end
