all: clear compile run clean

compile: main.c util.c util.h
	@gcc main.c -o test
run:
	@./test
clean:
	@rm -f test
clear:
	@clear