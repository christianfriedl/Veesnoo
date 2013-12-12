#include<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVCursesWindow.h"
#import "NVRect.h"

@interface NVWidget: NSObject { }

@property(retain) NVCursesWindow *cw;
@property(retain) NVRect *rect;
@property(retain) NVRect *absRect;
@property BOOL isVisible;
@property(retain) NVWidget *parent;

-(id)initWithParent: (NVWidget*)aparent X:(int)ax Y:(int)ay Width:(int)awidth Height:(int)aheight;
-(id)initWithRect: (NVRect *) rect;
-(id)initWithParent: (NVWidget*)aparent Rect: (NVRect *)arect;
-(void)dealloc;
-(void) refresh;
-(void)resizeToWidth: (int)awidth Height:(int)aheight;
-(void) moveToX: (int)x Y:(int)y;
-(void)addString: (NSString*)text;
-(void)addString: (NSString *)text atX: (int)ax Y:(int)ay;
-(void)addCh: (int)ch;
-(void)addCh: (int)ch atX:(int)ax Y:(int)ay;
// -(BOOL) receiveKey: (int)ch;
// -(void) setInputMode: (NVInputMode)mode;
-(void) focus;
-(void) deFocus;

@end
