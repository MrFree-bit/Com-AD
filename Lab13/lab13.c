#include <stdio.h>
#include <stdlib.h>

int *KnapsackDP(int *weights, int *values, int itemCount, int capacity);
void buildDPTable(int **dp, unsigned char **choice,
                  int *weights, int *values,
                  int itemCount, int capacity);
void reconstructSolution(int *result,
                         unsigned char **choice,
                         int *weights,
                         int itemCount,
                         int capacity);

int main()
{
    int itemCount = 5;
    int capacity = 11;

    int weights[5] = {1, 2, 5, 6, 7};
    int values[5]  = {1, 6, 18, 22, 28};

    int *result;

    result = KnapsackDP(weights, values, itemCount, capacity);

    for (int index = 0; index < itemCount; index++)
    {
        printf("%d ", result[index]);
    }

    free(result);
    return 0;
}

int *KnapsackDP(int *weights, int *values, int itemCount, int capacity)
{
    int **dpTable;
    unsigned char **choiceTable;
    int *result;

    dpTable = (int **)malloc(itemCount * sizeof(int *));
    choiceTable = (unsigned char **)malloc(itemCount * sizeof(unsigned char *));

    for (int row = 0; row < itemCount; row++)
    {
        dpTable[row] = (int *)calloc(capacity + 1, sizeof(int));
        choiceTable[row] = (unsigned char *)calloc(capacity + 1, sizeof(unsigned char));
    }

    buildDPTable(dpTable, choiceTable, weights, values, itemCount, capacity);

    result = (int *)calloc(itemCount, sizeof(int));
    reconstructSolution(result, choiceTable, weights, itemCount, capacity);

    for (int row = 0; row < itemCount; row++)
    {
        free(dpTable[row]);
        free(choiceTable[row]);
    }

    free(dpTable);
    free(choiceTable);

    return result;
}


void buildDPTable(int **dpTable, unsigned char **choiceTable,
                  int *weights, int *values,
                  int itemCount, int capacity)
{
    for (int item = 0; item < itemCount; item++)
    {
        for (int currentCap = 0; currentCap <= capacity; currentCap++)
        {
            int valueExclude = 0;
            int valueInclude = -1;

            if (item > 0)
            {
                valueExclude = dpTable[item - 1][currentCap];
            }

            if (weights[item] <= currentCap)
            {
                if (item == 0)
                {
                    valueInclude = values[item];
                }
                else
                {
                    valueInclude =
                        dpTable[item - 1][currentCap - weights[item]] +
                        values[item];
                }
            }

            if (valueInclude > valueExclude)
            {
                dpTable[item][currentCap] = valueInclude;
                choiceTable[item][currentCap] = 1;
            }
            else
            {
                dpTable[item][currentCap] = valueExclude;
                choiceTable[item][currentCap] = 0;
            }
        }
    }
}

void reconstructSolution(int *result,
                         unsigned char **choiceTable,
                         int *weights,
                         int itemCount,
                         int capacity)
{
    int remainingCap = capacity;

    for (int item = itemCount - 1; item >= 0; item--)
    {
        if (choiceTable[item][remainingCap] == 1)
        {
            result[item] = 1;
            remainingCap -= weights[item];
        }
        else
        {
            result[item] = 0;
        }
    }
}