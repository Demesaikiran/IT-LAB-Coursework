#include "getValues.h"
#include "bfs_matrix.h"

typedef struct AdjMat ADJMat;
struct AdjMat
{
    int nOfVertices;
    int array[MAXSIZE][2];
    int nOfEdges;
};


typedef struct AdjListNode NODE;
struct AdjListNode
{
    int end;
    NODE * next;
};

typedef struct AdjList ADJLIST;
struct AdjList
{
    NODE * head;
};

typedef struct Graph GRAPH;
struct Graph
{
    int nOfVertices;
    ADJLIST * arr;
};

NODE * ListNode(int end)
{
    NODE * newnode = (NODE *) malloc(sizeof(NODE));
    newnode -> end = end;
    newnode -> next = NULL;
    return newnode;
}

GRAPH * createGraph(int n)
{
    GRAPH * graph = (GRAPH *)malloc(sizeof(GRAPH));
    graph -> nOfVertices = n;

    graph -> arr = (ADJLIST *) malloc(n * sizeof(ADJLIST));

    for(int i = 0; i < n; i++)
    {
        graph -> arr[i].head = NULL;
    }

    return graph;
}

void addEdge(GRAPH * graph, int start, int end)
{
    NODE * newnode            =  ListNode(end);
    newnode -> next           =  graph -> arr[start].head;
    graph -> arr[start].head  =  newnode;

    //Adding edge for two nodes
    newnode = ListNode(start);
    newnode -> next = graph -> arr[end].head;
    graph -> arr[end].head = newnode;
}


void ExploreList(GRAPH * graph, int node, QUEUE * visited, QUEUE * explored)
{
    printf("%d\t", node+1);

    NODE * traverse = graph -> arr[node].head;
    if(traverse == NULL)
    {
        printf("\nEXIT\n");
    }

    while(traverse != NULL)
    {
        if(isVisited(*visited, traverse -> end) || isExplored(*explored, traverse -> end))
        {
            traverse = traverse -> next;
            continue;
        }
        enQueue(visited, traverse -> end);
    }

    return;
}
void printGraph(GRAPH * graph)
{
    printf("\nADJACENCY LIST OF EACH VERTEX OF GRAPH:\n========================================\n");
    for(int i = 0; i < graph -> nOfVertices; i++)
    {
        NODE * newnode = graph -> arr[i].head;
        printf("\n Adjacency list of vertex %d\n head ", i);
        while (newnode)
        {
            printf("-> %d", newnode -> end);
            newnode = newnode->next;
        }
        printf("\n");
    }
    printf("\n\n");
}
void BFS_List_Traverse(ADJMat *edges, int choiceNode, int edgeCount)
{
    GRAPH * graph = createGraph(edges -> nOfVertices);

    for(int i = 0; i < edgeCount; i++)
    {
        addEdge(graph, edges -> array[i][0], edges -> array[i][1]);
    }

    printGraph(graph);
    printf("\n\nExplored nodes in the order of:\n\n");

    QUEUE readyQ;
    readyQ.front = readyQ.rear = -1;
    QUEUE explored;
    explored.front = explored.rear = -1;

    enQueue(&explored, choiceNode-1);
    ExploreList(graph, choiceNode-1, &readyQ, &explored);

    while(!isQueueEmpty(&readyQ))
    {
        int node = dequeue(&readyQ);
        enQueue(&explored, node);
        ExploreList(graph, node, &readyQ, &explored);
    }
    printf("\n\n");

}   
