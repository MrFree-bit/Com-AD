#include <stdio.h>
#include <stdlib.h>

int *GetSet(int *sizePtr) {
    int total;
    printf("Enter number of items: ");
    scanf("%d", &total);

    int *bucket = malloc(total * sizeof(int));
    for (int i = 0; i < total; i++) {
        printf("Enter int only %d: ", i + 1);
        scanf("%d", &bucket[i]);
    }
    *sizePtr = total;
    return bucket;
}
int main() {
    int *data, num;
    data = GetSet(&num);
    for (int i = 0; i < num; i++) {
        printf("result %d = %d ", i+1, data[i]);
    }   
    return 0;
}
