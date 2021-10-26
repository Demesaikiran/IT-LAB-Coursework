#include <stdlib.h>
#include "getValues.h"
#include "bfs_list.h"

ADJMat * readAdjList(char * filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if(!fp)
    {
        printf("ERROR IN OPENING FILE %s", filename);
        exit(1);
    }

    int nOfEdges;
    ADJMat *list = malloc(sizeof(ADJMat));

    //Reading nOfVertices
    if(fscanf(fp, "%d", &(list -> nOfVertices)) != 1)
        exit(1);
    int a, b;
    int i =0;
    while((fscanf(fp, "%d%d", &a, &b) != EOF))
    {
        list -> array[i][0] = a-1;
        list -> array[i][1] = b-1;
        i++;
        (list -> nOfEdges)++;
    }

    list -> array[i][0] = list -> array[i][1] = -1;
    // We got Adjacency list copy here.
    fclose(fp);
    return list;
}

MATRIX * convertAdjListToMatrix(ADJMat * list)
{
    int n = list -> nOfVertices;
    printf("\nNo of vertices = %d\n", n);
    MATRIX * admat = malloc(sizeof(MATRIX));
    admat -> matrix = malloc(n * sizeof(int *));

    for(int i =0; i < n; i++)
        admat -> matrix[i]= malloc(n * sizeof(int));

    // Till now we allocated the memory to the adjacency matrix
    // Its time to keep the edge values in the matrix...
    // We need to keep 1's to the both indices of matrix
    // Reason is Undirected graph
    for(int i = 0; list -> array[i][0] != -1; i++)
    {
        int source = list -> array[i][0];
        int dest   = list -> array[i][1];

        admat -> matrix[source][dest] = 1;
        admat -> matrix[dest][source] = 1;
    }
    admat -> squareDim = n;

    return admat;
}

MATRIX * readADJMatrix(char * filename)
{
    ADJMat *list = readAdjList(filename);

    return convertAdjListToMatrix(list);
}