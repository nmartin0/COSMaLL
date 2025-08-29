FILES= ext_math.c
HEADERS= ext_math.h
LDLIBS= -lm

program: ${FILES} ${HEADERS}
	${CC} -o $@ $^ ${CFLAGS} ${LDLIBS}

.PHONY clean

clean:
	rm *.o program
