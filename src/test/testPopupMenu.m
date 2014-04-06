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
        NVWidget *win = [[NVWidget alloc] initWithX: 2 Y: 2 Width: 100 Height: 30];
        NVMenuItem *m1 = [[NVMenuItem alloc] initWithText: @"m1" X: 0 Y: 0];
        NVMenuItem *m2 = [[NVMenuItem alloc] initWithText: @"m2" X: 0 Y: 0];
        NVMenuItem *m3 = [[NVMenuItem alloc] initWithText: @"m3" X: 0 Y: 0];
        NVMenuItem *m4 = [[NVMenuItem alloc] initWithText: @"m4" X: 0 Y: 0];
        NVPopupMenu *pm = [[NVPopupMenu alloc] initWithX: 0 Y: 0];
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
