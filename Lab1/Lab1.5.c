#include <stdio.h>
#include <stdlib.h>

void GetMatrix(int rawPtr[], int *rows, int *cols) {
    int r, c;
    printf("Enter number of rows and columns \n");
    printf("Enter number of rows : ");
    scanf("%d", &r);
    printf("Enter number of columns : ");
    scanf("%d", &c);
    int total = r * c;
    int *matrixBox = malloc(total * sizeof(int));
    for (int i = 0; i < total; i++) {
        printf("Enter int only %d: ", i + 1);
        scanf("%d", &matrixBox[i]);
    }
    *((int **)rawPtr) = matrixBox;
    *rows = r;
    *cols = c;
}
int main() {
    int *data, m, n, num;
    GetMatrix((int *)&data, &m, &n);
    for (int i = 0; i < num; i++) {
        printf("result %d = %d ", i+1, data[i]);
    }   
    return 0;
}
