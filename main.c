#include <stdio.h>
#include "node.h"
#include "edge.h"
#include "algo.h"

int main() {
    int run = 1, len_path;
    char action = 'A';
    // action A: insert a new graph
    // action B: create new node with new out edges
    // action D: delete node
    // action P: print node
    // action S: shortest path between two given nodes
    // action T: TSP
    scanf("%c", &action);
    p_node head = NULL;
    while (run) {
        if (action == 'A') {
            deleteGraph_CMD(&head);
//            scanf("%d", &k);
//            head = generate(k);
            buildGraph_CMD(&head);
        }
        if (action == 'B') {
            addNode_CMD(&head);
        }
        if (action == 'p') {
            printGraph_CMD(head);
        }
        if (action == 'S') {
            shortestPath_CMD(head);
        }
        if (action == 'D') {
            deleteNode_CMD(&head);
        }
        if (action == 'T') {
            TSP_CMD(head);
        }
    }
    return 0;
}