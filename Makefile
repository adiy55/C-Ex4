CC = gcc
AR = ar
OBJECTS_MAIN = main.o
OBJECTS_EDGE = edge.o
OBJECTS_NODE = node.o
OBJECTS_ALGO = algo.o
OBJECTS_HEAP = minHeap.o
EDGE_HEADER = edge.h
NODE_HEADER = node.h
ALGO_HEADER = algo.h
FLAGS = -Wall -g

all: graphProg

graphProg: $(OBJECTS_MAIN) lib_edge.a lib_node.a lib_algo.a
	$(CC) $(FLAGS) -o graphProg $(OBJECTS_MAIN) lib_edge.a lib_node.a lib_algo.a

lib_algo.a: $(OBJECTS_ALGO) $(OBJECTS_EDGE) $(OBJECTS_NODE) $(OBJECTS_HEAP)
	$(AR) -rcs lib_algo.a $(OBJECTS_ALGO) $(OBJECTS_EDGE) $(OBJECTS_NODE) $(OBJECTS_HEAP) # creates static library

lib_node.a: $(OBJECTS_NODE) $(OBJECTS_EDGE) $(OBJECTS_ALGO)
	$(AR) -rcs lib_node.a $(OBJECTS_NODE) $(OBJECTS_EDGE) $(OBJECTS_ALGO) # create static library

lib_edge.a: $(OBJECTS_EDGE) $(OBJECTS_NODE) $(OBJECTS_ALGO)
	$(AR) -rcs lib_edge.a $(OBJECTS_EDGE) $(OBJECTS_NODE) $(OBJECTS_ALGO) # create static library

main.o: main.c
	$(CC) $(FLAGS) -c main.c

minHeap.o: minHeap.c $(ALGO_HEADER) $(EDGE_HEADER) $(NODE_HEADER)
	$(CC) $(FLAGS) -c minHeap.c

algo.o: algo.c $(ALGO_HEADER) $(EDGE_HEADER) $(NODE_HEADER)
	$(CC) $(FLAGS) -c algo.c

node.o: node.c $(NODE_HEADER) $(EDGE_HEADER) $(ALGO_HEADER)
	$(CC) $(FLAGS) -c node.c

edge.o: edge.c $(EDGE_HEADER) $(NODE_HEADER) $(ALGO_HEADER)
	$(CC) $(FLAGS) -c edge.c

clean:
	rm -f *.o *.a graphProg