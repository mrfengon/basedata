CC = gcc

CCFLAGS = -g

OBJ = basedata.o main.o

.SUFFIXES: .c .o

main: $(OBJ)
	@$(CC) $(CCFLAGS) $(OBJ) -o main

select: basedata.o select.o
	@$(CC) $(CCFLAGS) basedata.o select.o -o select

select.o: basedata.o
	$(CC) -c $(CCFLAGS) select.c

main.o: basedata.o
	$(CC) -c $(CCFLAGS) main.c

basedata.o: basedata.h basedata.c
	$(CC) -c $(CCFLAGS) basedata.h basedata.c

clean:
	@rm -f *.o *.gch main