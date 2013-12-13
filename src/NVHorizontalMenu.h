#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVContainer.h"

@interface NVHorizontalMenu : NVWidget <NVContainer> { }

@property (retain) NSMutableArray *subWidgets;

-(id) initWithParent: (NVWidget *) aparent X: (int)ax Y: (int)ay;
-(void) dealloc;
-(void) refresh;
-(void) addWidget: (NVWidget *)awidget;

@end
