out: sum.o sum1.o
	gcc -o out sum1.o sum.o

sum.o:
	gcc -c sum.c

sum1.o:
	gcc -c sum1.c

clean:
	rm -rf sum.o sum1.o out
