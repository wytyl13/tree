CC = /usr/bin/gcc
SRC = $(wildcard ./src/*.c)
OBJ = $(patsubst ./src/%.c,./obj/%.o,$(SRC))
INC_PATH = ./inc
CFLAGS = -Wall -g -O2 -Werror
EXECUTABLE = main

#$^ means all dependency in this rule. it is $(OBJ)
#$@ means the target in this rule, it is main in this rule.
main:$(OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

#$< means the first dependency in this rule.
#it is ./obj/%.o in this rule.
$(OBJ):./obj/%.o:./src/%.c
	$(CC) -c $< -o $@ $(CFLAGS) -I $(INC_PATH)

run:
	./main

clean:
	rm -rf $(OBJ) $(EXECUTABLE)
.PHONY:
	clean main run
