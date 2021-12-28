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
void addNode_CMD(node **head);
void deleteNode_CMD(p_node *head);
void printGraph_CMD(p_node head); // for self debug
void deleteGraph_CMD(p_node* head);
void shortestPath_CMD(p_node head);
void TSP_CMD(p_node head);

// helper functions
void free_node(p_node n);
void add_edge(p_node n, int dest, int weight);
int findNode(p_node *head, int idx); // return 0 if found - otherwise return 1
int findEdge(p_node *head, int srcNode, int dest); // return 0 if found - otherwise return 1
void addEdge(p_node *head, p_edge input);

// algorithms
int shortestPath(p_node src, p_node dest);
int dijkstra();


#endif //C_EX4_ALGO_H
