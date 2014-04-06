#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVFocusManaging.h"
#import "NVApp.h"

@interface NVSimpleFocusManager : NSObject <NVFocusManaging> { }

@property (weak) NVWidget<NVKeyReceiving> *widget;
@property (weak) NVWidget *focusedWidget;
@property (strong) NSMutableArray *subWidgets;
@property BOOL isFocused;
@property (weak) NVApp *app;

-(id) initWithWidget: (NVWidget *)awidget;
-(BOOL) receiveKey: (int) ch;
-(void) focus;
-(void) deFocus;
-(void) focusFirst;
-(void) focusNext;
-(void) focusPrev;
-(void) addWidget: (NVWidget *)awidget;

@end
