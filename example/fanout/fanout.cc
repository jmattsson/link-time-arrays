#include "fanout.h"

LTA_DEFINE(listener_t,listeners);

void notify_event_status (event_t event, uint8_t status)
{
  for (unsigned i = 0; i < LTA_NUM_ITEMS(listener_t,listeners); ++i)
    if (listeners[i].event == event)
      listeners[i].fn (event, status);
}
