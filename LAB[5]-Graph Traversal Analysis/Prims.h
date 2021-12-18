#ifndef PRIMS_H
#define PRIMS_H

#include "AdjList.h"
#include "Heap.h"

void PrimMST(Graph * graph)
{
    int V = graph -> V;
    int parent[V];
    int value[V];

    MinHeap * minheap = createMinHeap(V);

    for(int i = 1; i < V; i++)
    {
        parent[i] = -1;
        value[i]  = INT_MAX; // Infinity
        minheap -> nodes[i] = newMinHeapNode(i, value[v]);
        minheap -> position[i] = i;
    }

    // Starting with the 0th vertex

    value[0] = 0;
    minheap -> nodes[0] = newMinHeapNode(0, value[0]);
    minheap -> size = V;

    while(!isEmpty(minheap))
    {
        
    }
}

#endif