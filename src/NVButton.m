#import"NVButton.h"

@implementation NVButton

@synthesize text;

-(id) initWithParent: (NVWidget *) aparent Text: (NSString *) atext X: (int)ax Y: (int)ay {
    self = [super initWithParent: aparent Rect: [[NVRect alloc] initWithX: ax Y: ay Width: [atext length] + 4 Height: 1]];
    if (self)
        self.text = atext;
    return self;
}

-(void) dealloc {
    [self.text release];
    [super dealloc];
}

-(void) refresh {
    [self addString: [NSString stringWithFormat: @"[ %@ ]", self.text] atX: 0 Y: 0];
    [super refresh];
    [super refresh];
}

@end

