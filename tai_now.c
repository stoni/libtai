#include <stdint.h>
#include <time.h>
#include "tai.h"


void tai_now(struct tai* t)
{
  t->x = 4611686018427387914ULL + (uint64_t) time(NULL);
}
