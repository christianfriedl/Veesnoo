#import"NVREct.h"
#import"NVContainer.h"
#import"stdio.h"

void testAbsRect() {
    NVContainer *parent = [[NVContainer alloc] initWithX: 10 Y: 10 Width: 100 Height: 100];
    NVContainer *child = [[NVContainer alloc] initWithX: 10 Y: 10 Width: 100 Height: 100];
    NVWidget *grandChild = [[NVWidget alloc] initWithX: 10 Y: 10 Width: 100 Height: 100];

    [parent addWidget: child];
    [child addWidget: grandChild];
    assert([[grandChild absRect] x] == 30);
    assert([[grandChild absRect] y] == 30);
}


int main() {
    [[NVCursesManager sharedInstance] initCurses];
    testAbsRect();
    [[NVCursesManager sharedInstance] uninitCurses];
    return 0;
}
