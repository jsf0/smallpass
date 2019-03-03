## smallpass

smallpass is a small, simple utility for generating Diceware style passphrases on the command line. 
It uses the Electronic Frontier Foundation's long wordlist.  

### Building
smallpass builds with no dependencies on the BSDs. I haven't tried building on Linux, but you will probably want libbsd installed 
if you want to port it. 

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
