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
        NVTextfield *tf1 = [[NVTextfield alloc] initWithX: 0 Y: 0 Width: 10];
        [win addWidget: tf1];
        NVTextfield *tf2 = [[NVTextfield alloc] initWithX: 0 Y: 1 Width: 10];
        [win addWidget: tf2];
        NVTextfield *tf3 = [[NVTextfield alloc] initWithX: 0 Y: 2 Width: 10];
        [win addWidget: tf3];

        [win pack];

        [app setMainWindow: win];
        [app focus];
        [app run];

        [[NVCursesManager sharedInstance] uninitCurses];
    }
}
