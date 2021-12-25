CC = gcc
AR = ar
OBJECTS_MAIN = main.o
OBJECTS_EDGE = edge.o
OBJECTS_NODE = node.o
EDGE_HEADER = edge.h
NODE_HEADER = node.h
FLAGS = -Wall -g

all: graphProg

graphProg: $(OBJECTS_MAIN) lib_edge.a lib_node.a
	$(CC) $(FLAGS) -o graphProg $(OBJECTS_MAIN) lib_edge.a lib_node.a

lib_node.a: $(OBJECTS_NODE)
	$(AR) -rcs lib_node.a $(OBJECTS_NODE) # create static library

lib_edge.a: $(OBJECTS_EDGE)
	$(AR) -rcs lib_edge.a $(OBJECTS_EDGE) # create static library

main.o: main.c
	$(CC) $(FLAGS) -c main.c

node.o: node.c $(NODE_HEADER)
	$(CC) $(FLAGS) -c node.c

edge.o: edge.c $(EDGE_HEADER)
	$(CC) $(FLAGS) -c edge.c

clean:
	rm -f *.o *.a graphProg