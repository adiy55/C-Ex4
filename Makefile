CC = gcc
AR = ar
OBJECTS_MAIN = main.o
OBJECTS_MY_MAT = my_mat.o
OBJECTS_HEADER = my_mat.h
FLAGS = -Wall -g

#all: connections
#
#connections: $(OBJECTS_MAIN) libmy_mat.a
#	$(CC) $(FLAGS) -o connections $(OBJECTS_MAIN) libmy_mat.a
#
#libmy_mat.a: $(OBJECTS_MY_MAT)
#	$(AR) -rcs libmy_mat.a $(OBJECTS_MY_MAT) # create static library
#
#main.o: main.c $(OBJECTS_HEADER)
#	$(CC) $(FLAGS) -c main.c
#
#my_mat.o: my_mat.c $(OBJECTS_HEADER)
#	$(CC) $(FLAGS) -c my_mat.c
#
#clean:
#	rm -f *.o *.a connections