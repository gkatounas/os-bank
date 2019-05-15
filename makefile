OBJS	= test.o graph.o list.o hashtable.o
SOURCE	= test.c graph.c list.c hashtable.c
HEADER	= graph.h list.h hashtable.h
OUT	    = elegxos
CC	    = gcc
FLAGS	= -g -c

$(OUT):	$(OBJS)
	$(CC)	-g	$(OBJS)	-o	$@
test.o:	test.c
	$(CC)	$(FLAGS)	test.c
graph.o:	graph.c
	$(CC)	$(FLAGS)	graph.c
list.o:	list.c
	$(CC)	$(FLAGS)	list.c
hashtable.o:	hashtable.c
	$(CC)	$(FLAGS)	hashtable.c
clean:
	rm -f $(OBJS) $(OUT)
