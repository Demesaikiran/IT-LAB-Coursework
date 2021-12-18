#include<stdio.h>
#include<stdlib.h>
#include "bfs.h"
#include "getValues.h"
#include<time.h>
#include <math.h>


clock_t start, end;
double cpu_time_used;

int main(int argc, char ** argv)
{
    // Dealing with Adjacency matrix
    if(argv[2][0] == '1')
    {
        int row, col;
        MATRIX * admat = readADJMatrix(argv[1]);
        int dimension = admat -> squareDim;
        row = col = dimension;
        printf("\nADJACENCY MATRIX\n=================\n");
        printAdjMatrix(admat);

        start = clock();
        BFS_Matrix_Traverse(row, col, admat ->matrix);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("\n\nTime taken in Adjacency matrix BFS: %lf", cpu_time_used);

        printf("\n\nThe time complexity of adjacency of adjacency matrix BFS is O(n^2)\n");
        printf("\n\nEND OF BFS FOR ADJACENCY MATRIX\n\n");
    }

    // Dealing with Adjacency list
    else if(argv[2][0] == '2')
    {
        ADJMat * list = readAdjList(argv[1]);
        printf("\nChoose the source node from 1 to %d: ", list -> nOfVertices);
        int choiceNode;
        scanf("%d", &choiceNode);

        start = clock();
        BFS_List_Traverse(list, choiceNode, list -> nOfEdges);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("\n\nTime taken in Adjacency matrix BFS: %lf", cpu_time_used);

        printf("\nThe time complexity of adjacency list BFS is O(|V| + |E|)\n");
        printf("\nEND OF BFS FOR ADJACENCY LIST\n\n");
        
    }
    
}