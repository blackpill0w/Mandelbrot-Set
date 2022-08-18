CC       =  gcc
CC_FLAGS =  -std=c11 -Wall -Wextra -Wsign-conversion -g -Os
LD_FLAGS = -lm

SRC       =  src

main: main.o
	${CC} ${CC_FLAGS} ${LD_FLAGS} ${SRC}/main.c -o $@

main.o: ${SRC}/main.c
	${CC} ${CC_FLAGS} ${LD_FLAGS} ${SRC}/main.c -c

clean:
	rm -rf main*
