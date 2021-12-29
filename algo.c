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
        printf("There is a memory allocate problem\n");
    }
    while (scanf("%d", &c)) {
        if (isupper(c) || c == '\n') {
            ACTION = c;
            return;
        }
        scanf("%d", &weight);
        exist = findNode(head, c);
        if (exist != NULL) { // if exist isn't NULL
            edge_exist = findEdge(currNode, c);
            if (edge_exist != NULL) { // edge_exist isn't NULL
                freeEdge(currNode->edges, exist);
            }

        } else {
            p_node dest_node = addNode(head, c);

        }
        addEdge(currNode, c, weight);
    }
}

p_node addNode(node **head, int srcID) {
    p_node input_node = (node *) malloc(sizeof(node));
    if (input_node == NULL) { // check if memory was successfully allocated
        return NULL;
    }
    input_node->next = NULL;
    input_node->node_id = srcID;
    if (*head == NULL) {
        *head = input_node;
        return input_node;
    }
    p_node iter = *head;
    if (iter->next == NULL) {
        if (iter->node_id < input_node->node_id) {
            input_node->next = iter;
            iter->next = NULL;
            *head = input_node;
            return input_node;
        } else if (iter->node_id > input_node->node_id) {
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
}


void buildGraph_CMD(p_node *head) {
    deleteGraph_CMD(head);
    int c, weight, numOfNodes, currNodeID;
    char tmp;
    p_node curr_node,curr_dest;
    p_edge curr_edge;
    scanf('%d', &numOfNodes);
    while (scanf("%d", &c)) {
        if (isupper(c) || c == '\n') {
            ACTION = c;
            return;
        }
        if (c == 'n') {
            if (scanf("%d", &c)) {
                currNodeID = c;
                curr_node = findNode(head,c);
                if(curr_node==NULL) {
                    curr_node = addNode(head, c);
                }
            }
        }
        if(isdigit(c)){
            curr_dest = findNode(head,c);
            if(curr_dest==NULL){
                addNode(head,c);
            }
            if(scanf("%d",&weight)){
                curr_edge = findEdge(curr_node,c);
                if(curr_edge!=NULL){
                    freeEdge(&(curr_node->edges),curr_node);
                }
                addEdge(curr_node,curr_dest,weight);
            }
        }
    }
}

void deleteGraph_CMD(p_node *head) {
    p_node *curr_node = head, *tmp_node;
    p_edge *curr_edges, *tmp_edges;
    while (*curr_node != NULL) {
        *curr_edges = (*curr_node)->edges;
        while (*curr_edges != NULL) {
            *tmp_edges = (*curr_edges);
            *curr_edges = (*curr_edges)->next;
            free(*tmp_edges); // todo: is the dest_node an address? or does it delete the actual node?
        }
        *tmp_node = *curr_node;
        *curr_node = (*curr_node)->next;
        free(*tmp_node);
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
    if(tmp == NULL){
        new_edge->next = NULL;
        src->edges = new_edge;
        return;
    }
    new_edge->next = tmp;
    src->edges = new_edge;
}