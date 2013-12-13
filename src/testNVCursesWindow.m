#import"NVCursesWindow.h"
#import"NVWidget.h"
#import"NVCheckbox.h"
#import"NVButton.h"
#import"NVLabel.h"
#import"NVMenuItem.h"
#import"NVHorizontalMenu.h"

int main() {
    id pool = [[NSAutoreleasePool alloc] init];
    [[NVCursesManager sharedInstance] initCurses];
    NVWidget *win = [[NVWidget alloc] initWithRect: [[NVRect alloc] initWithX: 38 Y: 13 Width: 30 Height: 20]];
    NVLabel *l = [[NVLabel alloc] initWithParent: win Text: @"a label" X: 0 Y: 3];
    NVWidget *w = [[NVWidget alloc] initWithParent: win Rect: [[NVRect alloc] initWithX: 0 Y: 0 Width: 20 Height: 1]];
    NVCheckbox *c = [[NVCheckbox alloc] initWithParent: win Rect: [[NVRect alloc] initWithX: 0 Y: 1 Width: 3 Height: 1]];
    NVButton *b = [[NVButton alloc] initWithParent: win Text: @"button" X: 0 Y: 2];
    NVMenuItem *m1 = [[NVMenuItem alloc] initWithParent: win Text: @"item1" X: 0 Y: 0];
    NVMenuItem *m2 = [[NVMenuItem alloc] initWithParent: win Text: @"item2" X: 0 Y: 0];
    NVHorizontalMenu *hm = [[NVHorizontalMenu alloc] initWithParent: win X: 0 Y: 4];
    [hm addWidget: m1];
    [hm addWidget: m2];
    [w addString: @"abcde"];
    getch();
    [w refresh];
    [c refresh];
    [l refresh];
    getch();
    [c receiveKey: getch()];
    [c refresh];
    getch();
    [b refresh];
    getch();
    [hm refresh];
    getch();
    [[NVCursesManager sharedInstance] uninitCurses];
    [pool drain];
}
