#import"NVCursesWindow.h"
#import"NVWidget.h"
#import"NVCheckbox.h"
#import"NVButton.h"
#import"NVLabel.h"
#import"NVMenuItem.h"
#import"NVHorizontalMenu.h"

int main() {
    id pool = [[NSAutoreleasePool alloc] init];
    [[NVCursesManager sharedInstance] initCurses];
    NVWidget *win = [[NVWidget alloc] initWithRect: [[NVRect alloc] initWithX: 38 Y: 13 Width: 30 Height: 20]];
    NVMenuItem *m1 = [[NVMenuItem alloc] initWithParent: win Text: @"item1" X: 0 Y: 0];
    NVMenuItem *m2 = [[NVMenuItem alloc] initWithParent: win Text: @"item2" X: 0 Y: 0];
    NVHorizontalMenu *hm = [[NVHorizontalMenu alloc] initWithParent: win X: 0 Y: 4];
    [hm addWidget: m1];
    [hm addWidget: m2];
    [hm refresh];
    getch();
    [hm receiveKey: ' '];
    [hm refresh];
    getch();
    [[NVCursesManager sharedInstance] uninitCurses];
    [pool drain];
}
