#ifndef ADJLIST_H
#define ADJLIST_H

typedef struct AdjListNode ALNode;
struct AdjListNode
{
    int dest;
    int weight;
    ALNode* next;
};

typedef struct ADJList ADJList;
struct ADJList
{
    ALNode* head;
};

typedef struct Graph Graph;
struct Graph
{
    int V;
    ADJList* nodes;
};

ALNode * newAdjListNode(int dest, int weight)
{
    ALNode * newnode   =  malloc(sizeof(ALNode));
    newnode -> dest    =  dest;
    newnode -> weight  =  weight;

    return newnode;
}

Graph * createGraph(int V)
{
    Graph * newGraph = malloc(sizeof(Graph));
    newGraph -> V = V;

    newGraph -> nodes = malloc(sizeof(ADJList));

    for(int i = 0; i < V; i++)
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

#endif