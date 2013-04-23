#CFLAGS -DSYSV
CFLAGS -DBSD

tnc: tnc.c
	cc tnc.c -o tnc $(CFLAGS) -lm
