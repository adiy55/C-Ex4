#ifndef C_EX4_EDEG_H
#define C_EX4_EDEG_H

#include <stdlib.h>
#include"algo.h"
#include "node.h"

typedef struct GRAPH_NODE *NodeP, Node;

typedef struct GRAPH_EDGE {
    int weight;
    NodeP dest_node;
    struct GRAPH_EDGE *next;
} Edge, *EdgeP;

void addEdge(NodeP src, NodeP dest, int weight);
EdgeP findEdge(NodeP src_node, int destID);
void freeEdges(NodeP *head, NodeP n);
void freeEdge(EdgeP *edges, NodeP node);

#endif
