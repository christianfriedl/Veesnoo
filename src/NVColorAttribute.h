#include<Foundation/Foundation.h>
#include<ncurses.h>

@interface NVColorAttribute : NSObject {}

@property int fg;
@property int bg;
@property int attr;
@property int pair;

-(id) initWithFg: (int) afg Bg: (int) abg Attr: (int) attr;
-(void) onCw: (NVCursesWindow *) aCw;
-(void) offCw: (NVCursesWindow *) aCw;
@end
