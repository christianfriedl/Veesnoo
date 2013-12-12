#import"NVCursesWindow.h"
#import"NVWidget.h"
#import"NVCheckbox.h"

int main() {
    id pool = [[NSAutoreleasePool alloc] init];
    [[NVCursesManager sharedInstance] initCurses];
    NVWidget *win = [[NVWidget alloc] initWithRect: [[NVRect alloc] initWithX: 38 Y: 13 Width: 30 Height: 20]];
    NVWidget *w = [[NVWidget alloc] initWithParent: win Rect: [[NVRect alloc] initWithX: 0 Y: 0 Width: 20 Height: 1]];
    NVCheckbox *c = [[NVCheckbox alloc] initWithParent: win Rect: [[NVRect alloc] initWithX: 0 Y: 1 Width: 3 Height: 1]];
    [w addString: @"abcde"];
    getch();
    [w refresh];
    [c refresh];
    getch();
    [c receiveKey: getch()];
    [c refresh];
    getch();
    [[NVCursesManager sharedInstance] uninitCurses];
    [pool drain];
}
