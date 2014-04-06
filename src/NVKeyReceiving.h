@protocol NVKeyReceiving

-(BOOL) receiveKey: (int)ch;
-(BOOL) isFocused;
-(void) focus;
-(void) deFocus;

@end
