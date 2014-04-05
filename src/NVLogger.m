#include <stdlib.h>
#import"NVLogger.h"
@implementation NVLogger

+(void) logText: (NSString*) text {
    FILE *f = fopen("nv.log", "a");
    if (f) {
        NSDateFormatter *formatter;
        NSString *dateString;

        formatter = [[NSDateFormatter alloc] init];
        [formatter setDateFormat:@"dd-MM-yyyy HH:mm"];

        dateString = [formatter stringFromDate:[NSDate date]];

        NSString *text2 = [NSString stringWithFormat: @"%@: %@\n", dateString, text];
        fwrite([text2 UTF8String], [text2 lengthOfBytesUsingEncoding:NSUTF8StringEncoding], 1, f);

        fclose(f);
    } else {
        endwin();
        printf("unable to write to log file.");
        exit(1);
    }
}

@end
