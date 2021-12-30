#include "edge.h"
#include "algo.h"

void addEdge(NodeP src, NodeP dest, int weight) {
    EdgeP check = findEdge(src, dest->node_id);
    if (check) {
        freeEdge(src, dest);
    }
    EdgeP new_edge = (Edge *) malloc(sizeof(Edge));
    checkIfAllocated(new_edge);
    new_edge->dest_node = dest;
    new_edge->weight = weight;
    new_edge->next = NULL;
    EdgeP tmp = src->edges;
    if (tmp == NULL) {
        src->edges = new_edge;
        return;
    }
    new_edge->next = tmp;
    src->edges = new_edge;
}

EdgeP findEdge(NodeP src_node, int destID) {
    EdgeP iter = src_node->edges;
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

void freeEdges(NodeP *head, NodeP n) {
    NodeP iter = *head;
    while (iter != NULL) {
        if (iter != n && iter->edges != NULL) {
            freeEdge(iter, n);
        }
        iter = iter->next;
    }
}

void freeEdge(NodeP src, NodeP dest) { // Node is the dest Node of the Edge (what we want to delete)
    EdgeP iter = src->edges;
    if (iter->next == NULL && iter->dest_node == dest) { // one Edge in list
        free(iter);
    } else {
        while (iter->next != NULL) { // two or more edges in list
            if (iter->next->dest_node == dest) {
                EdgeP tmp = iter->next;
                iter = iter->next->next;
                free(tmp);
            }
            iter = iter->next;
        }
    }
}