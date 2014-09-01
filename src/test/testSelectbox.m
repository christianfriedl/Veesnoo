#import"NVCursesWindow.h"
#import"NVWidget.h"
#import"NVLabel.h"
#import"NVSelectbox.h"
#import"NVApp.h"
#import"NVWindow.h"

int main() {
    @autoreleasepool {
        [[NVCursesManager sharedInstance] initCurses];
        NVApp *app = [NVApp sharedInstance];
        NVWindow *win = [[NVWindow alloc] initWithX: 0 Y: 0 Width: 100 Height: 30];
        [win setTitle: @"Main Window"];
        [win maximize];
        [app setMainWindow: win];
        NVLabel *l1 = [[NVLabel alloc] initWithText: @"Selectbox 1:" X: 0 Y: 0];
        NVSelectbox *sb1 = [[NVSelectbox alloc] initWithX: 18 Y: 0 Width: 10];
        [sb1 addOption: @"value" Text: @"text"];
        [win addWidget: sb1];
        [win addWidget: l1];

        [win pack];

        [app focus];
        [app run];

        [[NVCursesManager sharedInstance] uninitCurses];
    }
}
