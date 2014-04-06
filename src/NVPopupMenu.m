#import "NVPopupMenu.h"

@implementation NVPopupMenu

@synthesize menu;

-(id)initWithX: (int) ax Y: (int) ay {
    self = [super initWithX: ax Y: ay Width: 1 Height: 1];
    if (self) {
        self.menu = [[NVVerticalMenu alloc] initWithX: 0 Y: 0];
        [self addWidget: self.menu];
        self.isVisible = YES;
    }
    return self;
}

-(void) pack {
    int i;
    [super pack];
    [self.rect setWidth: [[self.menu rect] width] + 2];
    [self.rect setHeight: [[self.menu rect] height] + 2];
    self.contentRect = [[NVRect alloc] initWithX: 1 Y: 1 Width: [self.rect width] -2 Height: [self.rect height] -2];
    [self setCWSize];
}

-(void) refresh {
    #ifdef DEBUG
        [NVDumper dumpRects: self Text: @"NVPopupMenu refresh: " StartLine: 10 Interrupt: YES];
    #endif
    [self setCWPosition];
    [self setCWSize];
    [self.cw addBorder];
    [self.cw refresh];
    [self.menu refresh];
}

-(void) addMenuItem: (NVMenuItem *) anitem {
    [self.menu addWidget: anitem];
}


@end
