#import"NV.h"
@class NVWidget;
@interface NVDumper: NSObject { }

+(void) dumpRects: (NVWidget*) w Text: (NSString*) text StartLine: (int) startLine Interrupt: (BOOL) interrupt;
+(void) dumpRect: (NVRect*) rect Text: text Line: (int) line Interrupt: (BOOL) interrupt;
+(void) dumpText: text Line: (int) line Interrupt: (BOOL) interrupt;

@end

