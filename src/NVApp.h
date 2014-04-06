#import<Foundation/Foundation.h>
#import"NVKeyReceiving.h"
@class NVWidget;

@interface NVApp: NSObject { }

@property (retain) NVWidget<NVKeyReceiving>* focusedWidget;
@property (retain) NVWidget<NVKeyReceiving>* mainWindow;

+(NVApp *) sharedInstance;
-(void) receiveKey: (int) ch;
-(void) focus;
-(void) run;

@end
