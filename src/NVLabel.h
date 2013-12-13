#include<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"

@interface NVLabel: NVWidget {
}

@property (retain) NSString *text;

-(id) initWithText: (NSString *)atext X: (int)ax Y:(int)ay;
-(id) initWithParent: (NVWidget *)aparent Text: (NSString *)atext X: (int)ax Y:(int)ay;
-(void)dealloc;
-(void)refresh;

@end

