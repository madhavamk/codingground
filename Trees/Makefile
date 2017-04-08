CC = gcc
CFLAGS  = -Wall

all: tree

tree:  tree_driver.o tree_util.o  
	$(CC) $(CFLAGS) -o tree tree_driver.o tree_util.o

tree_driver.o:  tree_driver.c 
	$(CC) $(CFLAGS) -c tree_driver.c

counter.o:  tree_util.c tree_util.h 
	$(CC) $(CFLAGS) -c tree_util.c
	
clean: 
	$(RM) tree *.o *~
