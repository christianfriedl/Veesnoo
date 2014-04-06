#pragma clang diagnostic ignored "-Wprotocol"
#import"NVHorizontalMenu.h"

@implementation NVHorizontalMenu

-(id) initWithX: (int)ax Y: (int)ay {
    self = [super initWithX: ax Y: ay Width: 1 Height: 1];
    return self;
}

-(void) pack {
    int i, width = 0;
    int count = [[self subWidgets] count];

    for (i=0; i < count; ++i) {
        if (i > 0)
            width += 1;
        [[[self subWidgets] objectAtIndex: i] moveToX: width Y: 0];
        width += [[[[self subWidgets] objectAtIndex: i] rect] width];
    }
    [[self rect] setWidth: width];
}

-(void) addWidget: (NVWidget *)awidget {
    [awidget setParent: self];
    [[self subWidgets] addObject: awidget];
    [[self focusManager] addWidget: awidget];
}

-(void) forwardInvocation: (NSInvocation *)anInvocation {
    if ([[self focusManager] respondsToSelector: [anInvocation selector]])
        [anInvocation invokeWithTarget:[self focusManager]];
    else
        [super forwardInvocation:anInvocation];
}

@end
