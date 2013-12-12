#import"NVRect.h"
int main() {
    NVRect *nvr = [[NVRect alloc] initWithX: 20 Y: 20 Width: 20 Height: 20];
    NSLog(@"%i\n", [nvr x]);
    NSLog(@"%i\n", [nvr y]);
    NSLog(@"%i\n", [nvr width]);
    NSLog(@"%i\n", [nvr height]);
    [nvr release];
}

