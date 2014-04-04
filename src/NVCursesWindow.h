#import <ncurses.h>
#import <Foundation/Foundation.h>
#import "NVCursesManager.h"
#import "NVRect.h"
#import "NVDumper.h"


@interface NVCursesWindow: NSObject { }

@property (assign) WINDOW *window;

-(id)initWithRect: (NVRect *) rect;
-(void)addString: (NSString*)text;
-(void)addString: (NSString *)text atX: (int)x Y:(int)y;
-(void)addCh: (int)ch atX:(int)x Y:(int)y;
-(void)refresh;
-(void)addBorder;
-(void)addCh:(int)ch;
-(int)width;
-(int)height;
-(void)attrOn:(int)attr;
-(void)attrOff:(int)attr;
-(void)resizeToWidth:(int)width Height:(int)height;
-(void)moveCursorToX:(int)x Y:(int)y;
-(void)moveToX:(int)x Y:(int)y;
-(void)fillBackground:(int)ch;
@end
