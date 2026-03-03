#include <stdio.h>
#include <stdlib.h>

int *KnapsackGreedy(int *weights, int *values, int itemCount, int capacity);
int findBestItem(int *weights, int *values, int *isUsed, int itemCount);

int main()
{
    int itemCount = 5;
    int capacity = 11;

    int weights[5] = {1, 2, 5, 6, 7};
    int values[5]  = {1, 6, 18, 22, 28};

    int *result = KnapsackGreedy(weights, values, itemCount, capacity);

    for (int index = 0; index < itemCount; index++)
    {
        printf("%d ", result[index]);
    }

    free(result);
    return 0;
}

int *KnapsackGreedy(int *weights, int *values, int itemCount, int capacity)
{
    int *selected = (int *)malloc(itemCount * sizeof(int));
    int *isUsed   = (int *)malloc(itemCount * sizeof(int));

    int currentWeight = 0;

    for (int i = 0; i < itemCount; i++)
    {
        selected[i] = 0;
        isUsed[i]   = 0;
    }

    while (1)
    {
        int bestIndex = findBestItem(weights, values, isUsed, itemCount);

        if (bestIndex == -1)
        {
            break;
        }

        isUsed[bestIndex] = 1;

        if (currentWeight + weights[bestIndex] <= capacity)
        {
            selected[bestIndex] = 1;
            currentWeight += weights[bestIndex];
        }
    }

    free(isUsed);
    return selected;
}

int findBestItem(int *weights, int *values, int *isUsed, int itemCount)
{
    int bestIndex = -1;
    double bestRatio = -1.0;

    for (int i = 0; i < itemCount; i++)
    {
        if (isUsed[i] == 0)
        {
            double ratio = (double)values[i] / (double)weights[i];

            if (ratio > bestRatio)
            {
                bestRatio = ratio;
                bestIndex = i;
            }
        }
    }

    return bestIndex;
}