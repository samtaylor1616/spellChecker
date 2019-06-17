CC = gcc
CFLAGS = -Wall -ansi -pedantic -Werror -g
OBJ = main.o fileIO.o linkedList.o listFunctions.o settings.o
EXEC = spellCheck

$(EXEC): $(OBJ)
	$(CC) $(OBJ) check.o -o $(EXEC)

main.o: main.c main.h fileIO.h linkedList.h listFunctions.h check.h settings.h
	$(CC) main.c -c $(CFLAGS)

fileIO.o: fileIO.c fileIO.h linkedList.h settings.h
	$(CC) fileIO.c -c $(CFLAGS)

linkedList.o: linkedList.c linkedList.h 
	$(CC) linkedList.c -c $(CFLAGS)

listFunctions.o: listFunctions.c listFunctions.h linkedList.h
	$(CC) listFunctions.c -c $(CFLAGS)

settings.o: settings.c settings.h
	$(CC) settings.c -c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
