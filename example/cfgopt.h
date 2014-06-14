/* Copyright (C) 2014 Johny Mattsson */

#ifndef _CFGOPT_H_
#define _CFGOPT_H_

#include "lta.h"
#include <stdbool.h>

bool parse_cfgopts (int argc, char *argv[]);


struct cfgopt;

typedef bool (*cfgopt_handler)(const struct cfgopt *opt, const char *arg);

typedef struct cfgopt
{
  char short_opt;
  bool has_arg;
  const char *description;
  cfgopt_handler handler;
} LTA_ALIGNED cfgopt_t;


LTA_DECLARE(const cfgopt_t, cfgopts);

#define CFGOPT(optname)       LTA_ITEM(const cfgopt_t, cfgopts, optname)

#endif
