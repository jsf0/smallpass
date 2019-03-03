CC = cc

DESTDIR = /usr
PREFIX = /local

CFLAGS = -Wall -O3 -fstack-protector-strong -fPIC -fPIE -D_FORTIFY_SOURCE=2

SRC = main.c

smallpass: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o smallpass

clean:
	rm smallpass
.PHONY: clean

install: smallpass smallpass.1
	install -m 755 -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 smallpass $(DESTDIR)$(PREFIX)/bin
	install -m 755 -d $(DESTDIR)$(PREFIX)/man/man1
	install -m 644 smallpass.1 $(DESTDIR)$(PREFIX)/man/man1
.PHONY: install
