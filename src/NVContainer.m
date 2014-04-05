#pragma clang diagnostic ignored "-Wprotocol"
#import"NVContainer.h"

@implementation NVContainer

@synthesize subWidgets;
@synthesize focusManager;

-(id) initWithParent: (NVWidget *)aparent Rect: (NVRect *)arect {
#ifdef DEBUG
    [NVLogger logText: @"NVContainer::init called"];
#endif
    self = [super initWithParent: aparent Rect: arect];
    if (self) {
        subWidgets = [[NSMutableArray alloc] initWithCapacity: 2];
#ifdef DEBUG
        [NVLogger logText: [NSString stringWithFormat: @"NVContainer::init creates focusManager for class %@", NSStringFromClass([self class])]];
#endif
        focusManager = [[NVSimpleFocusManager alloc] initWithWidget: self];
    }
    return self;
}

-(void) refresh {
    int i, width = 0;
    int count = [subWidgets count];

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

// default implementation for pack
-(void) pack {
    int i, width = 0;
    int count = [[self subWidgets] count];

    for (i=0; i < count; ++i) {
        if ([[self.subWidgets objectAtIndex: i] respondsToSelector: @selector(pack)])
            [[self.subWidgets objectAtIndex: i] pack];
    }
}

@end
