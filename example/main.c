#include "cfgopt.h"
#include <stdio.h>

int main (int argc, char *argv[])
{
  printf("cfgopts at %p\n",cfgopts);

  if (!parse_cfgopts (argc, argv))
    return 1;

  return 0;
}
