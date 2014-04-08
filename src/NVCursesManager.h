#include<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVRect.h"

#ifndef min
#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif
#ifndef max
#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif

#define NVKEY_ENTER (10)

@interface NVCursesManager: NSObject { }

@property BOOL bufferedMode;
@property BOOL echo;
@property BOOL keypadAvailable;
@property int width, height;
@property int nextPair;

+(NVCursesManager *)sharedInstance;
-(void)initCurses;
-(void)uninitCurses;
-(WINDOW *)createWindowWithX: (int)x Y:(int)y Width:(int)aWidth Height:(int)aHeight;
-(void)destroyWindow: (WINDOW *)window;
-(void)refresh;
-(NVRect *) getMaxScreenRect;
-(int) colorPairWithFg: (int) afg Bg: (int) abg;

@end
