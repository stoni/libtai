#ifndef LEAPSECS_H
#define LEAPSECS_H

#include "tai.h"

extern int leapsecs_init();
extern int leapsecs_read();

extern void leapsecs_add(struct tai *t, int hit);
extern int leapsecs_sub(struct tai *t);

#endif
