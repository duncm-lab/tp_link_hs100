CC = gcc
CFLAGS = -g -c -Wall -O0 -pthread
BIN = ../bin
LIB = ../lib


OBJFILES = socket_functions \
		   command \
		   encrypt \
		   device_send \
		   device_listen \
		   main

OBJECTS := $(addprefix $(LIB)/, $(addsuffix .o, $(OBJFILES)))


hs100: $(OBJECTS)
	$(CC) $^ -g -pthread -o $(BIN)/$@
	cp commands help.txt $(BIN)


$(LIB)/main.o: main.c $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

$(LIB)/socket_functions.o: socket_function.c $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

$(LIB)/command.o: command.c $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

$(LIB)/encrypt.o: encrypt.c $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

$(LIB)/device_send.o: device_send.c $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

$(LIB)/device_listen.o: device_listen.c $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

clean:
	find $(BIN) -type f -delete
	find $(LIB) -type f -delete
