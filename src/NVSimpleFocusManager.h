#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVFocusManager.h"

@interface NVSimpleFocusManager : NSObject <NVFocusManager> { }

@property (retain) NVWidget<NVKeyReceiver> *widget;
@property (retain) NVWidget *focusedWidget;
@property (retain) NSMutableArray *subWidgets;
@property BOOL isFocused;

-(id) initWithWidget: (NVWidget *)awidget;
-(void) dealloc;
-(BOOL) receiveKey: (int) ch;
-(void) focus;
-(void) deFocus;
-(void) focusFirst;
-(void) focusNext;
-(void) focusPrev;
-(void) addWidget: (NVWidget *)awidget;

@end
