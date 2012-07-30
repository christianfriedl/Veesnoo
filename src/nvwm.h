
#ifndef _NVWM_H
#define _NVWM_H

#define nvExceptionID_nonfatalException          (2000)
#define nvExceptionID_fatalException             (2001)

#define THIS(type) ((type*)(this->data))

#define NV_TAB                                  (9)
#define NV_ESC                                  (27)
#define NV_ENTER                                (10)
#define NV_BACKSPACE                            (127)

typedef enum { nvInputMode_none = 0, nvInputMode_command, nvInputMode_insert, nvInputMode_replace } nvInputMode;
#endif
