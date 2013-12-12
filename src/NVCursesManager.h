#include<ncurses.h>
#import"Foundation/Foundation.h"
#ifndef min
#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif
@interface NVCursesManager: NSObject { }

@property BOOL bufferedMode;
@property BOOL echo;
@property BOOL keypadAvailable;
@property int width, height;

+(NVCursesManager *)sharedInstance;
-(void)initCurses;
-(void)uninitCurses;
-(WINDOW *)createWindowWithX: (int)x Y:(int)y Width:(int)aWidth Height:(int)aHeight;
-(void)destroyWindow: (WINDOW *)window;
-(void)refresh;

@end
