#import"NVSimpleFocusManager.h"

@implementation NVSimpleFocusManager

@synthesize widget;
@synthesize focusedWidget;
@synthesize subWidgets;
@synthesize isFocused;
@synthesize app;

-(id) initWithWidget: (NVWidget<NVKeyReceiving> *)awidget {
#ifdef DEBUG
    [NVLogger logText: [NSString stringWithFormat: @"NVSimpleFocusManager init: widget class=%@", NSStringFromClass([awidget class])]];
#endif
    self = [super init];
    if (self) {
        app = [NVApp sharedInstance];
        widget = awidget;
        focusedWidget = nil;
        isFocused = NO;
        subWidgets = [[NSMutableArray alloc] initWithCapacity: 10];
        if ([widget respondsToSelector: @selector(subWidgets)]) {
            NVWidget<NVContaining> *container = (NVWidget<NVContaining> *) widget;
            NSMutableArray *wsw = [container subWidgets];
            int i, count = [wsw count];
            for (i=0; i < count; ++i)
                if ([[wsw objectAtIndex: i] conformsToProtocol: @protocol(NVKeyReceiving)]) {
                    id focusable = [wsw objectAtIndex: i];
                    [focusable setIsFocused: NO];
                    [subWidgets addObject: focusable];
                }
        }
    }
    return self;
}

-(void) addWidget: (NVWidget *)awidget {
#ifdef DEBUG
    [NVLogger logText: [NSString stringWithFormat: @"NVSimpleFocusManager for %@ add widget of class: %@", NSStringFromClass([self.widget class]), NSStringFromClass([awidget class])]];
#endif
    if ([awidget conformsToProtocol: @protocol(NVKeyReceiving)]) {
#ifdef DEBUG
        [NVLogger logText: [NSString stringWithFormat: @"...is NVKeyReceiving!"]];
#endif
        NVWidget<NVKeyReceiving> *focusable = (NVWidget<NVKeyReceiving> *) awidget;
        [focusable setIsFocused: NO];
        [subWidgets addObject: focusable];
    }
}

-(BOOL) receiveKey: (int) ch {
#ifdef DEBUG
    [NVLogger logText: [NSString stringWithFormat: @"NVSimpleFocusManager receiveKey: widget class=%@ @ %ld, key='%c' (%i)", NSStringFromClass([self.widget class]), self.widget, ch, ch]];
#endif
    if (ch == ' ') {
        [self focusNext];
        return YES;
    }
    return NO;
}

-(void) focusThis: (NVWidget<NVKeyReceiving>*) awidget {
    int i = 0, count = [subWidgets count];
    for (i=0; i < count; ++i) {
        NVWidget<NVKeyReceiving>* focusable = [subWidgets objectAtIndex: i];
        if (![focusable isEqual: awidget] && [focusable isFocused])
            [focusable deFocus];
    }
    [awidget focus];
    focusedWidget = awidget;
}

-(void) focus {
#ifdef DEBUG
    [NVLogger logText: [NSString stringWithFormat: @"NVSimpleFocusManager::focus for widget %@ @ %ld", NSStringFromClass([self.widget class]), self.widget]];
#endif
    isFocused = YES;
    [app setFocusedWidget: widget];
    [self focusFirst];
}

-(void) deFocus {
    [app setFocusedWidget: nil];
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
    [self focusThis: [subWidgets objectAtIndex: i]];
}

@end
