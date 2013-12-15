#import "NVCursesManager.h"

@implementation NVCursesManager

@synthesize bufferedMode;
@synthesize echo;
@synthesize keypadAvailable;
@synthesize width;
@synthesize height;

static NVCursesManager* instance = nil;

+(NVCursesManager *)sharedInstance {
    if (instance == nil)
        instance = [[NVCursesManager alloc] init];
    return instance;
}


-(id)init {
    self = [super init];
    if (self) {
        self.bufferedMode = false;
        self.echo = false;
        self.keypadAvailable = true;
        self.width = 0;
        self.height = 0;
    }
    return self;
}

-(void)initCurses {
    initscr();
    getmaxyx(stdscr, self.height, self.width);
    if (!self.bufferedMode) {
        raw();
        cbreak();
    }
    if (!self.echo) {
        noecho();
    }
    if (self.keypadAvailable) {
        keypad(stdscr, TRUE);
        set_escdelay(25);       /* set ESC delay to a very low level so we can use the ESC key AND the function keys ('tis good enough for VIM, 'tis good enough for me) */
    }
    if (has_colors())
        start_color();
    else
        @throw [NSException exceptionWithName: @"NoColorsException" reason: @"this terminal has no colors." userInfo: nil];
}

-(void)uninitCurses {
    endwin();
}

-(WINDOW *)createWindowWithX: (int)x Y:(int)y Width:(int)aWidth Height:(int)aHeight {
    return newwin(aHeight, aWidth, y, x);
}

-(void)destroyWindow: (WINDOW *)window {
    delwin(window);
}

-(void)refresh {
    refresh();
}

@end
