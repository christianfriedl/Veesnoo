#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVContainer.h"

@interface NVVerticalMenu : NVContainer { }

-(id) initWithParent: (NVWidget *) aparent X: (int)ax Y: (int)ay;
-(void) pack;
-(void) addWidget: (NVWidget *)awidget;
-(void) forwardInvocation: (NSInvocation *)anInvocation;
-(void) refresh;

@end