
#ifndef _NV_COLLECTIONS_H
#define _NV_COLLECTIONS_H

#include<cgenerics/cgString.h>
#include<cgenerics/cgArray.h>
#include<cgenerics/cgArrayIterator.h>

typedef struct nvActionLabel_struct nvActionLabel;
struct nvActionLabel_struct;
#include"nvWidget.h"
#include"nvActionLabel.h"

DECLARE_ARRAY(cgString)
DECLARE_ARRAY_ITERATOR(cgString)
DECLARE_ARRAY(nvWidget)
DECLARE_ARRAY_ITERATOR(nvWidget)

#endif
