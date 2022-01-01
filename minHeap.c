#include "algo.h"

Heap createHeap() {
    Heap *h = calloc(1, sizeof(Heap));
    h->nodes = calloc(NUM_NODES, sizeof(int));
    h->prev = calloc(NUM_NODES, sizeof(int));
    h->size = -1;
    h->prev_len = -1;
    return *h;
}

void push(Heap *h, NodeP v) {
    if (h->size == (NUM_NODES - 1)) {
        return;
    }
    h->size++;
    h->nodes[h->size] = v;
    heapifyUp(h, h->size);
}

void heapifyUp(Heap *h, int pos) {
    if (pos == 0) {
        return;
    }
    int parent = ((pos - 1) / 2);
    if (h->nodes[pos]->dist < h->nodes[parent]->dist) {
        swap(h, pos, parent);
        heapifyUp(h, parent);
    }
}

void swap(Heap *h, int i, int j) {
    NodeP tmp = h->nodes[i];
    h->nodes[i] = h->nodes[j];
    h->nodes[j] = tmp;
}

int min(Heap *h, int i, int j) {
    int m = h->size;
    int left = h->nodes[i]->dist;
    int right = h->nodes[j]->dist;
    int max = h->nodes[m]->dist;
    if (i <= h->size && left < max) {
        m = i;
    }
    if (j <= h->size && right < max)
        m = j;
    return m;
}

NodeP pop(Heap *h) {
    int i = 0;
    NodeP v = h->nodes[0];
    while (1) {
        int j = min(h, 2 * i + 1, 2 * i + 2); // min val between children
        if (j == h->size) {
            break;
        }
        h->nodes[i] = h->nodes[j];
        i = j;
    }
    h->nodes[i] = h->nodes[h->size];
    h->size--;
    return v;
}

//void dijkstra(Heap *h, int a, int b) {
//
//}

