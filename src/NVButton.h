#include<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVCursesWindow.h"

@interface NVButton : NSObject { }

@property (NVLabel*) label;

-(void) refresh;

@end
