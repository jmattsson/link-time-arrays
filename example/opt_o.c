#include "cfgopt.h"
#include <stdlib.h>

static const char *out;

const char *get_output_name (void)
{
  return out;
}

static bool on_opt_o (const cfgopt_t *opt, const char *arg)
{
  (void)opt;
  out = arg;
  return true;
}

CFGOPT(output) =
{
  .short_opt = 'o',
  .has_arg = true,
  .description = "Specifies output file as <arg>",
  .handler = on_opt_o,
};
