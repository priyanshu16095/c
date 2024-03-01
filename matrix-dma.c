#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int rows, int cols) {
    int** arr = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter the element at index [%d][%d]: ", i,j);
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }
    return arr;
}

void printMatrix(int** arr, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of cols: ");
    scanf("%d", &cols);
    int** arr = createMatrix(rows, cols);
    printMatrix(arr, rows, cols);
}
