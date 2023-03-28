// matrixMultiplication.cpp - 2차원 행렬을 1차원으로 저장, + 구현 
#include <iostream>
using namespace std;
#include <stdlib.h>
#include "time.h"
// 보통 행렬에 대하여add, sub, mult, transpose 구현하는 코딩
class Matrix {
private:
	int rows, cols;
	//int Term[rows][cols];
	int* Term;// a[i][j] = i * cols + j
public:
	Matrix(int, int); //constructor
	//~Matrix() { delete[]Term; } //destructor
	int GetData();
	Matrix Transpose();
	int Display();
	Matrix Add(Matrix b);
	Matrix Multiply(Matrix b);
};

Matrix::Matrix(int row, int col) { //constructor
		this->rows = row;
		this->cols = col;	
}

int Matrix::GetData() {
		this->Term = (int *)calloc(this->rows*this->cols, sizeof(int)); // can we change the 'calloc' to the 'new'?
		//this->Term = new (int *)[this->rows*this->cols];
		for (int i=0; i<this->rows; i++) {
			for (int j=0; j<this->cols; j++) {
				*(this->Term + this->cols * i + j) = rand() % 10;
			}
		}
		return 1;
}

Matrix Matrix::Transpose() {
		Matrix result(this->cols, this->rows);
		result.Term = (int *)calloc(this->cols*this->rows, sizeof(int));

		for (int i=0; i<this->rows; i++) {
			for (int j=0; j<this->cols; j++) {
				*(result.Term + result.cols*j + i) = *(this->Term + this->cols*i + j);
			}
		}
		return result;
}

int Matrix::Display() { // 행렬 모양: A[rows][cols] 출력
		for (int i=0; i<this->rows; i++) {
			for (int j=0; j<this->cols; j++) {
				cout << *(this->Term + this->cols * i + j) << " ";
			}
			cout << endl;
		}
		return 1;
}

Matrix Matrix::Add(Matrix b) { //, Matrix s3) {//was the "result" deleted? when this function is ended?
		//if (two matrix have same size?)
		Matrix result(this->rows, this->cols);
		result.Term = (int *)calloc(this->rows*this->cols, sizeof(int));
		for (int i=0; i < this->rows; i++) {
			for (int j=0; j < this->cols; j++) {
				*(result.Term+this->cols*i+j) = *(this->Term+this->cols*i+j) + *(b.Term+this->cols*i+j);
			}
		}
		return result;
}

Matrix Matrix::Multiply(Matrix b) {
		// if (check the size of matrices)
		Matrix result(this->rows, b.cols);
		result.Term = (int *)calloc(this->rows*result.cols, sizeof(int));
		for (int i=0; i<result.rows; i++) {
			for (int j=0; j<result.cols; j++) {
				for (int x=0; x<this->cols; x++) {
					*(result.Term + result.cols*i + j) += *(this->Term + this->cols*i + x) * *(b.Term + b.cols*x + j);
				}
			}
		}
		return result;
}

int main() {
	{
	Matrix a(2, 3); 
	Matrix a1(2, 3); 
	Matrix a2(2, 3);
	Matrix b(3, 4);
	Matrix c(2, 4);
	srand(time(NULL));
	cout << "matrix a[2][3]의 입력: " << endl;
	a.GetData();
	cout << "a" << endl;
	a.Display();
	//cout << a.rows;//can't access private //in C  printf("%d", a.rows); // cout : 출력객체 
	
	cout << "matrix a1[2][3]의 입력: " << endl;
	a1.GetData();
	a1.Display();

	a2 = a.Add(a1);
	cout << "a2 = a + a1" << endl;
	a2.Display();

	cout << "matrix b[3][4]의 입력: " << endl;
	b.GetData();
	b.Display();
	
	Matrix d(4, 3);
	d = b.Transpose();
	cout << "Transpose() of Matrix b" << endl;
	d.Display();

	cout << "Multiply of Matrix a,b" << endl;
	c = a.Multiply(b);
	c.Display();
	}
	system("pause");
	return 0;
}

