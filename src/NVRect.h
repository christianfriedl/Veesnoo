#import <Foundation/Foundation.h>

@interface NVRect : NSObject { }

@property int x, y, width, height;

-(id) initWithX: (int)ax Y: (int)ay Width: (int)awidth Height: (int)aheight;
-(NVRect*) copy;
-(void) moveToX: (int)ax Y: (int)ay;
-(void) resizeToWidth: (int)awidth Height: (int)aheight;
-(void) setOriginRelativeTo: (NVRect *) otherRect;
// -(CGRect *) CGRect;

@end
