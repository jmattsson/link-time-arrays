#include <getopt.h>
#include <stdlib.h>
#include "cfgopt.h"

LTA_DEFINE(const cfgopt_t, cfgopts);

static char *build_getopt_str (void)
{
  char *str = calloc (1, LTA_NUM_ITEMS(cfgopt_t, cfgopts) * 2 + 1);
  if (!str)
    return NULL;

  char *s = str;
  for (unsigned i = 0; i < LTA_NUM_ITEMS(cfgopt_t, cfgopts); ++i)
  {
    *s++ = cfgopts[i].short_opt;
    if (cfgopts[i].has_arg)
      *s++ = ':';
  }

  return str;
}


bool parse_cfgopts (int argc, char *argv[])
{
  int opt;
  char *optstr = build_getopt_str ();
  while ((opt = getopt (argc, argv, optstr)) != -1)
  {
    for (unsigned i = 0; i < LTA_NUM_ITEMS(cfgopt_t, cfgopts); ++i)
      if (opt == cfgopts[i].short_opt)
      {
        if (!cfgopts[i].handler (&cfgopts[i], optarg))
	{
	  free (optstr);
          return false;
	}
	break;
      }
  }
  free (optstr);
  return true;
}
