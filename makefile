CC=gcc
CFLAGS=-I.
DEPS = Ag3_InfinityWord.h
OBJ = Ag3_InfinityWord.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Ag3_InfinityWord: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

