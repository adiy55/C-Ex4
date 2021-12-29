#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "algo.h"

//#include <math.h>

p_node addNode(node **head, int srcID);

void addNode_CMD(node **head) {
    int c, weight;
    p_node currNode, exist;
    p_edge edge_exist;
    scanf("%d", &c);
    currNode = addNode(head, c);
    if (currNode == NULL) {
        printf("Error! Could not add node!\n");
    }
    while (scanf("%d", &c)) {
        if (isupper(c) || c == '\n') {
            ACTION = c;
            return;
        }
        p_node destNode;
        scanf("%d", &weight);
        exist = findNode(head, c);
        if (exist != NULL) { // if exist isn't NULL
            edge_exist = findEdge(currNode, c);
            if (edge_exist != NULL) { // edge_exist isn't NULL
                destNode = edge_exist->dest_node;
                freeEdge(&(currNode->edges), exist);
            }
        } else {
            destNode = addNode(head, c);
        }
        addEdge(currNode, destNode, weight);
    }
}

p_node addNode(node **head, int srcID) {
    p_node input_node = (node *) malloc(sizeof(node));
    if (input_node == NULL) { // check if memory was successfully allocated
        return NULL;
    }
    input_node->next = NULL;
    input_node->node_id = srcID;
    input_node->edges = NULL;
    if (*head == NULL) {
        *head = input_node;
        return input_node;
    }
    p_node iter = *head;
    if (iter->next == NULL) {
        if (iter->node_id > input_node->node_id) {
            input_node->next = iter;
            iter->next = NULL;
            *head = input_node;
            return input_node;
        } else if (iter->node_id < input_node->node_id) {
            iter->next = input_node;
            return input_node;
        } else {
            *head = input_node;
            free(iter);
            return input_node;
        }
    }
    while (iter->next != NULL) {
        if (iter->next->node_id == input_node->node_id) {
            input_node->next = iter->next->next;
            free_node(iter->next);
            iter->next = input_node;
            return input_node;
        } else if (iter->next->node_id > input_node->node_id) {
            input_node->next = iter->next;
            iter->next = input_node;
            return input_node;
        } else {
            iter = iter->next;
        }
    }
    return NULL;
}


void buildGraph_CMD(p_node *head) {
    deleteGraph_CMD(head);
    char c;
    int n, weight, numOfNodes;
    p_node curr_node, curr_dest;
    p_edge curr_edge;
    scanf("%d", &numOfNodes);
    while (scanf(" %c", &c)) {
        if (isupper(c) || c == '\n') {
            ACTION = c;
            return;
        }
        if (c == 'n') {
            scanf("%d", &n);
            curr_node = findNode(head, n);
            if (curr_node == NULL) {
                curr_node = addNode(head, n);
            }
            while (scanf("%d%d", &n, &weight)) {
                curr_dest = findNode(head, n);
                if (curr_dest == NULL) {
                    curr_dest = addNode(head, n);
                }
                curr_edge = findEdge(curr_node, n);
                if (curr_edge != NULL) {
                    freeEdge(&(curr_node->edges), curr_dest);
                }
                addEdge(curr_node, curr_dest, weight);
            }
        }
    }
}

void deleteNode_CMD(p_node *head) {
    char reqNode;
    scanf(" %c", &reqNode);
    if (*head == NULL) {
        printf("No Nodes at all!");
        return;
    }
    p_node iter = *head;
    if (iter->next == NULL) {
        if (iter->node_id == reqNode) {
            free_node(iter);
        }
    }
    while (iter->next != NULL) {
        if (iter->next->node_id == reqNode) {
            iter->next = iter->next->next;
            free_node(iter->next);
            return;
        }
        iter = iter->next;
    }
}

void deleteGraph_CMD(p_node *head) {
    if (*head == NULL) {
        return;
    }
    p_node iter = *head, tmp;
    while (iter != NULL) {
        tmp = iter;
        iter = iter->next;
        free_node(tmp);
    }
}

void free_node(p_node n) {
    p_edge e = n->edges, tmp;
    while (e != NULL) {
        tmp = e;
        e = e->next;
        free(tmp);
    }
    free(n);
}

void freeEdge(p_edge *edges, p_node node) { // node is the dest node of the edge (what we want to delete)
    if (*edges == NULL) { // empty linked list
        return;
    }
    p_edge iter = *edges;
    if (iter->next == NULL) { // one edge in list
        if (iter->dest_node == node) {
            free(iter);
        }
        return;
    }
    while (iter->next != NULL) { // two or more edges in list
        if (iter->next->dest_node == node) {
            p_edge tmp = iter->next;
            iter->next = iter->next->next;
            free(tmp);
        }
    }
}

p_node findNode(p_node *head, int idx) {
    if (*head == NULL) {
        return NULL;
    }
    p_node iter = *head;
    while (iter != NULL) {
        if (iter->node_id == idx) {
            return iter;
        }
        iter = iter->next;
    }
    return NULL;
}

p_edge findEdge(p_node src_node, int destID) {
    p_edge iter = src_node->edges;
    if (iter == NULL) { // no edges
        return NULL;
    }
    while (iter != NULL) {
        if (iter->dest_node->node_id == destID) {
            return iter;
        }
        iter = iter->next;
    }
    return NULL;
}


void addEdge(p_node src, p_node dest, int weight) {
    p_edge new_edge = (edge *) malloc(sizeof(edge));
    new_edge->dest_node = dest;
    new_edge->weight = weight;
    p_edge tmp = src->edges;
    if (tmp == NULL) {
        new_edge->next = NULL;
        src->edges = new_edge;
        return;
    }
    new_edge->next = tmp;
    src->edges = new_edge;
}

void printGraph_CMD(p_node head) { // for self debug
    while (head != NULL) {
        printf("Node ID: %d", head->node_id);
        p_edge iter = head->edges;
        while (iter != NULL) {
            printf("Dest: %d, Weight: %d", iter->dest_node->node_id, iter->weight);
            iter = iter->next;
        }
        head = head->next;
    }
}
