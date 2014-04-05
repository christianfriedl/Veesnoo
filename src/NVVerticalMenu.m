#pragma clang diagnostic ignored "-Wprotocol"
#import"NVVerticalMenu.h"

@implementation NVVerticalMenu

-(id) initWithParent: (NVWidget *) aparent X: (int)ax Y: (int)ay {
    self = [super initWithParent: aparent Rect: [[NVRect alloc] initWithX: ax Y: ay Width: 20 Height: 1]];
    return self;
}

-(void) pack {
    int i, width = 0;
    int count = [[self subWidgets] count];

    for (i=0; i < count; ++i) {
        if ([[[[self subWidgets] objectAtIndex: i] rect] width] > width)
            width = [[[[self subWidgets] objectAtIndex: i] rect] width];
        NVWidget *w = [[self subWidgets] objectAtIndex: i];
        [w moveToX: 0 Y: i];
    }
    [[self rect] setWidth: width];
    [[self rect] setHeight: count];
}
-(void) refresh {
#ifdef DEBUG
    [NVDumper dumpRects: self Text: @"NVVerticalMenu refresh: " StartLine: 10 Interrupt: YES];
#endif
    [super refresh];
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
