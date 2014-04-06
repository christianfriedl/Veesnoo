#import"NVCursesWindow.h"
#import"NVWidget.h"
#import"NVTextfield.h"
#import"NVCheckbox.h"
#import"NVButton.h"
#import"NVLabel.h"
#import"NVMenuItem.h"
#import"NVHorizontalMenu.h"
#import"NVPopupMenu.h"
#import"NVApp.h"
#import"NVWindow.h"

int main() {
    @autoreleasepool {
        [[NVCursesManager sharedInstance] initCurses];
        NVApp *app = [NVApp sharedInstance];
        NVWindow *win = [[NVWindow alloc] initWithParent: nil X: 0 Y: 0 Width: 100 Height: 50];
        NVTextfield *tf1 = [[NVTextfield alloc] initWithParent: win Text: @"abcd" X: 1 Y: 1 Width: 10];
        [win addWidget: tf1];
        NVTextfield *tf2 = [[NVTextfield alloc] initWithParent: win Text: @"efgh" X: 1 Y: 2 Width: 10];
        [win addWidget: tf2];
        NVTextfield *tf3 = [[NVTextfield alloc] initWithParent: win Text: @"ijkl" X: 1 Y: 3 Width: 10];
        [win addWidget: tf3];

        [win pack];

        [app setMainWindow: win];
        [app focus];
        [tf1 refresh];
        [tf2 refresh];
        [tf3 refresh];
        while (1) {
            int ch = getch();
            [app receiveKey: ch];
            [tf1 refresh];
            [tf2 refresh];
            [tf3 refresh];
        }
        [[NVCursesManager sharedInstance] uninitCurses];
    }
}
