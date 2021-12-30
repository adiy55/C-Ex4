#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "edge.h"
#include "algo.h"

int main() {
    // action A: insert a new graph
    // action B: create new Node with new out edges
    // action D: delete Node
    // action P: print Node
    // action S: shortest path between two given nodes
    // action T: TSP
    NodeP head = NULL;
    while (scanf("%c", &ACTION) && ACTION != '\n') {
        if (ACTION == 'A') {
            deleteGraph_CMD(&head);
            head = NULL;
            scanf("%d", &NUM_NODES);
            initNodes(&head);
        } else if (ACTION == 'n') {
            scanf("%d", &CURR_NODE);
            initEdges(&head);
        } else if (ACTION == 'B') {
            scanf("%d", &CURR_NODE);
            addNode(&head, CURR_NODE);
            initEdges(&head);
        } else if (ACTION == 'S') {
//            shortestPath_CMD(head);
        } else if (ACTION == 'D') {
            deleteNode_CMD(&head);
        } else if (ACTION == 'T') {
//            TSP_CMD(head);
        } else if (ACTION == 'P') { // for debugging
            printGraph_CMD(head);
        }
    }
//    deleteGraph_CMD(&head); // todo: fix memory free
    return 0;
}