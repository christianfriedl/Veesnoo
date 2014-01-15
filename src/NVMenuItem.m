#import "NVMenuItem.h"
#pragma clang diagnostic ignored "-Wprotocol"

@implementation NVMenuItem

@synthesize text;
@synthesize focusManager;

-(id) initWithParent: (NVWidget *)aparent Text: (NSString *)atext X: (int)ax Y:(int)ay {
    self = [super initWithParent: aparent Rect: [[NVRect alloc] initWithX: ax Y: ay Width: [atext length] Height: 1]];
    if (self) {
        text = atext;
        focusManager = [[NVSimpleFocusManager alloc] initWithWidget: self];
    }
    return self;
}
-(id) initWithText: (NSString *)atext X: (int)ax Y:(int)ay {
    self = [super initWithRect: [[NVRect alloc] initWithX: ax Y: ay Width: [atext length] Height: 1]];
    if (self) {
        text = atext;
    }
    return self;
}
-(void) refresh {
    if ([focusManager isFocused])
        [[self cw] attrOn: A_REVERSE];
    [self addString: text atX: 0 Y: 0];
    if ([focusManager isFocused])
        [[self cw] attrOff: A_REVERSE];
    [super refresh];
}

-(void) forwardInvocation: (NSInvocation *)anInvocation {
    if ([focusManager respondsToSelector: [anInvocation selector]])
        [anInvocation invokeWithTarget:focusManager];
    else
        [super forwardInvocation:anInvocation];
}


@end
