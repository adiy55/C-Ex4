#ifndef C_EX4_NODE_H
#define C_EX4_NODE_H

#include <stdlib.h>
#include "algo.h"
#include "edge.h"

typedef struct GRAPH_EDGE *EdgeP, Edge;

typedef struct GRAPH_NODE {
    int node_id;
    EdgeP edges; // edges out of the Node
    struct GRAPH_NODE *next;
} Node, *NodeP;

void addNode(Node **head, int srcID);
void freeNode(NodeP *head, NodeP n);
NodeP findNode(NodeP *head, int idx);

#endif
