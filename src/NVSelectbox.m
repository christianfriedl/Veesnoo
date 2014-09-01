#include <wctype.h>
#import"NVSelectbox.h"
#import"NVColorAttribute.h"

#pragma clang diagnostic ignored "-Wprotocol"

@interface NVSelectbox(Private)

@end

@implementation NVSelectbox

@synthesize focusManager;
@synthesize popupMenu;
@synthesize options;


-(id) initWithX: (int)ax Y: (int)ay Width: (int)awidth {
    self = [super initWithX: ax Y: ay Width: awidth Height: 1];
    if (self) {
        self.popupMenu = [[NVPopupMenu alloc] initWithX: ax Y: ay + 1];
        self.options = [[NSDictionary alloc] init];
        [[[NVApp sharedInstance] mainWindow] addWidget: self.popupMenu];
    }
    return self;
}

-(void) addOption: (id) avalue Text: (NSString*) atext {
    NVMenuItem *mi = [[NVMenuItem alloc] initWithText: atext X: 0 Y: 0];
    [mi setDelegate: self];
    [self.popupMenu addMenuItem: mi];
}

-(void) refresh {
    [self.popupMenu pack];
    [self.popupMenu focus];
    [super refresh];
}

-(BOOL) receiveKey: (int)ch {
#ifdef DEBUG
    [NVLogger logText: [NSString stringWithFormat: @"NVSelectbox receiveKey: ch='%c' (%i) ... ", ch, ch]];
#endif
    return [self.popupMenu receiveKey: ch];
    return NO;
}

- (void)forwardInvocation:(NSInvocation *)anInvocation {
    if ([focusManager respondsToSelector: [anInvocation selector]])
        [anInvocation invokeWithTarget:focusManager];
    else
        [super forwardInvocation:anInvocation];
}

-(BOOL) wasPushed: (NVWidget<NVKeyReceiving> *) target {
#ifdef DEBUG
    [NVLogger logText: [NSString stringWithFormat: @"NVSelectbox wasPushed: target='%@'", target]];
#endif
    return YES;
}

@end


