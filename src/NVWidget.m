#import"NVWidget.h"

@implementation NVWidget

@synthesize cw;
@synthesize rect; 
@synthesize contentRect;
@synthesize isVisible;
@synthesize parent;

-(id)initWithRect: (NVRect *) arect {
    self = [super init];
    if (self) {
        self.rect = arect;
        self.contentRect = [arect copy];
        self.cw = [[NVCursesWindow alloc] initWithRect: self.rect];
        self.isVisible = YES;
    }
    return self;
}

-(id)initWithParent: (NVWidget*)aparent Rect: (NVRect *)arect {
   self = [super init];

    if (self != nil) {
        self.rect = arect;
        self.contentRect = [arect copy];
        self.cw = [[NVCursesWindow alloc] initWithRect: self.rect];
        self.isVisible = YES;
        self.parent = aparent;
    }

    return self;
}

-(id)initWithParent: (NVWidget*)aparent X:(int)ax Y:(int)ay Width:(int)awidth Height:(int)aheight {
   self = [super init];

    if (self != nil) {
        self.rect = [[NVRect alloc] initWithX: ax Y: ay Width: awidth Height: aheight];
        self.contentRect = [rect copy];
        self.cw = [[NVCursesWindow alloc] initWithRect: [[NVRect alloc] initWithX:ax Y:ay Width:awidth Height:aheight]];
        self.isVisible = YES;
        self.parent = aparent;
    }

    return self;
}

-(id)initWithX:(int)ax Y:(int)ay Width:(int)awidth Height:(int)aheight {
    self = [super init];

    if (self != nil) {
        self.rect = [[NVRect alloc] initWithX: ax Y: ay Width: awidth Height: aheight];
        self.contentRect = [rect copy];
        self.cw = [[NVCursesWindow alloc] initWithRect: [[NVRect alloc] initWithX:ax Y:ay Width:awidth Height:aheight]];
        self.isVisible = YES;
        self.parent = nil;
    }

    return self;
}

-(void)resizeToWidth: (int) awidth Height: (int) aheight {
    [self.cw moveCursorToX:0 Y:0];
    [self.cw resizeToWidth:awidth Height:aheight];
    [self.rect resizeToWidth:awidth Height:aheight];
}

-(void)moveToX: (int)ax Y: (int)ay {
    [self.cw moveToX: ax Y: ay];
    [self.rect moveToX: ax Y: ay];
}

-(NVRect *) absContRect {
    if (parent == nil)
        return [contentRect copy];
    NVRect *acr = [self.parent absContRect];
    [acr setX: [acr x] + [[self contentRect] x]];
    [acr setY: [acr y] + [[self contentRect] y]];
    return acr;
}

-(void) setCWPosition {
    NVRect *acr = [self absContRect];
    [self.cw moveToX: [acr x] Y: [acr y]];
}

-(void) refresh {
    [self setCWPosition];
    [cw refresh];
}

-(void)addString: (NSString*)text {
    [cw addString: text];
}
-(void)addString: (NSString *)text atX: (int)ax Y:(int)ay {
    [cw addString:text atX:ax Y:ay];
}
-(void)addCh: (int)ch {
    [cw addCh:ch];
}
-(void)addCh: (int)ch atX:(int)ax Y:(int)ay {
    [cw addCh:ch atX:ax Y:ay];
}

@end
