#import<Foundation/Foundation.h>
#import"NVWindow.h"
@class NVWidget;
@class NVColorAttribute;

@interface NVApp: NSObject { }

@property (retain) NVWidget<NVKeyReceiving>* focusedWidget;
@property (retain) NVWindow* mainWindow;
@property (retain) NVColorAttribute* contentColAttr;
@property (retain) NVColorAttribute* borderColAttr;
@property (retain) NVColorAttribute* focusedColAttr;
@property (retain) NVColorAttribute* focusedBorderColAttr;
@property (retain) NVColorAttribute* activeColAttr;

+(NVApp *) sharedInstance;
-(void) receiveKey: (int) ch;
-(void) focus;
-(void) run;

@end
