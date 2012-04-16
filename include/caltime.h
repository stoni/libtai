#ifndef CALTIME_H
#define CALTIME_H

#include "caldate.h"

struct caltime {
  struct caldate date;
  int hour;
  int minute;
  int second;
  long offset;
} ;

extern void caltime_tai();
extern void caltime_utc();

extern unsigned int caltime_fmt();
extern unsigned int caltime_scan();

#endif
