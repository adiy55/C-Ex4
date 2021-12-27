#include <stdio.h>
#include <stdlib.h>
#include "algo.h"

//#include <math.h>

void addNode_CMD(node **head) {
    p_node input_node = (node *) malloc(sizeof(node));
    if (input_node == NULL) {
        return;
    }
    input_node->next = NULL;
//    input_node->node_id =
    if (*head == NULL) {
        *head = input_node;
        return;
    }
    p_node iter = *head;
    if (iter->next == NULL) {
        if (iter->node_id < input_node->node_id) {
            input_node->next = iter;
            iter->next = NULL;
            *head = input_node;
        } else if (iter->node_id > input_node->node_id) {
            iter->next = input_node;
        } else {
            *head = input_node;
            free(iter);
        }
    }
    while (iter->next != NULL) {
        if (iter->next->node_id == input_node->node_id) {
            input_node->next = iter->next->next;
            free_node(iter->next);
            iter->next = input_node;
        } else if (iter->next->node_id > input_node->node_id) {
            input_node->next = iter->next;
            iter->next = input_node;
            return;
        } else {
            iter = iter->next;
        }
    }
}


void buildGraph_CMD(p_node *head) {
    deleteGraph_CMD(&head);
    int k;
    char tmp;
    scanf("%d", &k);
    while (scanf("%c", &tmp) != NULL) {

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