#import"NVCursesWindow.h"
#import"NVWidget.h"

int main() {
    id pool = [[NSAutoreleasePool alloc] init];
    [[NVCursesManager sharedInstance] initCurses];
    NVWidget *win = [[NVWidget alloc] initWithRect: [[NVRect alloc] initWithX: 38 Y: 13 Width: 30 Height: 20]];
    NVWidget *w = [[NVWidget alloc] initWithParent: win Rect: [[NVRect alloc] initWithX: 0 Y: 0 Width: 20 Height: 1]];
    [w addString: @"abcde"];
    getch();
    [w refresh];
    getch();
    [[NVCursesManager sharedInstance] uninitCurses];
    [pool drain];
}
