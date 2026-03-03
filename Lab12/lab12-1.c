#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *Dijkstra(int *graph, int nodeCount);

int main()
{
    int nodeCount = 5;
    int row, col;

    int *graph = (int *)malloc(nodeCount * nodeCount * sizeof(int));

    for (row = 0; row < nodeCount; row++)
    {
        for (col = 0; col < nodeCount; col++)
        {
            graph[row * nodeCount + col] = -1;
        }
    }

    graph[0 * nodeCount + 1] = 100;
    graph[0 * nodeCount + 2] = 80;
    graph[0 * nodeCount + 3] = 30;
    graph[0 * nodeCount + 4] = 10;

    graph[1 * nodeCount + 2] = 25;
    graph[3 * nodeCount + 1] = 20;
    graph[3 * nodeCount + 2] = 40;
    graph[4 * nodeCount + 3] = 10;

    int *distance = Dijkstra(graph, nodeCount);

    for (row = 0; row < nodeCount - 1; row++)
    {
        if (row > 0)
        {
            printf(" ");
        }
        printf("%d", distance[row]);
    }

    free(distance);
    free(graph);

    return 0;
}

int *Dijkstra(int *graph, int nodeCount)
{
    int *distance = (int *)malloc((nodeCount - 1) * sizeof(int));
    int *visited  = (int *)malloc(nodeCount * sizeof(int));

    int i, iteration;

    for (i = 0; i < nodeCount; i++)
    {
        visited[i] = 0;
    }

    for (i = 1; i < nodeCount; i++)
    {
        distance[i - 1] = graph[0 * nodeCount + i];
    }

    visited[0] = 1;

    for (iteration = 0; iteration < nodeCount - 2; iteration++)
    {
        int currentNode = -1;
        int minimumDistance = INT_MAX;

        for (i = 1; i < nodeCount; i++)
        {
            if (!visited[i] &&
                distance[i - 1] != -1 &&
                distance[i - 1] < minimumDistance)
            {
                minimumDistance = distance[i - 1];
                currentNode = i;
            }
        }

        if (currentNode == -1)
        {
            break;
        }

        visited[currentNode] = 1;

        for (i = 1; i < nodeCount; i++)
        {
            if (!visited[i] &&
                graph[currentNode * nodeCount + i] != -1 &&
                distance[currentNode - 1] != -1)
            {
                int candidate =
                    distance[currentNode - 1] +
                    graph[currentNode * nodeCount + i];

                if (distance[i - 1] == -1 ||
                    candidate < distance[i - 1])
                {
                    distance[i - 1] = candidate;
                }
            }
        }
    }

    free(visited);
    return distance;
}