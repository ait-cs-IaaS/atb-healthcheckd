CC=gcc
CFLAGS=


%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

healthcheckd: main.o
	$(CC) -o healthcheckd main.o $(CFLAGS)

clean: main.o
	rm main.o
