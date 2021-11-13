#ifndef HEAP_H
#define HEAP_H

#include "AdjList.h"

typedef struct MinHeapNode MHNode;
struct MinHeapNode
{
    int v;
    int value;
};

typedef struct MinHeap MinHeap
struct MinHeap
{
    int size;
    int capacity;
    int * position;
    MHNode ** nodes;
};



#endif