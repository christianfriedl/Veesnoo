#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVFocusManaging.h"
#import "NVApp.h"

@interface NVSingleFocusManager : NSObject <NVFocusManaging> { }

@property (retain) NVWidget<NVKeyReceiving> *widget;
@property BOOL isFocused;
@property (retain) NVApp *app;

-(id) initWithWidget: (NVWidget *)awidget;
-(BOOL) receiveKey: (int) ch;
-(void) focus;
-(void) deFocus;

@end
