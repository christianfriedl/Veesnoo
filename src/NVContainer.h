#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVContaining.h"
#import "NVSimpleFocusManager.h"

/*
 * NVContainer is a Container of widgets that will also be focusable and pass on the focus
 * - which is probably what we want of almost all containers anyway
 */

@interface NVContainer : NVWidget <NVContaining, NVKeyReceiving> { }

@property (retain) NSMutableArray *subWidgets;
@property (retain) NVSimpleFocusManager *focusManager;

-(id) initWithParent: (NVWidget *)aparent Rect: (NVRect *)arect;
-(void) dealloc;
-(void) refresh;
-(void) addWidget: (NVWidget *)awidget;
-(void) forwardInvocation: (NSInvocation *)anInvocation;
-(void) pack;

@end
