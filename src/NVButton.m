#import"NVButton.h"

@implementation NVButton

@synthesize label;

-(NVButton*) initWithText: (NSString*) text {
    self = [super init];
    if (self) {
        self.label = [[NVLabel alloc] initWithX: 2 Y: 0 Text: text];
        self.width = [text length] + 4;
        self.height = 1;
    }
    return self;
}

-(void) refresh {
    [self.cw addCh: '[' atX: 0 Y: 0];
    [self.cw addCh: '[' atX: 0 Y: self.width - 1];
    [self.label refresh];
}

