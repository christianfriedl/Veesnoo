#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVFocusManaging.h"
#import "NVApp.h"

@interface NVSimpleFocusManager : NSObject <NVFocusManaging> { }

@property (retain) NVWidget<NVKeyReceiving> *widget;
@property (retain) NVWidget *focusedWidget;
@property (retain) NSMutableArray *subWidgets;
@property BOOL isFocused;
@property (retain) NVApp *app;

-(id) initWithWidget: (NVWidget *)awidget;
-(BOOL) receiveKey: (int) ch;
-(void) focus;
-(void) deFocus;
-(void) focusFirst;
-(void) focusNext;
-(void) focusPrev;
-(void) addWidget: (NVWidget *)awidget;

@end
