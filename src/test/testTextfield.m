#import"NVCursesWindow.h"
#import"NVTextfield.h"

int main() {
    @autoreleasepool {
        [[NVCursesManager sharedInstance] initCurses];
        NVWidget *win = [[NVWidget alloc] initWithX: 2 Y: 2 Width: 100 Height: 30];
        NVTextfield *t = [[NVTextfield alloc] initWithX: 0 Y: 0 Width: 20];
        int ch = 0;
        [t focus];
        [t refresh];
        while (ch != 'q') {
            ch = getch();
            [t receiveKey: ch];
            [t refresh];
        }

        [[NVCursesManager sharedInstance] uninitCurses];
    }
}
