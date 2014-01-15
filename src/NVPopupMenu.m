#import "NVPopupMenu.h"

@implementation NVPopupMenu

@synthesize menu;

-(id)initWithParent: (NVWidget *) parent X: (int) ax Y: (int) ay {
    self = [super initWithParent: parent Rect: [[NVRect alloc] initWithX: ax Y: ay Width: 5 Height: 5]];
    if (self) {
        self.menu = [[NVVerticalMenu alloc] initWithParent: self X: ax + 1 Y: ay + 1];
        [self addWidget: self.menu];
        self.isVisible = YES;
    }
    return self;
}

-(id)initWithRect: (NVRect *) arect {
    self = [super initWithParent: nil Rect: arect];
    if (self) {
        self.rect = arect;
        self.contentRect = [[NVRect alloc] initWithX: [self.rect x] +1 Y: [self.rect y] +1 Width: [self.rect width] -2 Height: [self.rect height] -2];
        self.cw = [[NVCursesWindow alloc] initWithRect: self.rect];
        self.menu = [[NVVerticalMenu alloc] initWithRect: [[NVRect alloc] initWithX: 0 Y: 0 Width: [self.rect width] - 2 
                                                  Height: [self.rect height] - 2]];
        self.isVisible = YES;
    }
    return self;
}

-(void) pack {
    int i;
    [super pack];
    [self.rect setWidth: [[self.menu rect] width] + 2];
    [self.rect setHeight: [[self.menu rect] height] + 2];
    self.contentRect = [[NVRect alloc] initWithX: [self.rect x] +1 Y: [self.rect y] +1 Width: [self.rect width] -2 Height: [self.rect height] -2];
}

-(void) refresh {
    [self setCWPosition];
    [self.cw addBorder];
    [self.cw refresh];
    [self.menu refresh];
}

-(void) addMenuItem: (NVMenuItem *) anitem {
    [self.menu addWidget: anitem];
}


@end
