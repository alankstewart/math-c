CFLAGS = -O3 -Wall -ansi -pedantic

default: all

all: test

clean:
	rm -f test 

test:
	@echo 'Building target: $@'
	gcc ${CFLAGS} src/two_thousand_lines.c  -framework OpenGL -framework GLUT -o two_thousand_lines

run: test
	@echo Executing ...
	./two_thousand_lines
