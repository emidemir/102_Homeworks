all: clean compile run

compile: main.c utils.c utils.h
	@gcc -o test main.c utils.c

run:
	./test

clean:
	@rm -f *.o
	@rm -f test
	@rm -f customeraccount.txt