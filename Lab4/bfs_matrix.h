#include "getValues.h"

struct queue
{
    int data[MAXSIZE];
    int front;
    int rear;
};
typedef struct queue QUEUE;

struct matrix
{
    int **matrix;
    int squareDim;
};
typedef struct matrix MATRIX;

int isQueueEmpty(QUEUE *qu)
{
    return (qu -> front == -1 && qu -> rear == -1)
            ||
            (qu -> front == qu -> rear + 1) ? 1 : 0;
}

void enQueue(QUEUE *q, int ele)
{
    if(isQueueEmpty(q))
    {
        (q -> front)++;
    }
    (q -> rear) ++;
    q -> data[q -> rear] = ele;

}

int dequeue(QUEUE * qu)
{
    if(isQueueEmpty(qu))
    {
        return -1;
    }
    int node = qu -> data[qu -> front];
    (qu -> front) ++;

    return node;
}

int isVisited(QUEUE visited, int node)
{
    for(int i = 0; i <= visited.rear; i++)
    {
        if(visited.data[i] == node)
        return 1;
    }
    return 0;
}

int isExplored(QUEUE explore, int node)
{
    for(int i = 0; i <= explore.rear; i++)
    {
        if(explore.data[i] == node)
        return 1;
    }
    return 0;
}

void explore(int node, QUEUE * visited, int dim, int **AdjMat, QUEUE *explored)
{
    printf("%d\t", node+1);

    for(int i = 0; i < dim; i++)
    {
        if(AdjMat[node][i] == 1)
        {
            if(isVisited(*visited, i) || isExplored(*explored, i))
            {
                continue;
            }
            else
                enQueue(visited, i);
        }
    }
    return;
}

void printAdjMatrix(MATRIX * temp)
{
    int n = temp -> squareDim;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", temp->matrix[i][j]);
        }
        printf("\n");
    }
}
void BFS_Matrix_Traverse(int row, int col, int **adjmat)
{
    int schoice;
    printf("\nChoose the source node from 1 to %d: ", row);
    scanf("%d", &schoice);
    printf("\n");
    printf("\nExplored vertices in the order of:\n\n");

    QUEUE readyQ;
    readyQ.front = readyQ.rear = -1;
    
    QUEUE explored;
    explored.front = explored.rear = -1;

    enQueue(&explored, schoice-1);
    explore(schoice-1, &readyQ, row, &(*adjmat), &explored);
    

    while(!isQueueEmpty(&readyQ))
    {
        int node = dequeue(&readyQ);
        enQueue(&explored, node);
        explore(node, &readyQ, row, &(*adjmat), &explored);
    }
    return;

}