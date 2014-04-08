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
        NVWindow *win = [[NVWindow alloc] initWithX: 0 Y: 0 Width: 100 Height: 30];
        [win setTitle: @"Main Window"];
        [win maximize];
        NVLabel *l1 = [[NVLabel alloc] initWithText: @"Text 1:" X: 0 Y: 0];
        NVTextfield *tf1 = [[NVTextfield alloc] initWithX: 8 Y: 0 Width: 10];
        [win addWidget: tf1];
        [win addWidget: l1];
        NVTextfield *tf2 = [[NVTextfield alloc] initWithX: 8 Y: 1 Width: 10];
        NVLabel *l2 = [[NVLabel alloc] initWithText: @"Text 1:" X: 0 Y: 1];
        [win addWidget: tf2];
        [win addWidget: l2];
        NVTextfield *tf3 = [[NVTextfield alloc] initWithX: 8 Y: 2 Width: 10];
        NVLabel *l3 = [[NVLabel alloc] initWithText: @"Text 3:" X: 0 Y: 2];
        [win addWidget: tf3];
        [win addWidget: l3];

        [win pack];

        [app setMainWindow: win];
        [app focus];
        [app run];

        [[NVCursesManager sharedInstance] uninitCurses];
    }
}
