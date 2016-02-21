CFLAGS = -O3 -Wall -Wno-deprecated-declarations -std=c99 -pedantic

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	LIBS = -lglut -lGLU -lGL -lm
endif
ifeq ($(UNAME), Darwin)
	LIBS = -framework OpenGL -framework GLUT -lm
endif

default: run

all: math

clean:
	rm -f *.o nurbs solar one_thousand_lines two_thousand_lines four_thousand_lines

math: clean
	@echo 'Building target: $@'

	gcc src/fibonacci.c ${CFLAGS} -o fibonacci

	gcc -c src/lines/line_segments.c ${CFLAGS} -o line_segments.o 
	gcc -c src/lines/main.c ${CFLAGS} -o main.o 
	gcc line_segments.o main.o src/lines/one_thousand_lines.c  ${CFLAGS} ${LIBS} -o one_thousand_lines 
	gcc line_segments.o main.o src/lines/two_thousand_lines.c  ${CFLAGS} ${LIBS} -o two_thousand_lines 
	gcc line_segments.o main.o src/lines/four_thousand_lines.c ${CFLAGS} ${LIBS} -o four_thousand_lines 
	
	gcc src/nurbs/nurbs.c ${CFLAGS} ${LIBS} -o nurbs
	
	gcc src/light/solar.c ${CFLAGS} ${LIBS} -o solar

run: math
	@echo Executing ...
	#./one_thousand_lines
	#./two_thousand_lines
	#./four_thousand_lines
	#./nurbs
	#./solar
	./fibonacci
	
