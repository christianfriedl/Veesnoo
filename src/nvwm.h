#ifndef _NVWM_H
#define _NVWM_H

#define nvExceptionID_nonfatalException          (2000)
#define nvExceptionID_fatalException             (2001)

#define THIS(type) ((type*)(this->data))

typedef enum { nvInputMode_command, nvInputMode_insert, nvInputMode_replace } nvInputMode;
#endif
