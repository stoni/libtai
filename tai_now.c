#include <time.h>
#include "tai.h"

void tai_now(t)
struct tai *t;
{
  t->x = 4611686018427387914ULL + (uint64) time((long *) 0);
}
