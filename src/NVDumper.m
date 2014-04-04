#import"NVDumper.h"
@implementation NVDumper
+(void) dumpRects: (NVWidget*) w Text: (NSString*) text StartLine: (int) startLine Interrupt: (BOOL) interrupt {
    [NVDumper dumpRect: [w rect] Text: [text stringByAppendingString: [NSString stringWithFormat: @" rect"]] Line: startLine Interrupt: NO];
    [NVDumper dumpRect: [w contentRect] Text: [text stringByAppendingString: [NSString stringWithFormat: @" contentRect"]] Line: startLine+1 Interrupt: NO];
    [NVDumper dumpRect: [w absRect] Text: [text stringByAppendingString: [NSString stringWithFormat: @" absRect"]] Line: startLine+2 Interrupt: NO];
    [NVDumper dumpRect: [w absContRect] Text: [text stringByAppendingString: [NSString stringWithFormat: @" absContRect"]] Line: startLine+3 Interrupt: NO];
    if (interrupt)
        getch();
}

+(void) dumpRect: (NVRect*) rect Text: text Line: (int) line Interrupt: (BOOL) interrupt {
    const char *s = [[text stringByAppendingString: [NSString stringWithFormat: @" x=%i, y=%i, w=%i, h=%i", [rect x], [rect y], [rect width], [rect height]]] UTF8String];
    mvaddstr(line, 1, s);
    if (interrupt)
        getch();
}

+(void) dumpText: text Line: (int) line Interrupt: (BOOL) interrupt {
    const char *s = [text UTF8String];
    mvaddstr(line, 1, s);
    if (interrupt)
        getch();
}
@end
