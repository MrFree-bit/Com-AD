#include <stdio.h>
#include <stdlib.h>

int* GetMatrix(int *row, int *col) {
    printf("Enter number of rows: ");
    scanf("%d", row);
    printf("Enter number of columns: ");
    scanf("%d", col);
    int *matrix = (int *)malloc((*row) * (*col) * sizeof(int));
    printf("\nEnter int only:\n");
    for(int i = 0; i < *row; i++) {
        for(int j = 0; j < *col; j++) {
            printf("location [%d][%d]: ", i, j);
            scanf("%d", &matrix[i * (*col) + j]);
        }
    }
    return matrix;
}
int main() {
    int *data, m, n;
    data = GetMatrix(&m, &n);
    printf("row: %d\n", m);
    printf("column: %d\n", n);
    printf("\nInput int:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", data[i * n + j]);
        }
        printf("\n");
    }
    free(data);
    return 0;
}