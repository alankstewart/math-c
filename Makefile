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
	rm -f two_thousand_lines 

math:
	@echo 'Building target: $@'
	gcc -o two_thousand_lines src/two_thousand_lines.c ${CFLAGS} ${LIBS} 

run: math
	@echo Executing ...
	./two_thousand_lines
