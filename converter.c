#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tai.h"
#include "caltime.h"

/**
 *
 *
 */
static void usage()
{
	struct tai t;
	tai_now(&t);
	printf("converter taiToIso|isoToTai tai|iso\n");
	printf("Current TAI: %lld\n", t.x);
}
/**
 *
 *
 */
int main(int argc, char** argv)
{
	const char* cmd;
	uint64_t tai;
	const char* iso;

	if (argc < 3) {
		usage();
		return(1);
	}

	cmd = argv[1];

	if (strcmp(cmd, "taiToIso") == 0) {
		struct caltime ct;
		struct tai t;
		char buf[128];
		int len;
		tai = _strtoui64(argv[2], NULL, 10);
		t.x = tai;
		caltime_utc(&ct, &t, 0, 0);
		len = caltime_fmt(buf, &ct);
		buf[len] = '\0';
		printf("ISO: %s\n", buf);
	}
	else if (strcmp(cmd, "isoToTai") == 0) {
		iso = argv[2];
	}
	else {
		usage();
		return(1);
	}



	return(0);
}