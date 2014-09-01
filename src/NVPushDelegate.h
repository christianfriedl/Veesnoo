#import "NVWidget.h"
#import "NVKeyReceiving.h"

@protocol NVPushDelegate

-(BOOL) wasPushed: (NVWidget<NVKeyReceiving> *) target;

@end
