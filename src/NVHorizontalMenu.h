#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVContainer.h"

@interface NVHorizontalMenu : NVContainer { }

-(id) initWithX: (int)ax Y: (int)ay;
-(void) addWidget: (NVWidget *)awidget;
-(void) forwardInvocation: (NSInvocation *)anInvocation;
-(void) pack;

@end
