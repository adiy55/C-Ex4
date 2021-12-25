#ifndef C_EX4_ALGO_H
#define C_EX4_ALGO_H

typedef struct graph_node *pnode;

typedef struct graph_edge {
    int weight;
    pnode dest_node;
    struct graph_edge *next;
} edge, *pedge;


typedef struct graph_node {
    int node_id;
    pedge edges;
    struct graph_node *next;
} node, *pnode;

// cmd functions
void buildGraph_CMD(pnode *head);
void addNode_CMD(pnode *head);
void deleteNode_CMD(pnode *head);
void printGraph_CMD(pnode head); // for self debug
void deleteGraph_CMD(pnode* head);
void shortestPath_CMD(pnode head);
void TSP_CMD(pnode head);

// algorithms
int shortestPath(pnode src, pnode dest);
int dijkstra();


#endif //C_EX4_ALGO_H
