#import"NVTextfield.h"

#pragma clang diagnostic ignored "-Wprotocol"

@implementation NVTextfield

@synthesize text;
@synthesize editState;
@synthesize focusManager;

-(id) initWithParent: (NVWidget *) aparent Text: (NSString *) atext X: (int)ax Y: (int)ay Width: (int)awidth {
    self = [super initWithParent: aparent Rect: [[NVRect alloc] initWithX: ax Y: ay Width: [atext length] + 4 Height: 1]];
    if (self) {
        text = [[NSMutableString alloc] initWithString: atext];
        editState = NVEditState_none;
        focusManager = [[NVSimpleFocusManager alloc] initWithWidget: self];
    }
    return self;
}

-(id) initWithParent: (NVWidget *) aparent X: (int)ax Y: (int)ay Width: (int)awidth {
    return [self initWithParent: aparent Text: @"" X: ax Y: ay Width: awidth];
}

-(void) refresh {
    [self addString: self.text atX: 0 Y: 0];
    [super refresh];
}

-(BOOL) receiveKey: (int)ch {
    if (editState == NVEditState_none) {
    } else if (editState == NVEditState_insert) {
    } else if (editState == NVEditState_replace) {
    } else
        @throw [NSException exceptionWithName: @"NVTextfieldException" reason: @"unknown edit state" userInfo: nil];
    return false;
}

- (void)forwardInvocation:(NSInvocation *)anInvocation {
    if ([focusManager respondsToSelector: [anInvocation selector]])
        [anInvocation invokeWithTarget:focusManager];
    else
        [super forwardInvocation:anInvocation];
}

@end

