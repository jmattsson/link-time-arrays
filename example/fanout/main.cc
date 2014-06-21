#include <stdio.h>
#include "fanout.h"

extern "C" size_t __write (int fd, const unsigned char *buf, size_t n)
{
  // TODO: dump this out on a UART..
  (void)fd;
  (void)buf;
  return n;
}

int main (void)
{
  notify_event_status (EVENT_BOOTED, 0);
  for (unsigned i = 0; i < 5; ++i)
    notify_event_status (EVENT_RUNNING, i);
  notify_event_status (EVENT_EXIT, 0);
  return 0;
}

static void do_msg (event_t ev, uint8_t status)
{
  if (ev == EVENT_BOOTED)
    printf ("IAR fanout example\n");
  else if (ev == EVENT_EXIT)
    printf ("End of example\n");
  else
    printf ("Unexpected notification ev %u status %u\n", ev, status);
}

EVENT_LISTENER(bootmsg, EVENT_BOOTED, do_msg);
EVENT_LISTENER(exitmsg, EVENT_EXIT, do_msg);
