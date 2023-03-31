#include <iostream>
//���Ҽ��� ���� ��Ģ������ �����ϵ��� �����Ѵ�. main() �Լ��� �����ϸ� �ȵȴ� ���۸��غ���~
using namespace std;
class ComplexNumber {
private:
	float real; //�Ǽ�
	float imaginary; //���
public:
	//�ڵ�
	
	ComplexNumber(float real, float imaginary): real(real), imaginary(imaginary) { //instead of this->real = real; 
		//this->real = real;
		//this->imaginary = imaginary;
	}
	//ComplexNumber& operator+(const ComplexNumber&);
	friend ComplexNumber& operator+(const ComplexNumber&, const ComplexNumber&);
	ComplexNumber add(const ComplexNumber);

	friend ostream& operator<<(ostream& stream, const ComplexNumber& p);

	
};
ComplexNumber& operator+(const ComplexNumber&a, const ComplexNumber&b) {
	a.real += b.real;
	a.imaginary += b.imaginary;

	return a;
	//return *a;
	//return &a;
}

ostream& operator<<(ostream& stream, const ComplexNumber& p) {
	stream << p.real << " + " << p.imaginary << "i";
	return stream;
}

//ComplexNumber add(const ComplexNumber &b) {} �̷��� �� �� �Ǵ� �� Ȯ��
ComplexNumber& ComplexNumber::add(const ComplexNumber &b) {
	ComplexNumber cn;

	return cn;                        
}

int main(void) {//main�� ������ �� ����
	while (1)
	{
		ComplexNumber a(1, 1), b(2, 2), c(3, 3), d(4, 4);
		int select;	
		cout << "\nSelect command 1: ����, 2: ����, 3. ����, 4: ������, 5. ���ⵡ��, 6. quit => ";
		cin >> select;
		switch (select) {
		case 1:
			cout << endl << "���� d = a + b + c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.add(b.add(c));
			cout << "d = " << d << endl;
			break;
		case 2:
			cout << endl << "���� d = a - b - c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.subtract(b.subtract(c));
			cout << "d = " << d << endl;
			break;

		case 3:
			cout << endl << "���� d = a * b * c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.multiply(b.multiply(c));
			cout << "d = " << d << endl;
			//e = a - b - c - d;
			break;
		case 4:
			cout << endl << "������ d = a / b / c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.divide(b.divide(c));
			cout << "d = " << d << endl;
			cout << a;
			break;
		case 5:
			cout << endl << "cascading ���� d = a + b + c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a + b + c;//operator_overloading
			cout << "d = " << d << endl;
			break;
		default:
			exit(0);
			break;
		}
	}
	system("pause");
	return 1;
}