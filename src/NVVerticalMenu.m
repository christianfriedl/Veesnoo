#pragma clang diagnostic ignored "-Wprotocol"
#import"NVVerticalMenu.h"

@implementation NVVerticalMenu

@synthesize subWidgets;
@synthesize focusManager;

-(id) initWithParent: (NVWidget *) aparent X: (int)ax Y: (int)ay {
    self = [super initWithParent: aparent Rect: [[NVRect alloc] initWithX: ax Y: ay Width: 20 Height: 1]];
    if (self) {
        subWidgets = [[NSMutableArray alloc] initWithCapacity: 10];
        focusManager = [[NVSimpleFocusManager alloc] initWithWidget: self];
    }
    return self;
}

-(void) dealloc {
    [subWidgets release];
    [focusManager release];
    [super dealloc];
}

-(void) refresh {
    int i, width = 0;
    int count = [subWidgets count];

    for (i=0; i < count; ++i) {
        if ([[[subWidgets objectAtIndex: i] rect] width] > width)
            width = [[[subWidgets objectAtIndex: i] rect] width];
        [[[subWidgets objectAtIndex: i] rect] setY: i];
    }
    [[self rect] setWidth: width];

    for (i=0; i < count; ++i)
        [[subWidgets objectAtIndex: i] refresh];
}

-(void) addWidget: (NVWidget *)awidget {
    [awidget setParent: self];
    [subWidgets addObject: awidget];
    [focusManager addWidget: awidget];
}

-(void) forwardInvocation: (NSInvocation *)anInvocation {
    if ([focusManager respondsToSelector: [anInvocation selector]])
        [anInvocation invokeWithTarget:focusManager];
    else
        [super forwardInvocation:anInvocation];
}

@end
