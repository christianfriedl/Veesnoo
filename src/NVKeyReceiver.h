@protocol NVKeyReceiver

-(BOOL) receiveKey: (int)ch;
-(void) setIsFocused: (BOOL)isFocused;
-(BOOL) isFocused;
-(void) focus;
-(void) deFocus;

@end
