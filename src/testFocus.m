#import"NVCursesWindow.h"
#import"NVWidget.h"
#import"NVCheckbox.h"
#import"NVButton.h"
#import"NVLabel.h"
#import"NVMenuItem.h"
#import"NVHorizontalMenu.h"
#import"NVVerticalMenu.h"

int main() {
    id pool = [[NSAutoreleasePool alloc] init];
    [[NVCursesManager sharedInstance] initCurses];
    NVWidget *win = [[NVWidget alloc] initWithRect: [[NVRect alloc] initWithX: 2 Y: 2 Width: 100 Height: 30]];
    NVMenuItem *m1 = [[NVMenuItem alloc] initWithParent: win Text: @"item1" X: 0 Y: 0];
    NVMenuItem *m2 = [[NVMenuItem alloc] initWithParent: win Text: @"item2" X: 0 Y: 0];
    NVMenuItem *m3 = [[NVMenuItem alloc] initWithParent: win Text: @"item3" X: 0 Y: 0];
    NVMenuItem *m4 = [[NVMenuItem alloc] initWithParent: win Text: @"item4" X: 0 Y: 0];
    NVHorizontalMenu *hm = [[NVHorizontalMenu alloc] initWithParent: win X: 0 Y: 0];
    [hm addWidget: m1];
    [hm addWidget: m2];
    NVVerticalMenu *vm = [[NVVerticalMenu alloc] initWithParent: win X: 0 Y: 2];
    [vm addWidget: m3];
    [vm addWidget: m4];
    [hm refresh];
    [vm refresh];
    getch();
    [hm receiveKey: ' '];
    [hm refresh];
    getch();
    [vm receiveKey: ' '];
    [vm refresh];
    getch();
    [[NVCursesManager sharedInstance] uninitCurses];
    [pool drain];
}
