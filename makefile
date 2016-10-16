
CC     =     gcc
CFLAGS = -Wall
CFLAGS = -g
OBJS   = permutations.o randoms.o sampleexam1.o
EXEC   = permutations randoms sampleexam1

permutations:
	$(CC)	$(CFLAGS) -o permutations permutations.c

randoms:
	$(CC) 	$(CFLAGS) -o randoms randoms.c

sampleexam1:
	$(CC)	$(CFLAGS) -o sampleexam1 sampleexam1.c

clean :
	rm -f $(OBJS) $(EXEC)
