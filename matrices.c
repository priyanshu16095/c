#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int rows, int cols) {
    int** arr = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter the value at index [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
    return arr;
}

int** allocateSpace(int rows, int cols) {
    int** arr = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }
    if(arr == NULL) {
        printf("MEMORY ALLOCATION FAILED");
        return NULL;
    }
    return arr;
}

int** addMatrices(int** arr1, int** arr2, int rows, int cols) {
    int** arr = allocateSpace(rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return arr;
}

int** substractMatrices(int** arr1, int** arr2, int rows, int cols) {
    int** arr = allocateSpace(rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    return arr;
}

int** multiplyMatrix(int** arr1, int rows1, int cols1, int** arr2, int rows2, int cols2) {
    if(cols1 != rows2) {
        printf("Matrix multiplication not possible");
        return NULL;
    }
    int** arr = allocateSpace(cols1, rows2);
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            arr[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                arr[i][j] = arr1[i][k] * arr2[k][j];
            }
        }
    }
    return arr;
}

void transpose(int** arr, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = arr[j][i];
        }
    }
}

void displayMatrix(int** arr, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int rows = 3;
    int cols = 3;
    
    // int** arr1 = createMatrix(rows, cols);
    // int** arr2 = createMatrix(rows, cols);
    
    // int** sumMatrix = addMatrices(arr1, arr2, rows, cols);
    // displayMatrix(sumMatrix, rows, cols);
    
    // int** diffMatrix = substractMatrices(arr1, arr2, rows, cols);
    // displayMatrix(diffMatrix, rows, cols);
    
    // int** mulMatrix = multiplyMatrix(arr1, rows, cols, arr2, rows, cols);
    // displayMatrix(mulMatrix, rows, cols);
    
    int** arr = createMatrix(rows, cols);
    displayMatrix(arr, rows, cols);
    transpose(arr, rows, cols);
    displayMatrix(arr, rows, cols);
}

















