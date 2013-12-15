#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVContaining.h"
#import "NVSimpleFocusManager.h"

@interface NVHorizontalMenu : NVWidget <NVContaining, NVKeyReceiving> { }

@property (retain) NSMutableArray *subWidgets;
@property (retain) NVSimpleFocusManager *focusManager;

-(id) initWithParent: (NVWidget *) aparent X: (int)ax Y: (int)ay;
-(void) dealloc;
-(void) refresh;
-(void) addWidget: (NVWidget *)awidget;
-(void) forwardInvocation: (NSInvocation *)anInvocation;

@end
