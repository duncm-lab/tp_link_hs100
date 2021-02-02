CC = gcc
CFLAGS = -g -c -Wall -O0 -pthread
BIN = ../bin
LIB = ../lib

OBJECTS = $(LIB)/main.o \
		  $(LIB)/socket_functions.o \
		  $(LIB)/command.o \
		  $(LIB)/encrypt.o \
		  $(LIB)/device_send.o \
		  $(LIB)/device_listen.o


hs100: $(OBJECTS)
	$(CC) $^ -g -pthread -o $(BIN)/$@

server: $(LIB)/server.o $(LIB)/socket_functions.o
	$(CC) $^ -g -o $(BIN)/$@

$(LIB)/main.o: main.c
	$(CC) $(CFLAGS) $< -o $@

$(LIB)/socket_functions.o: socket_function.c
	$(CC) $(CFLAGS) $< -o $@

$(LIB)/server.o: server.c
	$(CC) $(CFLAGS) $< -o $@

$(LIB)/command.o: command.c
	$(CC) $(CFLAGS) $< -o $@

$(LIB)/encrypt.o: encrypt.c
	$(CC) $(CFLAGS) $< -o $@

$(LIB)/device_send.o: device_send.c
	$(CC) $(CFLAGS) $< -o $@

$(LIB)/device_listen.o: device_listen.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	find $(BIN) -type f -delete
	find $(LIB) -type f -delete
