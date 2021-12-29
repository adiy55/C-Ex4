#ifndef C_EX4_ALGO_H
#define C_EX4_ALGO_H

int ACTION;

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
void addNode_CMD(node **head);
void deleteNode_CMD(p_node *head);
void printGraph_CMD(p_node head); // for self debug
void deleteGraph_CMD(p_node* head);
void shortestPath_CMD(p_node head);
void TSP_CMD(p_node head);

// helper functions
void free_node(p_node n);
p_node findNode(p_node *head, int idx); // return 0 if found - otherwise return 1
p_edge findEdge(p_node curr_node, int destID);
void addEdge(p_node src, p_node dest, int weight);
void freeEdge(p_edge *edges, p_node node);

// algorithms
int shortestPath(p_node src, p_node dest);
int dijkstra();


#endif //C_EX4_ALGO_H
