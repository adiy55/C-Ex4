#ifndef C_EX4_ALGO_H
#define C_EX4_ALGO_H

typedef struct graph_node *p_node;

typedef struct graph_edge {
    int weight;
    p_node dest_node;
    struct graph_edge *next;
} edge, *p_edge;


typedef struct graph_node {
    int node_id;
    p_edge edges; // edges out of the node
    struct graph_node *next;
} node, *p_node;

// cmd functions
void buildGraph_CMD(p_node *head);
void addNode_CMD(p_node *head);
void deleteNode_CMD(p_node *head);
void printGraph_CMD(p_node head); // for self debug
void deleteGraph_CMD(p_node* head);
void shortestPath_CMD(p_node head);
void TSP_CMD(p_node head);

// algorithms
int shortestPath(p_node src, p_node dest);
int dijkstra();


#endif //C_EX4_ALGO_H
