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
        NVLabel *l1 = [[NVLabel alloc] initWithText: @"Selectbox 1:" X: 0 Y: 0];
        NVSelectbox *sb1 = [[NVSelectbox alloc] initWithX: 18 Y: 0 Width: 10];
        [win addWidget: sb1];
        [win addWidget: l1];

        [win pack];

        [app setMainWindow: win];
        [app focus];
        [app run];

        [[NVCursesManager sharedInstance] uninitCurses];
    }
}
