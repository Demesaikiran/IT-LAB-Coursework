#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
/*
#include "AdjList.h"
#include "Prims.h"
*/

/**
 * ADJACENCY LIST AND GRAPH PART
 * 
 */

/**
 * Node Blueprint
 *  ------------------------------
 *  | Destination | Weight | NULL|
 *  ------------------------------
 */
typedef struct AdjListNode ALNode;
struct AdjListNode
{
    int dest;
    int weight;
    ALNode* next;
};

/**
 * List Blueprint
 * A pointer to the Node above
 *            ------------------------------
 * head ----> | Destination | Weight | NULL|
 *            ------------------------------
 */
typedef struct ADJList ADJList;
struct ADJList
{
    ALNode* head;
};

/**
 * Graph Blueprint
 * -------------------------------------
 * | Vertices | Array of list pointers |
 * -------------------------------------
 */
typedef struct Graph Graph;
struct Graph
{
    int V;
    ADJList* nodes;
};

/**
 * Overall Blueprint of Graph
 * -------------------------------------
 * | Vertices | Array of list pointers |
 * -------------------------------------
 *                  |
 *                  |
 *                  v
 * -----------------------------------------------
 * | Head[1] | Head[2] | Head[3] |.....| Head[V] |
 * -----------------------------------------------
 *      |         .
 *      |         .
 *      V         
 *  ------------------------------
 *  | Destination | Weight | NULL|
 *  ------------------------------
 */

ALNode * newAdjListNode(int dest, int weight)
{
    ALNode * newnode   =  malloc(sizeof(ALNode));
    newnode -> dest    =  dest;
    newnode -> weight  =  weight;
    newnode -> next    = NULL;

    return newnode;
}

Graph * createGraph(int V)
{
    Graph * newGraph = malloc(sizeof(Graph));
    newGraph -> V = V;

    newGraph -> nodes = malloc((V+1) * sizeof(ADJList));

    for(int i = 1; i <= V; ++i)
    {
        newGraph -> nodes[i].head = NULL;
    }

    return newGraph;
}

