@interface NVWindow : NVContainer {}

@property(strong) NSString *title;

-(id) initWithX:(int)ax Y:(int)ay Width:(int)awidth Height:(int)aheight;
-(void) pack;
-(void) refresh;
-(void) maximize;

@end
