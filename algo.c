#include <stdio.h>
#include <stdlib.h>
#include "algo.h"

//#include <math.h>
//void insert_append(p_node, p_node);

//Based on rsetta Code - https://rosettacode.org/wiki/Singly-linked_list/Element_insertion
void insert_append(p_node *anchor, p_node *newNode);

void addNode_CMD(p_node *head, p_node *input_node) {
    p_node *currNode = head, *tmp;
    if (head == NULL) {
        head = input_node;
        return;
    }
    //int id = input_node.node_id
    while ((*currNode)->next != NULL /*&& id>currNode.node_id*/) {
        if ((*currNode)->next->node_id > (*input_node)->node_id) {
            *currNode = (*currNode)->next;
        } else if ((*input_node)->node_id == (*currNode)->next->node_id) {
            *tmp = (*currNode)->next;
            (*currNode)->next = *input_node;
            (*input_node)->next = (*tmp)->next;
            free(*tmp);
            return;
        }
    }
    insert_append(currNode, (p_node *) &input_node);

}

void insert_append(p_node *anchor, p_node *newNode) {
    (*newNode)->next = (*anchor)->next;
    (*anchor)->next = *newNode;
}



void buildGraph_CMD(p_node *head) {
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