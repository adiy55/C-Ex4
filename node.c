#include "node.h"

void addNode(Node **head, int srcID) {
    NodeP input_node = (Node *) malloc(sizeof(Node));
    checkIfAllocated(input_node);
    input_node->next = NULL;
    input_node->node_id = srcID;
    input_node->edges = NULL;
    NodeP check = findNode(head, srcID), tmp;
    if (check) {
        updateEdgeDest(head, input_node, check);
        freeNode(head, check, 0);
    }
    if (*head == NULL) {
        *head = input_node;
        return;
    } else {
        tmp = *head;
        *head = input_node;
        input_node->next = tmp;
    }
}

void updateEdgeDest(NodeP *head, NodeP input_node, NodeP check) {
    NodeP iter = *head;
    while (iter != NULL) {
        if (iter != check) {
            EdgeP e = findEdge(iter, check->node_id);
            if (e != NULL) {
                e->dest_node = input_node;
            }
        }
        iter = iter->next;
    }
}

NodeP findNode(NodeP *head, int idx) {
    if (*head == NULL) {
        return NULL;
    }
    NodeP iter = *head;
    while (iter != NULL) {
        if (iter->node_id == idx) {
            return iter;
        }
        iter = iter->next;
    }
    return NULL;
}

void freeNode(NodeP *head, NodeP n, int delete_graph) {
    if (*head == NULL) {
        return;
    }
    if (!delete_graph) {
        freeEdges(*head, n);
    }
    EdgeP e = n->edges, tmp;
    while (e != NULL) {
        tmp = e;
        e = e->next;
        free(tmp);
    }
    n->edges = NULL;
    NodeP iter = *head, target;
    if (iter == n) {
        target = iter;
        *head = iter->next;
        free(target);
    } else {
        while (iter->next != NULL) {
            if (iter->next == n) {
                target = iter->next;
                iter->next = iter->next->next;
                free(target);
                break;
            }
            iter = iter->next;
        }
    }
}
