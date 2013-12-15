#pragma clang diagnostic ignored "-Wprotocol"
#import"NVContainer.h"

@implementation NVContainer

@synthesize subWidgets;
@synthesize focusManager;

-(id) initWithParent: (NVWidget *)aparent Rect: (NVRect *)arect {
    self = [super initWithParent: aparent Rect: arect];
    if (self) {
        subWidgets = [[NSMutableArray alloc] initWithCapacity: 2];
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

-(void) pack {
     [self doesNotRecognizeSelector:_cmd];
}

@end
