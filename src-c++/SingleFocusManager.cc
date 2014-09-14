#import"NVSingleFocusManager.h"

@implementation NVSingleFocusManager

@synthesize widget;
@synthesize isFocused;
@synthesize app;

-(id) initWithWidget: (NVWidget<NVKeyReceiving> *)awidget {
#ifdef DEBUG
    [NVLogger logText: [NSString stringWithFormat: @"NVSingleFocusManager init: widget class=%@", NSStringFromClass([awidget class])]];
#endif
    self = [super init];
    if (self) {
        app = [NVApp sharedInstance];
        widget = awidget;
        isFocused = NO;
    }
    return self;
}

-(BOOL) receiveKey: (int) ch {
#ifdef DEBUG
    [NVLogger logText: [NSString stringWithFormat: @"NVSingleFocusManager receiveKey: widget class=%@ @ %ld, key='%c' (%i)", NSStringFromClass([self.widget class]), self.widget, ch, ch]];
#endif
    return NO;
}

-(void) focus {
#ifdef DEBUG
    [NVLogger logText: [NSString stringWithFormat: @"NVSingleFocusManager::focus for widget %@ @ %ld", NSStringFromClass([self.widget class]), self.widget]];
#endif
    isFocused = YES;
    [app setFocusedWidget: widget];
}

-(void) deFocus {
    [app setFocusedWidget: nil];
    isFocused = NO;
}

@end
