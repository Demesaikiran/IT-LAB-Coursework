#include<stdio.h>
#include<stdlib.h>

typedef struct node NODE;
struct node
{
    int dest;
    int weight;
    NODE * next;
};

typedef struct list LIST;
struct list
{
    NODE * head;
};

typedef struct graph GRAPH;
{
    int V;
    LIST * vertices;
};

NODE * createnode(int destination, int weight)
{
    NODE * newnode = malloc(sizeof(NODE));
    newnode -> dest = destination;
    newnode -> weight = weight;
    newnode -> next = NULL;
    return newnode;
}

GRAPH * createGraph(int V)
{
    GRAPH * newgraph = malloc(sizeof(GRAPH));
    newgraph -> V = V;

    newgraph -> vertices = malloc((V+1) * sizeof(LIST));
    for(int i = 1; i < V; i++)
    {
        newgraph -> vertices[i].head = NULL;
    }
}