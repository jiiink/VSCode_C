/*Matrix addition about 2 dimential
C++ 2nd assignment, get data, add, multiply 2dimential by using 1dimential array
1. getMatrix(row, col) allocate row x col memory, put random value
2. add(a, b) //a = a + b
3. multiply(a, b, c) //c = a x b
*/
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#define MaxCounts 30
#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
#define DROWS 3
#define DCOLS 5
//int getMatrix(int[], int);//take with random - only use pointer
bool showMatrix(int*, int, int);
int * addMatrix(int *, int, int, int *, int, int);//a = a + b, return a
int * getMatrix(int, int);
int * multiplyMatrix(int *, int, int, int*, int, int,int *, int, int);//c = a * b, return c
bool freeMatrix(int *, int, int);
int main()
{
    srand(time(NULL));
  
    int* a, * a1, * a2, * a3, * b, * c, * d;

    a = getMatrix(AROWS, ACOLS); 
    a1 = getMatrix(AROWS, ACOLS); 
    a2 = getMatrix(AROWS, ACOLS);
    showMatrix(a, AROWS, ACOLS); 
    showMatrix(a1, AROWS, ACOLS);
    showMatrix(a2, AROWS, ACOLS);
    
    a3 = addMatrix(addMatrix(a, AROWS, ACOLS, a1, AROWS, ACOLS),AROWS, ACOLS, a2, AROWS, ACOLS);
    showMatrix(a3, AROWS, ACOLS);
    
    b = getMatrix(BROWS, BCOLS);
    showMatrix(b, BROWS, BCOLS);

    c = getMatrix(CROWS, CCOLS);
    showMatrix(c, CROWS, CCOLS);

    d = multiplyMatrix(a, AROWS, ACOLS, b, BROWS, BCOLS, c, CROWS, CCOLS);
    showMatrix(c, CROWS, CCOLS);
    showMatrix(d, DROWS, DCOLS);

    freeMatrix(a, AROWS, ACOLS); 
    freeMatrix(a1, AROWS, ACOLS); 
    freeMatrix(a2, AROWS, ACOLS);
    freeMatrix(b, BROWS, BCOLS); 
    freeMatrix(c, CROWS, CCOLS);
    
    system("pause");
    return 1;
}

int * getMatrix(int rows, int cols) { 
    int* arr = (int*)calloc(rows * cols, sizeof(int));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(arr + cols * i + j) = rand() % 10;
        }
    }
    return arr;
}

bool showMatrix(int *arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(arr + cols * i + j));
        }
        printf("\n");
    }
    printf("\n");

    return true;
}

int* addMatrix(int *arr1, int row1, int col1, int *arr2, int row2,  int col2) {//a = a + b, return a
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            *(arr1 + col1 * i + j) = *(arr1 + col1 * i + j) + *(arr2 + col2 * i + j);
        }
    }
    return arr1;
}

int* multiplyMatrix(int *arr1, int row1, int col1, int *arr2, int row2, int col2, int *arr3, int row3, int col3) {//c = a * b, return c
    for (int i = 0; i < (row3*col3); i++) {//initialize all item of arr3 to 0
        *(arr3 + i) = 0;
    }

    for (int x = 0; x < row3; x++) { //matrix multiply
        for (int y = 0; y < col3; y++) {
            for (int i = 0; i < col1; i++) {
                *(arr3 + col3 * x + y) += *(arr1 + col1 * x + i) * *(arr2 + col2 * i + y);
            }
        }
    }

    return arr3;
}

bool freeMatrix(int *arr, int row, int col) {
    free(arr);

    return true;
}