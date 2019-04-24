## smallpass

smallpass is a small, simple utility for generating Diceware style passphrases on the command line. 
It uses the Electronic Frontier Foundation's long wordlist.  

### Rationale

There are lots of these Diceware generators out there, but many of them are overly complicated, have large dependencies, or are insecure. 
Smallpass is written in plain C, does not suffer from modulo bias, has no network functionality, doesn't parse any files, and has minimal 
command line flags.
This allows smallpass to be locked down tightly using pledge() on OpenBSD.

### Building
smallpass builds without requiring any dependencies on the BSDs. On Linux you will need libbsd installed 
(run "sudo apt-get install libbsd-dev" or the equivalent for your distribution). 

To build, run:
```
$ make
```

To install the binary and man page, run:
```

# make install
```

### Usage

If run with no options, smallpass will output a 7 word passphrase. This is equivalent to about 90 bits of entropy.
Each word adds about 12.9 bits.

To specify a length, use the -n option.

For example, the following will generate a 5 word passphrase:

```

smallpass -n 5
```

The minimum number of words is 1 and the max is 128.
