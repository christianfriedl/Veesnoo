#include "Widget.h"

@interface NVLabel: NVWidget {
}

@property (retain) NSString *text;

-(id) initWithText: (NSString *)atext X: (int)ax Y:(int)ay;
-(void)refresh;

@end

