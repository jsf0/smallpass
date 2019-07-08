/*
 * Copyright (c) 2019 Joseph Fierro <joseph.fierro@runbox.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <err.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef __linux__
	#include <bsd/bsd.h>
#endif /* Linux */

#include "eff_long.h"

#define	LIST_LENGTH	7776
#define	MIN	1
#define	MAX	128

static void usage(void);

int
main(int argc, char **argv)
{
	#ifdef __OpenBSD__
	if ((unveil("/", "r")) == -1)
		err(1, "unveil");
        if ((pledge("stdio", NULL)) == -1)
                err(1, "pledge");
        #endif /* __OpenBSD__ */

	uint32_t ch, length, n, i = 0;
	const char *errstr;

	while ((ch = getopt(argc, argv, "hn:")) != -1) {
		switch (ch) {
		case 'h':
		    usage();
		    break;
		case 'n':
		    length = strtonum(optarg, MIN, MAX, &errstr);
		    if (errstr != NULL)
			errx(1, "Error getting passphrase length: %s", errstr);
		    break;
		default:
		    usage();
		    break;
		}
	}

	if (argc < 2)
		length = 7;

	argc -= optind;
	argv += optind;

	if (argc != 0)
		usage();

        while (i < length) {
                n = arc4random_uniform(LIST_LENGTH);
                printf("%s ", eff_long[n]);
                i++;
        }
 
        printf("\n");

	return(0);
}

void
usage(void)
{
	errx(1, "\nusage:\n\tsmallpass [-n length]");
}
