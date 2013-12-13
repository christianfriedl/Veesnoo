#import<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"

@interface NVButton : NVWidget { }

@property (retain) NSString *text;

-(id) initWithParent: (NVWidget *) aparent Text: (NSString *) atext X: (int)ax Y: (int)ay;
-(void) dealloc;
-(void) refresh;

@end
