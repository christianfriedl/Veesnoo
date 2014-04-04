#import"NVCursesWindow.h"
#import"NVWidget.h"
#import"NVCheckbox.h"
#import"NVButton.h"
#import"NVLabel.h"
#import"NVMenuItem.h"
#import"NVHorizontalMenu.h"
#import"NVPopupMenu.h"

int main() {
    @autoreleasepool {
        [[NVCursesManager sharedInstance] initCurses];
        NVWidget *win = [[NVWidget alloc] initWithRect: [[NVRect alloc] initWithX: 2 Y: 2 Width: 100 Height: 30]];
        NVMenuItem *m1 = [[NVMenuItem alloc] initWithParent: win Text: @"item1" X: 0 Y: 0];
        NVMenuItem *m2 = [[NVMenuItem alloc] initWithParent: win Text: @"item2" X: 0 Y: 0];
        NVMenuItem *m3 = [[NVMenuItem alloc] initWithParent: win Text: @"item3" X: 0 Y: 0];
        NVMenuItem *m4 = [[NVMenuItem alloc] initWithParent: win Text: @"item4" X: 0 Y: 0];
        NVPopupMenu *pm = [[NVPopupMenu alloc] initWithParent: win X: 0 Y: 0];
        [pm addMenuItem: m1];
        [pm addMenuItem: m2];
        [pm addMenuItem: m3];
        [pm addMenuItem: m4];

        [pm pack];

        [pm focus];
        [pm refresh];
        getch();
        [pm receiveKey: ' '];
        [pm refresh];
        getch();
        [pm receiveKey: ' '];
        [pm refresh];
        getch();
        [[NVCursesManager sharedInstance] uninitCurses];
    }
}
