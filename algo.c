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
    if (!src) {
        printf("ERROR! NO SRC NODE! %d", CURR_NODE);
        exit(1);
    }
    while (scanf("%d %d", &d, &weight)) {
        dest = findNode(head, d);
        if (!dest) {
            printf("ERROR! NO DEST NODE!");
            exit(1);
        }
        addEdge(src, dest, weight);
    }
}

void initHeap(NodeP *head, NodeP n) {
    if (*head == NULL) {
        return;
    }
    MIN_HEAP.nodes = malloc(NUM_NODES * sizeof(NodeP));
    checkIfAllocated(MIN_HEAP.nodes);
    MIN_HEAP.size = -1;
    NodeP iter = *head;
    while (iter != NULL) {
        if (iter == n) {
            iter->dist = 0;
        } else {
            iter->dist = INT_MAX;
        }
        push(&MIN_HEAP, iter);
        iter = iter->next;
    }
}

void deleteNode_CMD(NodeP *head) {
    int reqNode;
    scanf("%d", &reqNode);
    NodeP n = findNode(head, reqNode);
    if (n) {
        freeNode(head, n, 0);
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
        freeNode(head, tmp, 1);
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

void shortestPath_CMD(NodeP head) {
    int src, dest;
    if (scanf("%d %d", &src, &dest)) {
        dijkstra(head, src);
        NodeP d = findNode(&head, dest);
        if (d) {
            int res = d->dist == INT_MAX ? -1 : d->dist;
            printf("Dijsktra shortest path: %d \n", res);
        }
    }
}

void dijkstra(NodeP head, int target) {
    NodeP n = findNode(&head, target), curr;
    EdgeP iter;
    initHeap(&head, n);
    while (MIN_HEAP.size >= 0) {
        curr = pop(&MIN_HEAP);
        iter = curr->edges;
        while (iter != NULL) {
            if (curr->dist != INT_MAX) {
                int curr_dist = curr->dist + iter->weight;
                if (iter->dest_node->dist > curr_dist) {
                    iter->dest_node->dist = curr_dist;
                }
            }
            iter = iter->next;
        }
    }
    free(MIN_HEAP.nodes);
    MIN_HEAP.nodes = NULL;
}

void TSP_CMD(NodeP head) {
    int n_cities = 0, num;
    MIN_TSP = INT_MAX;
    if (scanf("%d", &n_cities)) {
        int list[n_cities];
        for (int i = 0; i < n_cities; ++i) {
            if (scanf("%d", &num)) {
                list[i] = num; // list contains the node ids
            } else {
                printf("INVALID INPUT!");
                exit(1);
            }
        }
        permutation(head, list, 0, n_cities - 1);
        printf("TSP shortest path: %d \n", MIN_TSP);

    }
}

void swapInt(int *a, int *b) { //function to swap the variables
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(NodeP head, int *arr, int start, int end) {
    if (start == end) {
        int sum = 0;
        for (int i = 0; i < end; i++) {
            NodeP currNode = findNode(&head, arr[i]);
            EdgeP currEdge = findEdge(currNode, arr[i + 1]);
            if (currEdge != NULL) {
                sum += currEdge->weight;
            } else {
                return;
            }
        }
        MIN_TSP = (sum < MIN_TSP) ? sum : MIN_TSP;
        return;
    }
    int i;
    for (i = start; i <= end; i++) {
        swapInt((arr + i), (arr + start));
        permutation(head, arr, start + 1, end);
        swapInt((arr + i), (arr + start));
    }
}
