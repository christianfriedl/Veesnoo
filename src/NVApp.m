#import "NVApp.h"
#import"NVKeyReceiving.h"
#import"NVWidget.h"

@interface NVApp(Private)

-(BOOL) sendKey: (int) ch toWidget: (NVWidget<NVKeyReceiving>*) aWidget;

@end

@implementation NVApp

@synthesize focusedWidget;
@synthesize mainWindow;

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

-(void) focus {
    if (! self.mainWindow)
        @throw [NSException exceptionWithName: @"NoMainWindowException" reason: @"no main window set." userInfo: nil];
    [self.mainWindow focus];
}

-(BOOL) sendKey: (int) ch toWidget: (NVWidget<NVKeyReceiving>*) aWidget {
    BOOL accepted = false;
    do {
#ifdef DEBUG
        [NVLogger logText: [NSString stringWithFormat: @"NVApp::sendKey: sending key '%c' to %@ @ %ld", ch, NSStringFromClass([self.focusedWidget class]), self.focusedWidget]];
#endif
        accepted = [aWidget receiveKey: ch];
#ifdef DEBUG
        [NVLogger logText: [NSString stringWithFormat: @"NVApp::sendKey: receive key accepted=%i", accepted]];
#endif
        if (!accepted) {
            NVWidget *pWidget = [aWidget parent];
            if ([[pWidget class] conformsToProtocol: @protocol(NVKeyReceiving)])
                aWidget = (NVWidget<NVKeyReceiving>*)pWidget;
            else
                aWidget = nil;
        }
#ifdef DEBUG
        [NVLogger logText: [NSString stringWithFormat: @"NVApp::sendKey: aWidget=%ld, accepted=%i", aWidget, accepted]];
#endif
    } while (aWidget && !accepted);
    return accepted;
}

-(void) receiveKey: (int) ch {
    if (!self.focusedWidget)
        @throw [NSException exceptionWithName: @"NoFocusedWidgetException" reason: @"no focused widget set." userInfo: nil];
    BOOL accepted = [self sendKey: ch toWidget: self.focusedWidget];
    /*
    if (!accepted) {
            @throw [NSException exceptionWithName: @"KeyNotAcceptedException" reason: @"no focused widget found to accept our key." userInfo: nil];
    }
    */
    // currently, if the key is not accepted, we simply throw it away...
}

-(void) run {
    while (1) {
        [mainWindow refresh];
        int ch = getch();
        [self receiveKey: ch];
    }
}

@end
