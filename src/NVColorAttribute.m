#import"NVCursesManager.h"
#import"NVCursesWindow.h"
#import"NVColorAttribute.h"

@implementation NVColorAttribute

@synthesize fg;
@synthesize bg;
@synthesize attr;
@synthesize pair;

-(id) initWithFg: (int) afg Bg: (int) abg Attr: (int) aattr {
    self = [super init];
    if (self) {
        self.pair = [[NVCursesManager sharedInstance] colorPairWithFg: afg Bg: abg];
        self.fg = afg;
        self.bg = abg;
        self.attr = aattr;
    }
    return self;
}

-(void) onCw: (NVCursesWindow *) aCw {
    [aCw pairOn: self.pair];
    [aCw attrOn: self.attr];
}

-(void) offCw: (NVCursesWindow *) aCw {
    [aCw pairOff: self.pair];
    [aCw attrOff: self.attr];
}
@end
