
#ifndef _NVWM_H
#define _NVWM_H

#include<limits.h>
#include<cgenerics/cgArray.h>
#include<cgenerics/cgArrayIterator.h>


#define nvExceptionID_nonfatalException  ( 2000)
#define nvExceptionID_fatalException     ( 2001)
#define nvExceptionID_menuNoItemSelected ( 2002)

#define THIS(TYPE)                       ((TYPE*) ( this->data))

#define NV_TAB                           ( 9)
#define NV_ESC                           ( 27)
#define NV_ENTER                         ( 10)
#define NV_BACKSPACE                     ( 127)
#define NV_MENU_NO_SELECTED_ITEM         ( INT_MAX)

typedef enum { nvInputMode_none = 0, nvInputMode_command, nvInputMode_insert, nvInputMode_replace } nvInputMode;
#endif
