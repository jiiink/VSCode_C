#include <stdio.h>

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

//int getMatrix(int[], int);//난수 생성하여 처리 - pointer만 사용하여 구현
void showMatrix(int[], int, int);

bool multiplyMatrix(int a[], int, int, int b[], int, int, int c[], int, int);//c = a * b를 계산하고 c를 return
//bool freeMatrix(int[], int, int);
int main()
{
    srand(time(NULL));

    int a[] = { 1,0,1,0,
                1,0,1,1,
                1,0,0,1 };

    int b[] = { 1,1,1,1,0,
                0,0,0,1,1,
                1,1,0,0,0,
                0,1,1,1,1 };

    int c[15] = { 0 };
    showMatrix(a, AROWS, ACOLS); showMatrix(b, BROWS, BCOLS);
    bool result;
    result = multiplyMatrix(a, AROWS, ACOLS, b, BROWS, BCOLS, c, CROWS, CCOLS);
    if (!result)
        printf(" a의 열과 b의 행의 숫자가 달라서 곱셈 계산 안된다");
    showMatrix(c, CROWS, CCOLS);

    //freeMatrix(c, CROWS, CCOLS);
    system("pause");
    return 1;
}

void showMatrix(int* a, int r, int c) {
    printf(" matrix row = %d, col = %d\n", r, c);
    for (int i = 0; i < r; i++)
    {
    //행렬 출력 구현
        for (int j = 0; j < c; j++) {
            printf("%d ", *(a + i + j));
        }
        printf("\n");
    }
}
bool multiplyMatrix(int a[], int ar, int ac, int b[], int br, int bc, int c[], int cr, int cc) {
    if (ac != br)return false;
    
    for (int x = 0; x < cr; x++) {
        for (int y = 0; y < cc; y++) {
    //행렬 곱셈 구현
            for (int i = 0 ; i < ar; i++) {
                *(c+x+y) += *(a + x + i) * *(b + i + x);
            }
        }
    }
}