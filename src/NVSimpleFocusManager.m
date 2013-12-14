#import"NVSimpleFocusManager.h"

@implementation NVSimpleFocusManager

@synthesize widget;
@synthesize focusedWidget;
@synthesize subWidgets;
@synthesize isFocused;

-(id) initWithWidget: (NVWidget<NVKeyReceiver> *)awidget {
    self = [super init];
    if (self) {
        widget = awidget;
        focusedWidget = nil;
        isFocused = NO;
        subWidgets = [[NSMutableArray alloc] initWithCapacity: 10];
        if ([widget respondsToSelector: @selector(subWidgets)]) {
            NVWidget<NVContainer> *container = (NVWidget<NVContainer> *) widget;
            NSMutableArray *wsw = [container subWidgets];
            int i, count = [wsw count];
            for (i=0; i < count; ++i)
                if ([[wsw objectAtIndex: i] conformsToProtocol: @protocol(NVKeyReceiver)]) {
                    id focusable = [wsw objectAtIndex: i];
                    [focusable setIsFocused: NO];
                    [subWidgets addObject: focusable];
                }
        }
    }
    return self;
}

-(void) addWidget: (NVWidget *)awidget {
    if ([awidget conformsToProtocol: @protocol(NVKeyReceiver)]) {
        NVWidget<NVKeyReceiver> *focusable = (NVWidget<NVKeyReceiver> *) widget;
        [focusable setIsFocused: NO];
        [subWidgets addObject: awidget];
    }
}

-(void) dealloc {
    [widget release];
    [subWidgets release];
    [super dealloc];
}

-(BOOL) receiveKey: (int) ch {
    if (ch == ' ') {
        [self focusNext];
        return YES;
    }
    return NO;
}

-(void) focusThis: (NVWidget<NVKeyReceiver>*) awidget {
    [awidget focus];
    focusedWidget = awidget;
}

-(void) focus {
    isFocused = YES;
    [self focusFirst];
}

-(void) deFocus {
    isFocused = NO;
}

-(void) focusFirst {
    if ([subWidgets count] != 0)
        [self focusThis: [subWidgets objectAtIndex: 0]];
}

-(void) focusNext {
    int i = 0, count = [subWidgets count];
    if (count == 0)
        return;
    if (focusedWidget != nil)
        i = [subWidgets indexOfObject: focusedWidget];
    if (i == count - 1)
        i = 0;
    else
        ++i;
    [self focusThis: [subWidgets objectAtIndex: i]];
}

-(void) focusPrev {
    int i = 0, count = [subWidgets count];
    if (count == 0)
        return;
    if (focusedWidget != nil)
        i = [subWidgets indexOfObject: focusedWidget];
    if (i == 0)
        i = count - 1;
    else
        --i;
    focusedWidget = [subWidgets objectAtIndex: i];
}

@end
