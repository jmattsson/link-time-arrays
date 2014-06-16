/* Copyright (C) 2014 Johny Mattsson */

#ifndef _LTA_H_
#define _LTA_H_

/* Internal utility macros */
#define _LTA_STRINGIFY(str) #str
#define _LTA_CONCAT(a,b) a##b
#define _LTA_PRAGMA(what) _Pragma(#what)
#define _LTA_STATIC_ASSERT(tag,name,expr) \
  typedef char _LTA_CONCAT(tag,name)[(expr) ? 0: -1]


/* Compiler specific macro definitions */
#if defined(__GNUC__)
# include "lta/lta-gcc.h"
#elif define(__clang__)
# include "lta/lta-clang.h"
#elif defined(__IAR_SYSTEMS_ICC__)
# include "lta/lta-iar.h"
#else
# error "Compiler not recognized - Link-Time Arrays not available!"
#endif

/* Provided interface */

#define LTA_ALIGNED _LTA_ALIGNED

#define LTA_DECLARE(type,name) \
  _LTA_DECLARE(type,name)

#define LTA_DEFINE(type,name) \
  _LTA_DEFINE(type,name)

#define LTA_ITEM(type,name,item_name) \
  _LTA_ITEM(type,name,item_name)

#define LTA_NUM_ITEMS(type,name) \
  _LTA_NUM_ITEMS(type,name)

#endif
