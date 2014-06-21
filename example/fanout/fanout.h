#ifndef _FANOUT_H_
#define _FANOUT_H_

#include <stdint.h>
#include "lta.h"

typedef enum { EVENT_BOOTED, EVENT_RUNNING, EVENT_EXIT } event_t;

typedef void (*listener_fn) (event_t ev, uint8_t status);

typedef struct
{
  event_t event;
  listener_fn fn;
} listener_t;

void notify_event_status (event_t event, uint8_t status);

LTA_DECLARE(listener_t,listeners);

#define EVENT_LISTENER(name,e,f) \
  LTA_ITEM(const listener_t, listeners, name) = { .event = e, .fn = f }

#endif
