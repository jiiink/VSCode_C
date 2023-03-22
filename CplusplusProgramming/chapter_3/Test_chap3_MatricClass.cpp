// matrixMultiplication.cpp - 2���� ����� 1�������� ����, + ���� 
#include <iostream>
using namespace std;
#include <stdlib.h>
#include "time.h"
// ���� ��Ŀ� ���Ͽ�add, sub, mult, transpose �����ϴ� �ڵ�
class Matrix {
public:
	Matrix(int row, int col) { //constructor
		rows = row;
		cols = col;	
	}
	//~Matrix() { delete[]Term; }
	int GetData() {
		Term = (int *)calloc(rows*cols, sizeof(int));

		for (int i=0; i<rows; i++) {
			for (int j=0; j<cols; j++) {
				*(Term + cols * i + j) = rand() % 10;
			}
		}
		return 1;
	}
	Matrix Transpose() {
		Matrix result(cols, rows);
		result.Term = (int *)calloc(cols*rows, sizeof(int));

		for (int i=0; i<rows; i++) {
			for (int j=0; j<cols; j++) {
				*(result.Term + rows*j + i) = *(Term + cols*i + j);
			}
		}
		return result;
	}
	int Display() { // ��� ���: A[rows][cols] ���
		for (int i=0; i<rows; i++) {
			for (int j=0; j<cols; j++) {
				cout << *(Term + cols * i + j) << " ";
			}
			cout << endl;
		}
		return 1;
	}
	Matrix Add(Matrix b) {
		//if (two matrix have same size?)
		Matrix result(rows, cols);
		result.Term = (int *)calloc(rows*cols, sizeof(int));
		for (int i=0; i < rows; i++) {
			for (int j=0; j < cols; j++) {
				*(result.Term+cols*i+j) = *(Term+cols*i+j) + *(b.Term+cols*i+j);
			}
		}
		return result;
	}
	Matrix Multiply(Matrix b) {
		Matrix result(rows, b.cols);
		result.Term = (int *)calloc(rows*result.cols, sizeof(int));
		for (int i=0; i<rows; i++) {
			for (int j=0; j<result.cols; j++) {
				for (int x=0; x<cols; x++) {
					*(result.Term + result.cols*i + j) += *(Term + cols*i + x) * *(b.Term + b.cols*x + j);
				}
			}
		}
		return result;
	}

private:
	int rows, cols;
	//int Term[rows][cols];
	int* Term;// a[i][j] = i * cols + j
};


int main()
{
	Matrix a(2, 3); 
	Matrix a1(2, 3); 
	Matrix a2(2, 3);
	Matrix b(3, 4);
	Matrix c(2, 4);
	srand(time(NULL));
	cout << "matrix a[2][3]�� �Է�: " << endl;
	a.GetData();
	cout << "a" << endl;
	a.Display();
	//cout << a.rows;//can't access private //in C  printf("%d", a.rows); // cout : ��°�ü 
	
	cout << "matrix a1[2][3]�� �Է�: " << endl;
	a1.GetData();
	a1.Display();

	a2 = a.Add(a1);
	cout << "a2 = a + a1" << endl;
	a2.Display();

	cout << "matrix b[3][4]�� �Է�: " << endl;
	b.GetData();
	b.Display();

	Matrix d(4, 3);
	d = b.Transpose();
	cout << "Transpose() of Matrix b" << endl;
	d.Display();

	cout << "Multiply of Matrix a,b" << endl;
	c = a.Multiply(b);
	c.Display();
	
	system("pause");
	return 0;
}

