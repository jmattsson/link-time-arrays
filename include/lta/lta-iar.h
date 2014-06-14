/* Copyright (C) 2014 Johny Mattsson */

/* IAR Systems C Compiler */

#ifndef _LTA_IAR_H_
#define _LTA_IAR_H_

#define _LTA_ALIGNED

#define _LTA_DEFINE(type,name) \
  type *const name = __segment_begin(_LTA_STRINGIFY(name))

/* The IAR compiler doesn't recognize a segment name within a compilation
 * unit unless it's seen the segment used first, hence the placeholder here. */
#define _LTA_DECLARE(type,name) \
  extern void *_lta_placeholder@_LTA_STRINGIFY(name); \
  extern type *const name

#define _LTA_ITEM(type,name,item_name) \
  __root type item_name@_LTA_STRINGIFY(name)

#define _LTA_NUM_ITEMS(type,name) \
  ((__segment_begin(_LTA_STRINGIFY(name)) \
    - __segment_end(_LTA_STRINGIFY(name))) \
   / sizeof(type))

#endif
