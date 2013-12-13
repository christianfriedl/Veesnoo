#import"NVHorizontalMenu.h"

@implementation NVHorizontalMenu

@synthesize subWidgets;

-(id) initWithParent: (NVWidget *) aparent X: (int)ax Y: (int)ay {
    self = [super initWithParent: aparent Rect: [[NVRect alloc] initWithX: ax Y: ay Width: 20 Height: 1]];
    if (self) {
        subWidgets = [[NSMutableArray alloc] initWithCapacity: 10];
    }
    return self;
}
-(void) dealloc {
    [subWidgets release];
    [super dealloc];
}
-(void) refresh {
    int i, width = 0;
    for (i=0; i < [subWidgets count]; ++i) {
        if (i > 0)
            width += 1;
        [[[subWidgets objectAtIndex: i] rect] setX: width];
        width += [[[subWidgets objectAtIndex: i] rect] width];
    }
    [[self rect] setWidth: width];

    int count = [subWidgets count];
    for (i=0; i < count; ++i)
        [[subWidgets objectAtIndex: i] refresh];
}

-(void) addWidget: (NVWidget *)awidget {
    [awidget setParent: self];
    [subWidgets addObject: awidget];
}

@end
