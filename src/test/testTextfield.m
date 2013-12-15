#import"NVCursesWindow.h"
#import"NVTextfield.h"

int main() {
    id pool = [[NSAutoreleasePool alloc] init];
    [[NVCursesManager sharedInstance] initCurses];
    NVWidget *win = [[NVWidget alloc] initWithRect: [[NVRect alloc] initWithX: 2 Y: 2 Width: 100 Height: 30]];
    NVTextfield *t = [[NVTextfield alloc] initWithParent: win Text: @"sometext" X: 0 Y: 0 Width: 20];
    int ch;
    [t focus];
    [t refresh];
    while ((ch = getch() != 'q'))
        [t receiveKey: ch];

    [[NVCursesManager sharedInstance] uninitCurses];
    [pool drain];
}
