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

int main() {
    @autoreleasepool {
        [[NVCursesManager sharedInstance] initCurses];
        NVApp *app = [NVApp sharedInstance];
        NVWidget *win = [[NVWidget alloc] initWithRect: [[NVRect alloc] initWithX: 2 Y: 2 Width: 100 Height: 30]];
        NVTextfield *tf = [[NVTextfield alloc] initWithParent: win Text: @"abcd" X: 1 Y: 1 Width: 10];

        [tf focus];
        [tf refresh];
        int ch = getch();
        while (ch != 'q') {
            [app receiveKey: ch];
            [tf refresh];
            ch = getch();
        }
        [[NVCursesManager sharedInstance] uninitCurses];
    }
}