void addEdge(Graph * graph, int src, int dest, int weight)
{
    ALNode * newnode           =  newAdjListNode(dest, weight);
    newnode -> next            =  graph -> nodes[src].head;
    graph -> nodes[src].head   =  newnode;

    // Graph undirected... Presence of edge entry in both the vertices
    newnode                    =  newAdjListNode(src, weight);
    newnode -> next            =  graph -> nodes[dest].head;
    graph -> nodes[dest].head  =  newnode;
}
Graph * ADJListInput(int V, int E)
{
    int src, dest, weight;
    Graph * graph = createGraph(V);
    
    for(int i = 0; i < E; i++)
    {
        scanf("%d%d%d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    return graph;
}

/**************************************************************/
/**
 * MIN HEAP PART
 * 
 */

/**
 * Min -Heap Node structure
 * @param v
 *      The vertex index 
 * @param value
 *      The correspoding value of vertex - v
 */
typedef struct MinHeapNode MHNode;
struct MinHeapNode
{
    int v;
    int value;
};

/**
 * Structure of min Heap
 * @param size
 *      Number of heap nodes
 * @param capacity
 *      Capacity of MinHeap
 * @param position
 *      position of the mentioned node by user for decreasekey() operation
 * @param nodes
 *      Array of min heap nodes
 */
typedef struct MinHeap MinHeap;
struct MinHeap
{
    int size;
    int capacity;
    int * position;
    MHNode ** nodes;
};

MHNode * createMinHeapNode(int v, int value)
{
    MHNode * mhnode= malloc(sizeof(MHNode));
    mhnode -> v = v;
    mhnode -> value = value;
    return mhnode;
}

MinHeap * createMinHeap(int capacity)
{
    MinHeap * mheap = malloc(sizeof(MinHeap));
    mheap -> position = malloc(sizeof(int) * capacity);
    mheap -> nodes = malloc(sizeof(MHNode *) * capacity);
    mheap -> size = 0;
    mheap -> capacity = capacity;

    return mheap;
}

void swapNodes(MHNode ** a, MHNode ** b)
{
    MHNode * temp = *a;
    * a = * b;
    * b = temp;
}

void minHeapify(MinHeap * minheap, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int small = index;

    if((left < minheap -> size) && ((minheap -> nodes[left] -> value) < minheap -> nodes[small] -> value))
        small = left;
    
    if((right < minheap -> size) && ((minheap -> nodes[right] -> value) < minheap -> nodes[small] -> value))
        small = right;

    if(small != index)
    {
        MHNode * newnode = minheap -> nodes[small];
        MHNode * tempnode = minheap -> nodes[index];

        minheap -> position[newnode -> v] = index;
        minheap -> position[tempnode -> v] = small;

        swapNodes(&minheap -> nodes[small], &minheap -> nodes[index]);

        minHeapify(minheap, small);
    }
}
int isEmpty(struct MinHeap *  minheap)
{
    return minheap -> size == 0;
}

int isInMinHeap(MinHeap * mheap, int v)
{
    if(mheap -> position[v] < mheap -> size)
        return 1;
    return 0;
}
MHNode * extractMinHeapNode(MinHeap * minheap)
{
    if(isEmpty(minheap))
        return NULL;

    MHNode * temp = minheap -> nodes[0];

    MHNode * lnode = minheap -> nodes[ minheap -> size - 1];

    minheap -> nodes[0] = lnode;


    minheap -> position[temp -> v] = minheap -> size -1;
    minheap -> position[lnode -> v] = 0;

    --minheap -> size;
    minHeapify(minheap, 0);

    return temp;
}

void decreaseValue(MinHeap * minheap, int v, int value)
{
    int temp = minheap -> position[v];

    minheap -> nodes[temp] -> value = value;


    while(temp && minheap -> nodes[temp] -> value < minheap -> nodes[(temp - 1) / 2] -> value)
    {
        minheap -> position[minheap -> nodes[temp] -> v] = (temp - 1) / 2;
        minheap -> position[minheap -> nodes[(temp - 1) / 2] -> v] = temp;
        swapNodes(&minheap -> nodes[temp], &minheap -> nodes[(temp - 1) / 2]);

        temp = (temp - 1) / 2;
    }
}
/*************************************************************/
/**
 * Prims Algorithms Part
 * 
 */

void printArr(int arr[], int n)
{
    for(int i = 1; i < n; i++)
        printf("%d %d\n",arr[i],i);
}
void PrimMST(Graph * graph)
{
    int V = graph -> V;
    int parent[V+1];
    int value[V+1];

    MinHeap * minheap = createMinHeap(V+1);

    for(int i = 1; i <= V; i++)
    {
        parent[i] = -1;
        value[i]  = INT_MAX; // Infinity
        minheap -> nodes[i] = createMinHeapNode(i, value[V]);
        minheap -> position[i] = i;
    }

    // Starting with the 0th vertex

    value[1] = 0;
    minheap -> nodes[0] = createMinHeapNode(0, value[0]);
    minheap -> position[0] = 0;
    minheap -> size = V;
    while(!isEmpty(minheap))
    {
        MHNode * newnode = extractMinHeapNode(minheap);
        int u = newnode -> v; // Vertex number storing
        ALNode * temp = graph -> nodes[u].head;
        

        while( temp != NULL )
        {
            int v = temp -> dest;

            if(isInMinHeap(minheap, v) && temp -> weight < value[v])
            {
                value[v] = temp -> weight;
                parent[v] = u;
                decreaseValue(minheap, v, value[v]);
            }

            temp = temp -> next;
        }
    }

    printArr(parent, V);
}

void printGraph(Graph * g)
{
    int v = g -> V;
    

    for(int i = 1; i <= v; i++)
    {
        ADJList temp = g -> nodes[i];
        ALNode * newnode = temp.head;
        printf("Vertex - %d: \n\n", i);
        while(newnode != NULL)
        {
            printf("%d | %d --> ", newnode->dest, newnode->weight);
            newnode = newnode->next;
        }
        printf("NULL\n");
        /* 
        ALNode * node = temp -> head;
        printf("%d -- %d\n", node -> dest, node -> weight);
        temp = g -> nodes; */
    }

}
int main()
{
    // nOfV = number of vertices which is n
    // nOfE = number of edges which is m
    int nOfV, nOfE;
    scanf("%d%d", &nOfV, &nOfE);

    Graph * graph = ADJListInput(nOfV, nOfE);
    printGraph(graph);
    PrimMST(graph);
}