#ifndef C_EX4_ALGO_H
#define C_EX4_ALGO_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "node.h"
#include "edge.h"

typedef struct GRAPH_NODE *NodeP, Node;
typedef struct GRAPH_EDGE *EdgeP, Edge;

typedef struct HEAP {
    NodeP *nodes; // pointer to nodes // heap
    int size;
} Heap;

char ACTION;
int NUM_NODES, CURR_NODE;
Heap MIN_HEAP;

// cmd functions
void deleteNode_CMD(NodeP *head);
void printGraph_CMD(NodeP head); // for self debug
void deleteGraph_CMD(NodeP* head);
void shortestPath_CMD(NodeP head);
void TSP_CMD(NodeP head);

// helper functions
void checkIfAllocated(void *p);
void initNodes(NodeP *head);
void initEdges(NodeP *head);
void initHeap(NodeP *head, NodeP n);

// algorithms
void dijkstra(NodeP head, int target);
void TSP(NodeP head, int list[]);

// min heap
void push(Heap *h, NodeP v);
void heapifyUp(Heap *h, int pos);
void swap(Heap *h, int i, int j);
int min(Heap *h, int i, int j);
NodeP pop(Heap *h);

#endif
