#ifndef C_EX4_ALGO_H
#define C_EX4_ALGO_H

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);
int shortestPath(pnode src, pnode dest);
int dijkstra();


#endif //C_EX4_ALGO_H
