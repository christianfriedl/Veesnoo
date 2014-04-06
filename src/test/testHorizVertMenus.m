#import"NVCursesWindow.h"
#import"NVWidget.h"
#import"NVCheckbox.h"
#import"NVButton.h"
#import"NVLabel.h"
#import"NVMenuItem.h"
#import"NVHorizontalMenu.h"
#import"NVVerticalMenu.h"

int main() {
    @autoreleasepool {
        [[NVCursesManager sharedInstance] initCurses];
        NVWidget *win = [[NVWidget alloc] initWithX: 2 Y: 2 Width: 100 Height: 30];
        NVMenuItem *m1 = [[NVMenuItem alloc] initWithText: @"m1" X: 5 Y: 0];
        NVMenuItem *m2 = [[NVMenuItem alloc] initWithText: @"m2" X: 2 Y: 0];
        NVMenuItem *m3 = [[NVMenuItem alloc] initWithText: @"m3" X: 2 Y: 5];
        NVMenuItem *m4 = [[NVMenuItem alloc] initWithText: @"m4" X: 0 Y: 0];
        NVMenuItem *m5 = [[NVMenuItem alloc] initWithText: @"m5" X: 1 Y: 10];
        NVMenuItem *m6 = [[NVMenuItem alloc] initWithText: @"m6" X: 100 Y: 3];
        NVMenuItem *m7 = [[NVMenuItem alloc] initWithText: @"m7" X: 0 Y: 13];
        NVMenuItem *m8 = [[NVMenuItem alloc] initWithText: @"m8" X: 2 Y: 3];
        NVHorizontalMenu *hm = [[NVHorizontalMenu alloc] initWithX: 0 Y: 0];
        [hm addWidget: m1];
        [hm addWidget: m2];
        [hm addWidget: m3];
        [hm addWidget: m4];
        NVVerticalMenu *vm = [[NVVerticalMenu alloc] initWithX: 0 Y: 2];
        [vm addWidget: m5];
        [vm addWidget: m6];
        [vm addWidget: m7];
        [vm addWidget: m8];

        [hm pack];
        [vm pack];

        [hm focus];
        [hm refresh];
        getch();
        [vm focus];
        [vm refresh];
        getch();
        [hm receiveKey: ' '];
        [hm refresh];
        getch();
        [vm receiveKey: ' '];
        [vm refresh];
        getch();
        [[NVCursesManager sharedInstance] uninitCurses];
    }
}
