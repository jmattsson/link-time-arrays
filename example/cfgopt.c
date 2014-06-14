#include <getopt.h>
#include "cfgopt.h"

LTA_DEFINE(const cfgopt_t, cfgopts);

bool parse_cfgopts (int argc, char *argv[])
{
  int opt;
  while ((opt = getopt (argc, argv, "ho:")) != -1) // FIXME: make up optstr
  {
    for (unsigned i = 0; i < LTA_NUM_ITEMS(cfgopt_t, cfgopts); ++i)
      if (opt == cfgopts[i].short_opt)
      {
        if (!cfgopts[i].handler (&cfgopts[i], optarg))
          return false;
	break;
      }
  }
  return true;
}
