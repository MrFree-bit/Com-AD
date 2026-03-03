#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void zero_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
}

static void copy_array(int *dest, const int *src, int n) {
    memcpy(dest, src, n * sizeof(int));
}

int KnapsackBT(int *itemWeights, int *itemValues, int itemCount, int capacity, int startIndex, int *bestPick) {
    int bestValue = 0;

    int *bestLocalPick = (int *)calloc(itemCount, sizeof(int));
    if (bestLocalPick == NULL) {
        return 0;
    }

    if (startIndex >= itemCount || capacity <= 0) {
        zero_array(bestPick, itemCount);
        free(bestLocalPick);
        return 0;
    }

    for (int itemIndex = startIndex; itemIndex < itemCount; itemIndex++) {
        if (itemWeights[itemIndex] > capacity) {
            continue;
        }

        int *candidatePick = (int *)calloc(itemCount, sizeof(int));
        if (candidatePick == NULL) {
            continue;
        }

        int remainCapacity = capacity - itemWeights[itemIndex];
        int subValue = KnapsackBT(itemWeights, itemValues, itemCount, remainCapacity, itemIndex + 1, candidatePick);
        int candidateValue = itemValues[itemIndex] + subValue;

        candidatePick[itemIndex] = 1;

        if (candidateValue > bestValue) {
            bestValue = candidateValue;
            copy_array(bestLocalPick, candidatePick, itemCount);
        }

        free(candidatePick);
    }

    copy_array(bestPick, bestLocalPick, itemCount);
    free(bestLocalPick);
    return bestValue;
}

int main() {
    int itemCount = 5;
    int capacity = 11;

    int itemWeights[5] = {1, 2, 5, 6, 7};
    int itemValues[5] = {1, 6, 18, 22, 28};

    int *pick = (int *)calloc(itemCount, sizeof(int));
    if (pick == NULL) {
        return 0;
    }

    int bestValue = KnapsackBT(itemWeights, itemValues, itemCount, capacity, 0, pick);

    printf("Value = %d\n", bestValue);

    for (int i = 0; i < itemCount; i++) {
        printf("%d ", pick[i]);
    }

    free(pick);
    return 0;
}