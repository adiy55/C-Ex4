#include <stdio.h>
#include "node.h"
#include "edge.h"
#include "algo.h"

int main() {
    int run = 1;//, len_path;
//    char action = 'A';
    // action A: insert a new graph
    // action B: create new node with new out edges
    // action D: delete node
    // action P: print node
    // action S: shortest path between two given nodes
    // action T: TSP
//    scanf("%c", &action);
    scanf("%c", &ACTION);
    p_node head = NULL;
    while (run) {
        if (ACTION == 'A') {
            deleteGraph_CMD(&head);
//            scanf("%d", &k);
//            head = generate(k);
            buildGraph_CMD(&head);
        }
        if (ACTION == 'B') {
            addNode_CMD(&head);
        }
//        if (ACTION == 'p') {
//            printGraph_CMD(head);
//            run = 0;
//        }
        printGraph_CMD(head);
//        if (ACTION == 'S') {
//            shortestPath_CMD(head);
//        }
//        if (ACTION == 'D') {
//            deleteNode_CMD(&head);
//        }
//        if (ACTION == 'T') {
//            TSP_CMD(head);
//        }
        if (ACTION == '\n') {
            run = 0;
        }
    }
    return 0;
}