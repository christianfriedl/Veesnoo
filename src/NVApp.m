#import "NVApp.h"
#import"NVKeyReceiving.h"
#import"NVWidget.h"

@implementation NVApp

@synthesize focusedWidget;

static NVApp* instance = nil;

+(NVApp *)sharedInstance {
    if (instance == nil)
        instance = [[NVApp alloc] init];
    return instance;
}


-(id)init {
    self = [super init];
    if (self) {
        self.focusedWidget = nil;
    }
    return self;
}

-(void) receiveKey: (int) ch {
    if (!self.focusedWidget)
        @throw [NSException exceptionWithName: @"NoFocusedWidgetException" reason: @"no focused widget set." userInfo: nil];
#ifdef DEBUG
    [NVLogger logText: [NSString stringWithFormat: @"NVApp: sending key '%c' to %@ @ %ld", ch, NSStringFromClass([self.focusedWidget class]), self.focusedWidget]];
#endif
    [self.focusedWidget receiveKey: ch];
}

@end