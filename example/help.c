#include "cfgopt.h"
#include <stdlib.h>
#include <stdio.h>

static bool on_help (const cfgopt_t *opt, const char *arg)
{
  (void)arg;
  fprintf (stderr, "Options:\n");
  for (unsigned i = 0; i < LTA_NUM_ITEMS(cfgopt_t, cfgopts); ++i)
  {
    opt = &cfgopts[i];
    fprintf(stderr, " -%c %s    %s\n",
      opt->short_opt,
      opt->has_arg ? "<arg>" : "     ",
      opt->description);
  }
  exit (1);
}

CFGOPT(help) =
{
  .short_opt = 'h',
  .has_arg = false,
  .description = "Shows this help",
  .handler = on_help
};
