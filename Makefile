CFLAGS = -O3 -Wall -Wno-deprecated-declarations -std=c99 -pedantic

default: all

all: test

clean:
	rm -f test 

test:
	@echo 'Building target: $@'
	gcc ${CFLAGS} src/two_thousand_lines.c -lm -framework OpenGL -framework GLUT -o two_thousand_lines

run: test
	@echo Executing ...
	./two_thousand_lines
