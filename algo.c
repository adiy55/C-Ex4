#include"algo.h"

void checkIfAllocated(void *p) {
    if (p == NULL) {
        exit(1);
    }
}

void initNodes(NodeP *head) {
    for (int i = NUM_NODES - 1; i >= 0; i--) {
        addNode(head, i);
    }
}

void initEdges(NodeP *head) {
    int d, weight;
    NodeP src = findNode(head, CURR_NODE), dest;
    if(!src){
        printf("ERROR! NO SRC NODE! %d", CURR_NODE);
        exit(1);
    }
    while (scanf("%d%d", &d, &weight)) {
        dest = findNode(head, d);
        if(!dest){
            printf("ERROR! NO DEST NODE!");
            exit(1);
        }
        addEdge(src, dest, weight);
    }
}

void deleteNode_CMD(NodeP *head) {
    int reqNode;
    scanf("%d", &reqNode);
    NodeP n = findNode(head, reqNode);
    if (!n) {
        freeNode(head, n);
    }
}

void deleteGraph_CMD(NodeP *head) {
    if (*head == NULL) {
        return;
    }
    NodeP iter = *head, tmp;
    while (iter != NULL) {
        tmp = iter;
        iter = iter->next;
        freeNode(head, tmp);
    }
}

void printGraph_CMD(NodeP head) { // for self debug
    while (head != NULL) {
        printf("Node ID: %d ", head->node_id);
        EdgeP iter = head->edges;
        while (iter != NULL) {
            printf("Dest: %d, Weight: %d, ", iter->dest_node->node_id, iter->weight);
            iter = iter->next;
        }
        head = head->next;
        printf("\n");
    }
}
