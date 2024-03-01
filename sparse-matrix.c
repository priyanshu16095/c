#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int rows, int cols) {
    int** arr = (int**)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter the element at index [%d][%d]: ", i,j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
    return arr;
}

void printMatrix(int** arr, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int countElement(int** arr, int rows, int cols, int element) {
    int count;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(arr[i][j] == element) {
                count++;
            }
        }
    }
    return count;
}

int** createCompactMatrixMatrix(int** arr, int rows, int cols, int nonZeroCount) {
    int** c = (int**)malloc(3 * sizeof(int*));
    for(int i = 0; i < 3; i++) {
        c[i] = (int*)malloc(nonZeroCount * sizeof(int));
    }
    int k = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(arr[i][j] != 0) {
                c[0][k] = i;
                c[1][k] = j;
                c[2][k] = arr[i][j];
                k++;
            }
        }
    }
    return c;
}

int main() {
    int rows = 3;
    int cols = 3;
    
    int** arr = createMatrix(rows, cols);
    printMatrix(arr, rows, cols);
    
    int zeroCount = countElement(arr, rows, cols, 0);
    int nonZeroCount = rows*cols - zeroCount;
    
    int** compact = createCompactMatrixMatrix(arr, rows, cols, nonZeroCount);
    printMatrix(compact, 3, nonZeroCount);
}

