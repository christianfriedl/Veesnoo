#include<ncurses.h>
#import"Foundation/Foundation.h"
#import "NVWidget.h"

@interface NVLabel: NVWidget {
}
@property NSString* text;

-(id) initWithX: (int)x Y:(int)y Text: (NSString*)text;
-(void)dealloc;
-(void)refresh;
-(void)setText: (NSString*)text;

@end

