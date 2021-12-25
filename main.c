#include <stdio.h>
#include "node.h"
#include "edge.h"
#include "algo.h"

int main() {
    int run = 1, len_path;
    char action = 'A';
    while (run) {
        // action A: insert a new graph
        // action B: create new node with new out edges
        // action D: delete node
        // action S: shortest path between two given nodes
        // action T: TSP
        scanf("%c", &action);
      if (action == 'A') {
            insert(matrix);
        } else {
            calc_matrix(); // calculate the shortest path
            if (action == 'B') {
                is_there_a_route(shortest_path) ? printf("True\n") : printf("False\n");
            } else if (action == 'D') {
                len_path = what_is_the_shortest_route(shortest_path);
                len_path ? printf("%d\n", len_path) : printf("-1\n");
            } else if (action == 'S'){

            } else if (action == 'T'){

            }
        }
    }
    return 0;
}