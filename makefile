CC = gcc
OBJS = main.o main_aux.o SPPoint.o SPBPriorityQueue.o
EXEC = ex2
COMP_FLAG = -std=c99 -Wall -Wextra \
-Werror -pedantic-errors

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ -lm
main.o: main.c main_aux.h SPPoint.h SPBPriorityQueue.h
	$(CC) $(COMP_FLAG) -c -lm $*.c
main_aux.o: main_aux.c main_aux.h
	$(CC) $(COMP_FLAG) -c -lm $*.c
SPPoint.o: SPPoint.c SPPoint.h 
	$(CC) $(COMP_FLAG) -c -lm $*.c
SPBPriorityQueue.o: SPBPriorityQueue.c SPBPriorityQueue.h
	$(CC) $(COMP_FLAG) -c -lm $*.c
clean:
	rm -f $(OBJS) $(EXEC)
