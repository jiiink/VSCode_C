//2차원 행렬 덧셈, 곱셈
//chatbot GPT 사용해도 결과 안나옴
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
#define DROWS 3
#define DCOLS 6
int getData(int[][], int);// 구현 가능하게 수정 필요 - 2개 이상 구현해도 된다
int show(int[][], int);// 구현 가능하게 수정 필요 - 2개 이상 구현해도 된다
int[][] add(int[][], int, int[][], int);// 구현 가능하게 수정 필요
int[][] multiply(int[][], int, int[][], int);// 구현 가능하게 수정 필요

//hello?
//is that work?
int main()
{
    srand(time(NULL));
    int a[AROWS][ACOLS];
    int a1[AROWS][ACOLS];
    int a2[AROWS][ACOLS];
    int a3[AROWS][ACOLS];
    int b[BROWS][BCOLS];
    int c[CROWS][CCOLS];
    int d[CROWS][CCOLS];
    getData(a, AROWS);//난수를 사용하여 입력
    getData(a1, AROWS);//난수를 사용하여 입력
    getData(b, BROWS);//난수를 사용하여 입력
    show(a, AROWS);  show(a1, AROWS); show(a2, AROWS); show(b, AROWS);
    a2 = add(a, AROWS, a1, AROWS);
    show(a2, AROWS);
    a3 = add(add(a, AROWS, a1, AROWS), a2, AROWS);
    show(a3, AROWS);
    c = multiply(a, AROWS, b, BROWS);
    show(c, AROWS);
    d = multiply(multiply(a, AROWS, b, BROWS), c, CROWS));
    show(d, DROWS);
    system("pause");
    return 1;
}