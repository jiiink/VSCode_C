#include <iostream>
//º¹¼Ò¼ö¿¡ ´ëÇÑ »çÄ¢¿¬»êÀÌ °¡´ÉÇÏµµ·Ï ±¸ÇöÇÑ´Ù. main() ÇÔ¼ö´Â ¼öÁ¤ÇÏ¸é ¾ÈµÈ´Ù ±¸±Û¸µÇØº¸ÀÚ~
using namespace std;

class ComplexNumber {
private:
	float real; //½Ç¼ö
	float imaginary; //Çã¼ö
public:
	ComplexNumber(float real, float imaginary): real(real), imaginary(imaginary) { //instead of this->real = real; 
		//this->real = real;
		//this->imaginary = imaginary;
	}
	ComplexNumber& operator+(const ComplexNumber&);
	friend ComplexNumber operator+(const ComplexNumber&, const ComplexNumber&); //operator_overloading
	friend ostream& operator<<(ostream& stream, const ComplexNumber& p);
	ComplexNumber add(const ComplexNumber&);
	ComplexNumber subtract(const ComplexNumber&);
	ComplexNumber multiply(const ComplexNumber&);
	ComplexNumber divide(const ComplexNumber&);

	
};
ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b) { //operator_overloading
	ComplexNumber cn(0, 0);
	
	cn.real = a.real + b.real;
	cn.imaginary = a.imaginary + b.imaginary;

	return cn;
	//return *a;
	//return &a;
}

ostream& operator<<(ostream& stream, const ComplexNumber& p) {
	if (p.real != 0 && p.imaginary != 0) stream << p.real << " + " << p.imaginary << "i";
	else if (p.real != 0 && p.imaginary == 0) stream << p.real;
	else if (p.real == 0 && p.imaginary != 0) stream << p.imaginary << "i";
	else stream << p.real;

	return stream;
}

//ComplexNumber add(const ComplexNumber &b) {} //ÀÌ·¨À» ¶§ ¾È µÇ´Â °Å È®ÀÎ
ComplexNumber ComplexNumber::add(const ComplexNumber &b) { //how to return class?
	ComplexNumber cn(0, 0);

	cn.real = this->real + b.real;
	cn.imaginary = this->imaginary + b.imaginary;

	return cn;                        
}

ComplexNumber ComplexNumber::subtract(const ComplexNumber& b) {
	ComplexNumber cn(0, 0);

	cn.real = this->real - b.real;
	cn.imaginary = this->imaginary - b.imaginary;

	return cn;
}

ComplexNumber ComplexNumber::multiply(const ComplexNumber& b) {
	ComplexNumber cn(0, 0);

	cn.real = this->real * b.real - (this->imaginary * b.imaginary);
	cn.imaginary = (this->real * b.imaginary) + (this->imaginary * b.real);

	return cn;
}

ComplexNumber ComplexNumber::divide(const ComplexNumber& b) {
	ComplexNumber cn(0, 0);
	ComplexNumber b_(b.real, -b.imaginary);
	ComplexNumber son(0, 0);
	ComplexNumber result(0, 0);

	float mother = b.real * b.real - (b.imaginary * -b.imaginary);
	son = this->multiply(b_);
	//cout << "son : " << son << endl;

	result.real = son.real / mother;
	result.imaginary = son.imaginary / mother;

	// cn.real = this->real * b.real - (this->imaginary * b.imaginary);
	// cn.imaginary = (this->real * b.imaginary) + (this->imaginary * b.real);

	return result;
}

int main(void) {//mainÀº ¼öÁ¤ÇÒ °Í ¾øÀ½
	while (1)
	{
		ComplexNumber a(1, 1), b(2, 2), c(3, 3), d(4, 4);
		int select;	
		cout << "\nSelect command 1: µ¡¼À, 2: »¬¼À, 3. °ö¼À, 4: ³ª´°¼À, 5. ¿¬¼âµ¡¼À, 6. quit => ";
		cin >> select;
		switch (select) {
		case 1:
			cout << endl << "µ¡¼À d = a + b + c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.add(b.add(c));
			cout << "d = " << d << endl;
			break;
		case 2:
			cout << endl << "»¬¼À d = a - b - c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			// d = a.subtract(b.subtract(c));
			d = (a.subtract(b)).subtract(c);
			cout << "d = " << d << endl;
			break;

		case 3:
			cout << endl << "°ö¼À d = a * b * c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.multiply(b.multiply(c));
			cout << "d = " << d << endl;
			//e = a - b - c - d;
			break;
		case 4:
			cout << endl << "³ª´°¼À d = a / b / c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			// d = a.divide(b.divide(c));
			d = a.divide(b);
			cout << "d = " << d << endl;
			// cout << a;
			break;
		case 5:
			cout << endl << "cascading µ¡¼À d = a + b + c" << endl;
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