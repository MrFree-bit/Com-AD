#include <stdio.h>
#include <stdlib.h>

int GetSet(int holder[]) {
    int amount;
    printf("Enter number of items: ");
    scanf("%d", &amount);
    int *slot = malloc(amount * sizeof(int));
    for (int i = 0; i < amount; i++) {
        printf("Enter int only %d: ", i + 1);
        scanf("%d", &slot[i]);
    }
    *((int **)holder) = slot;
    return amount;
}
int main() {
    int *data, num;
    num = GetSet(&data);
    for (int i = 0; i < num; i++) {
        printf("result %d = %d ", i+1, data[i]);
    }   
    return 0;
}