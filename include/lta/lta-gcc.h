/* Copyright (C) 2014 Johny Mattsson */

/* GNU C Compiler */

#ifndef _LTA_GCC_H_
#define _LTA_GCC_H_

/* The linker can only set up new segments on aligned boundaries, so the
 * types put into an LTA must be thusly aligned. The default value is
 * somewhat pessimistic, but should be safe everywhere.
 * Don't override this unless you know what you're doing - you won't get
 * any helpful warnings when things go wrong...
 */
#ifndef _LTA_GCC_ALIGN
# define _LTA_GCC_ALIGN 64
#endif


/* This is how we stuff something into the named segment */
#define _LTA_GCC_SEGMENT(name) \
  __attribute__((section(_LTA_STRINGIFY(name)),unused,used))
/* We use a segment name of 'seg_<name>' so that we can define a const* of
 * the appropriate type as '<name>'. If we were to use the same name for
 * the segment, the linker will overwrite our constant silenty if the
 * segment has been seen in that compilation unit. */
#define _LTA_GCC_SEGMENT_ATTRS(name) \
  _LTA_GCC_SEGMENT(_LTA_CONCAT(seg_,name))

/* The start/stop symbols for the segment are hidden and only exposed by the
 * linker on an as-needed basis.
 */
#define _LTA_GCC_STOP(name)  _LTA_CONCAT(__stop_seg_, name)
#define _LTA_GCC_START(name) _LTA_CONCAT(__start_seg_,name)
#define _LTA_GCC_START_STOP_DECLARATIONS(name) \
  extern const char _LTA_GCC_START(name); \
  extern const char _LTA_GCC_STOP(name)


#define _LTA_ALIGNED __attribute__((aligned(_LTA_GCC_ALIGN)))

#define _LTA_DEFINE(type,name) \
  _LTA_GCC_START_STOP_DECLARATIONS(name); \
  type *const name = (type *)(&_LTA_GCC_START(name))

/* We want to always have the start/stop symbols visible, so that LTA_NUM_ITEMS
 * can work as expected. */
#define _LTA_DECLARE(type,name) \
  _LTA_GCC_START_STOP_DECLARATIONS(name); \
  extern type *const name

#define _LTA_ITEM(type,name,item) \
  _LTA_STATIC_ASSERT(lta_alignmentcheck_,name,(__alignof__(type) == _LTA_GCC_ALIGN)); \
  static type _LTA_ALIGNED item _LTA_GCC_SEGMENT_ATTRS(name)

#define _LTA_NUM_ITEMS(type,name) \
  ((&_LTA_GCC_STOP(name) - &_LTA_GCC_START(name))/sizeof(type))

#endif
