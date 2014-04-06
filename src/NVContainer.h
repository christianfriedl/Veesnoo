#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVContaining.h"
#import "NVContainerFocusManager.h"

/*
 * NVContainer is a Container of widgets that will also be focusable and pass on the focus
 * - which is probably what we want of almost all containers anyway
 */

@interface NVContainer : NVWidget <NVContaining, NVKeyReceiving> { }

@property (retain) NSMutableArray *subWidgets;
@property (retain) NVContainerFocusManager *focusManager;

-(id)initWithX:(int)ax Y:(int)ay Width:(int)awidth Height:(int)aheight;
-(void) refresh;
-(void) addWidget: (NVWidget *)awidget;
-(void) forwardInvocation: (NSInvocation *)anInvocation;
-(void) pack;

@end
