#ifndef C_EX4_ALGO_H
#define C_EX4_ALGO_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "edge.h"

char ACTION;
int NUM_NODES, CURR_NODE;

typedef struct GRAPH_NODE *NodeP, Node;
typedef struct GRAPH_EDGE *EdgeP, Edge;

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

// algorithms
int shortestPath(NodeP src, NodeP dest);
int dijkstra();


#endif
