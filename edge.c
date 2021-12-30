#include "edge.h"
#include "algo.h"

void addEdge(NodeP src, NodeP dest, int weight) {
    EdgeP check = findEdge(src, dest->node_id);
    if (check) {
        freeEdge(&(src->edges), dest);
    }
    EdgeP new_edge = (Edge *) malloc(sizeof(Edge));
    checkIfAllocated(new_edge);
    new_edge->dest_node = dest;
    new_edge->weight = weight;
    EdgeP tmp = src->edges;
    if (tmp == NULL) {
        new_edge->next = NULL;
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
    while (*head != NULL) {
        if (*head != n) {
            freeEdge((EdgeP *) (*head)->edges, n);
        }
    }
}

void freeEdge(EdgeP *edges, NodeP node) { // Node is the dest Node of the Edge (what we want to delete)
    if (*edges == NULL) { // empty linked list
        return;
    }
    EdgeP iter = *edges;
    if (iter->next == NULL) { // one Edge in list
        if (iter->dest_node == node) {
            free(iter);
        }
        return;
    }
    while (iter->next != NULL) { // two or more edges in list
        if (iter->next->dest_node == node) {
            EdgeP tmp = iter->next;
            iter->next = iter->next->next;
            free(tmp);
        }
    }
}