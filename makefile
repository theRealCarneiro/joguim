PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

CC = gcc
CCFLAGS= -std=c99 -pedantic

TARGET = joguim
SRC = main.c state_manager.c
OBJ = ${SRC:.c=.o}

joguim:	${OBJ}
	${CC} ${OBJ} -o $@ ${CCFLAGS}

.c.o:
	${CC} -c ${SRC}

${OBJ}:	

clean:
	rm -rf *.o ${TARGET}

install:	joguim
	install -Dm755 joguim ${DESTDIR}${PREFIX}/bin/joguim

uninstall:
	rm ${DESTDIR}${PREFIX}/bin/joguim

.PHONY: clean install uninstall
