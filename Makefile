build   : main.o logic.o print.o optim.o utils.o
	    gcc -o 2048 main.o logic.o print.o optim.o utils.o -lcurses
main.o  : main.c
	    gcc -c main.c
logic.o : logic.c logic.h
	    gcc -c logic.c
print.o : print.c
	    gcc -c print.c
optim.o : optim.c
	    gcc -c optim.c
utils.o : utils.c
	    gcc -c utils.c
clean   :
	    rm 2048
	    rm *.o	
run     : build
	    ./2048

