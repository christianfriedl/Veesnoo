#import"Foundation/Foundation.h"
#import "NVWidget.h"
#import "NVKeyReceiver.h"
#import "NVContainer.h"

@protocol NVFocusManager <NVKeyReceiver>

-(id) initWithWidget: (NVWidget<NVKeyReceiver> *)awidget;

@end
