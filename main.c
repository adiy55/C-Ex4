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
    while (scanf("%c", &ACTION)) {
        if (ACTION == '\n') {
            printGraph_CMD(head);
            deleteGraph_CMD(&head);
            break;
        }
        if (ACTION == 'A') {
            deleteGraph_CMD(&head);
            scanf("%d", &NUM_NODES);
            initNodes(&head);
        }
        if (ACTION == 'n') {
            scanf("%d", &CURR_NODE);
            initEdges(&head);
        }
        if (ACTION == 'B') {
            scanf("%d", &CURR_NODE);
            addNode(&head, CURR_NODE);
            initEdges(&head);
        }
        if (ACTION == 'S') {
//            shortestPath_CMD(head);
        }
        if (ACTION == 'D') {
            deleteNode_CMD(&head);
            head = NULL;
        }
        if (ACTION == 'E') {
            printGraph_CMD(head);
            return 0;
        }
        if (ACTION == 'T') {
//            TSP_CMD(head);
        }
    }
    return 0;
}