#include "cfgopt.h"
#include <stdio.h>

#define MY_VER "1.0"

int main (int argc, char *argv[])
{
  if (!parse_cfgopts (argc, argv))
    return 1;

  return 0;
}

static bool on_ver (const cfgopt_t *opt, const char *arg)
{
  (void)opt;
  (void)arg;
  fprintf (stderr, "lta example v%s\n", MY_VER);
  return false;
}

CFGOPT(ver) =
{
  .short_opt = 'V',
  .has_arg = false,
  .description = "Shows version information",
  .handler = on_ver,
};
