#import <stdlib.h>
#import "NVCursesWindow.h"

@implementation NVCursesWindow

@synthesize window;

-(id)initWithRect: (NVRect *) rect {
    self = [super init];
    if (self) {
        self.window = [[NVCursesManager sharedInstance] createWindowWithX: [rect x] Y: [rect y] Width: [rect width] Height: [rect height]];
    }
    return self;
}

-(void)dealloc {
    [[NVCursesManager sharedInstance] destroyWindow: self.window];
}

-(void)addString: (NSString*)text {
    int x, y;

    getyx(self.window, y, x);

    [self addString: text atX: x Y: y];
}

-(void) addString: (NSString *)text atX: (int)x Y:(int)y {
    int width, height;

    getmaxyx(self.window, height, width);
    mvwaddnstr(self.window, y, x, [text UTF8String], min([text length], width - x));
}

-(void)addCh:(int)ch {
    int x, y;

    getyx(self.window, y, x);
    [self addCh:ch atX:x Y:y];
}

-(void)addCh: (int)ch atX:(int)x Y:(int)y {
    mvwaddch(self.window, y, x, ch);
    wnoutrefresh(self.window);
}

-(void) refresh {
    [[NVCursesManager sharedInstance] refresh];
    wrefresh(self.window);
}

-(void) addBorder {
    box(self.window, 0, 0);
    wnoutrefresh(self.window);
    [[NVCursesManager sharedInstance] refresh];
}

-(int)width {
    int width, height;

    getmaxyx(self.window, height, width);
    return width;
}

-(int)height {
    int width, height;

    getmaxyx(self.window, height, width);
    return height;
}

-(void)attrOn:(int)attr {
    wattron(self.window, attr);
}

-(void)attrOff:(int)attr {
    wattroff(self.window, attr);
}

-(void)resizeToWidth:(int)width Height:(int)height {
    if ((wresize(self.window, height, width)) == ERR)
        @throw [NSException exceptionWithName: @"CursesWindowException" reason: @"unable to resize window" userInfo: nil];
}

-(void)moveCursorToX:(int)x Y:(int)y {
    wmove(self.window, y, x);
    wnoutrefresh(self.window);
}

-(void)moveToX:(int)x Y:(int)y {
    if ((mvwin(self.window, y, x)) != OK)
        @throw [NSException exceptionWithName: @"CursesWindowException" reason: [NSString stringWithFormat: @"unable to move window %ld to x=%i, y=%i", self.window, x, y] userInfo: nil];
}

-(void)fillBackground:(int)ch {
    int x, y, maxx, maxy;
    getmaxyx(self.window, maxy, maxx);
    for (y = 0; y < maxy; ++y)
        for (x = 0; x < maxx; ++x)
            [self addCh:ch atX: x Y: y];
}

@end
