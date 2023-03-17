#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
#define DROWS 5
#define DCOLS 4

void showMatrix(int[], int, int);
int* createArray(int rows);
int* multiplyMatrix(int a[], int, int, int b[], int, int, int c[], int, int);//c = a * b를 계산하고 c를 return
bool freeMatrix(int[], int);
int main()
{
    srand(time(NULL));
    int* a = createArray(AROWS * ACOLS);
    int* b = createArray(BROWS * BCOLS);
    int* c = createArray(CROWS * CCOLS);
    int* d = createArray(DROWS * DCOLS);
    showMatrix(a, AROWS, ACOLS); showMatrix(b, BROWS, BCOLS);
    bool result;
    result = multiplyMatrix(multiplyMatrix(a, AROWS, ACOLS, b, BROWS, BCOLS, c, CROWS, CCOLS), CROWS, CCOLS, d, DROWS, DCOLS, a, AROWS, ACOLS);
    if (!result)
        printf(" a의 열과 b의 행의 숫자가 달라서 곱셈 계산 안된다");
    showMatrix(c, CROWS, CCOLS);

    freeMatrix(a, AROWS * ACOLS);
    freeMatrix(b, AROWS * ACOLS);
    freeMatrix(c, AROWS * ACOLS);
    system("pause");
    return 1;
}

