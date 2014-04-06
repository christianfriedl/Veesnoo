#import"NVCursesWindow.h"
#import"NVTextfield.h"

int main() {
    @autoreleasepool {
        [[NVCursesManager sharedInstance] initCurses];
        NVWidget *win = [[NVWidget alloc] initWithX: 1 Y: 1 Width: 100 Height: 30];
        NVWidget *w = [[NVWidget alloc] initWithX: 0 Y: 0 Width: 20 Height: 1];
        [w addString: @"1.1 string"];
        [w refresh];
        NVWidget *w2 = [[NVWidget alloc] initWithX: 1 Y: 1 Width: 20 Height: 1];
        [w2 addString: @"2.2 string"];
        [w2 refresh];
        getch();

        [[NVCursesManager sharedInstance] uninitCurses];
    }
}
