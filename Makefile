CFLAGS = -O3 -Wall -Wno-deprecated-declarations -std=c90 -pedantic

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	LIBS = -lglut -lGLU -lGL -lm
endif
ifeq ($(UNAME), Darwin)
	LIBS = -framework OpenGL -framework GLUT -lm
endif

default: all

all: math

clean:
	rm -f *.o one_thousand_lines two_thousand_lines four_thousand_lines

math:
	@echo 'Building target: $@'
	gcc -c src/line_segments.c ${CFLAGS} -o line_segments.o 
	gcc -c src/main.c ${CFLAGS} -o main.o 
	gcc line_segments.o main.o src/one_thousand_lines.c  ${CFLAGS} ${LIBS} -o one_thousand_lines 
	gcc line_segments.o main.o src/two_thousand_lines.c  ${CFLAGS} ${LIBS} -o two_thousand_lines 
	gcc line_segments.o main.o src/four_thousand_lines.c ${CFLAGS} ${LIBS} -o four_thousand_lines 

run: math
	@echo Executing ...
	./one_thousand_lines
	#./two_thousand_lines
	#./four_thousand_lines
	
