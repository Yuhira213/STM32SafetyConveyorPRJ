CC = gcc
CFLAGS = -Wall -std=c99 -g
LDFLAGS = -lcmocka

SRC = relay_buzzer.c relay_buzzer_test.c
OBJ = $(SRC:.c=.o)
EXEC = relay_buzzer_test.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(EXEC)