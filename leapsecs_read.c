#ifdef WIN32
#include <io.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
extern int errno;
#endif
#include "tai.h"
#include "leapsecs.h"

struct tai *leapsecs = 0;
int leapsecs_num = 0;

int leapsecs_read()
{
#ifdef WIN32
	int fd;
	struct tai *t;
	struct _stat st;
	int n;
	int i;
	struct tai u;

	fd = _open("leapsecs.dat", _O_RDONLY);

	if (fd == -1) {
		if (leapsecs) free(leapsecs);
		leapsecs = 0;
		leapsecs_num = 0;
		return 0;
	}

	if (_fstat(fd,&st) == -1) { close(fd); return -1; }

	t = (struct tai *) malloc(st.st_size);
	if (!t) { close(fd); return -1; }

	n = read(fd,(char *) t,st.st_size);
	close(fd);
	if (n != st.st_size) { free(t); return -1; }

	n /= sizeof(struct tai);

	for (i = 0;i < n;++i) {
		tai_unpack((char *) &t[i],&u);
		t[i] = u;
	}

	if (leapsecs) free(leapsecs);

	leapsecs = t;
	leapsecs_num = n;
#else
  int fd;
  struct stat st;
  struct tai *t;
  int n;
  int i;
  struct tai u;

  fd = open("leapsecs.dat",O_RDONLY | O_NDELAY);
  if (fd == -1) {
    if (errno != ENOENT) return -1;
    if (leapsecs) free(leapsecs);
    leapsecs = 0;
    leapsecs_num = 0;
    return 0;
  }

  if (fstat(fd,&st) == -1) { close(fd); return -1; }

  t = (struct tai *) malloc(st.st_size);
  if (!t) { close(fd); return -1; }

  n = read(fd,(char *) t,st.st_size);
  close(fd);
  if (n != st.st_size) { free(t); return -1; }

  n /= sizeof(struct tai);

  for (i = 0;i < n;++i) {
    tai_unpack((char *) &t[i],&u);
    t[i] = u;
  }

  if (leapsecs) free(leapsecs);

  leapsecs = t;
  leapsecs_num = n;
#endif
  return(0);
}