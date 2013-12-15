#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVKeyReceiving.h"
#import "NVContaining.h"

@protocol NVFocusManaging <NVKeyReceiving>

-(id) initWithWidget: (NVWidget<NVKeyReceiving> *)awidget;

@end
