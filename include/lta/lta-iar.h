/* Copyright (C) 2014 Johny Mattsson */

/* IAR Systems C Compiler */

#ifndef _LTA_IAR_H_
#define _LTA_IAR_H_

#ifndef __cplusplus
# error "Due to lack of support for using link time constant in initializers, only C++ is currently supported with IAR."
#endif

#define _LTA_ALIGNED

#define _LTA_STRINGIFY_X(x) _LTA_STRINGIFY(x)
#define _LTA_IAR_SEGMENT(name) _LTA_STRINGIFY_X(_LTA_CONCAT(seg_,name))

#define _LTA_DEFINE(type,name) \
  type *const name = (type *)__segment_begin(_LTA_IAR_SEGMENT(name))

#define _LTA_DECLARE(type,name) \
  _LTA_PRAGMA(segment=_LTA_IAR_SEGMENT(name)); \
  extern type *const name

#define _LTA_ITEM(type,name,item_name) \
  __root type item_name@_LTA_IAR_SEGMENT(name)

#define _LTA_NUM_ITEMS(type,name) \
  (((char *)__segment_begin(_LTA_IAR_SEGMENT(name)) \
    - (char *)__segment_end(_LTA_IAR_SEGMENT(name))) \
   / sizeof(type))

#endif
