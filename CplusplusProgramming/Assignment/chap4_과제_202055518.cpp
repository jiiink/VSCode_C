#include <iostream>
//º¹¼Ò¼ö¿¡ ´ëÇÑ »çÄ¢¿¬»êÀÌ °¡´ÉÇÏµµ·Ï ±¸ÇöÇÑ´Ù. main() ÇÔ¼ö´Â ¼öÁ¤ÇÏ¸é ¾ÈµÈ´Ù ±¸±Û¸µÇØº¸ÀÚ~
using namespace std;

class ComplexNumber {
private:
	float real; //½Ç¼ö
	float imaginary; //Çã¼ö
public:
	ComplexNumber(float real, float imaginary): real(real), imaginary(imaginary) {}
	ComplexNumber() { real = 0; imaginary = 0; }
	friend ComplexNumber operator+(const ComplexNumber&, const ComplexNumber&);
	friend ostream& operator<<(ostream& stream, const ComplexNumber& p);
	ComplexNumber add(const ComplexNumber&);
	ComplexNumber subtract(const ComplexNumber&);
	ComplexNumber multiply(const ComplexNumber&);
	ComplexNumber divide(const ComplexNumber&);
};

ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b) {
	ComplexNumber res;
	
	res.real = a.real + b.real;
	res.imaginary = a.imaginary + b.imaginary;

	return res;
}

ostream& operator<<(ostream& stream, const ComplexNumber& p) {
	if (p.real != 0 && p.imaginary != 0) stream << p.real << " + " << p.imaginary << "i";
	else if (p.real != 0 && p.imaginary == 0) stream << p.real;
	else if (p.real == 0 && p.imaginary != 0) stream << p.imaginary << "i";
	else stream << p.real;

	return stream;
}

ComplexNumber ComplexNumber::add(const ComplexNumber &object) {
	ComplexNumber result;

	result.real = this->real + object.real;
	result.imaginary = this->imaginary + object.imaginary;

	return result;
}

ComplexNumber ComplexNumber::subtract(const ComplexNumber& object) {
	ComplexNumber result;

	result.real = this->real - object.real;
	result.imaginary = this->imaginary - object.imaginary;

	return result;
}

ComplexNumber ComplexNumber::multiply(const ComplexNumber& object) {
	ComplexNumber result;

	result.real = this->real * object.real - (this->imaginary * object.imaginary);
	result.imaginary = (this->real * object.imaginary) + (this->imaginary * object.real);

	return result;
}

ComplexNumber ComplexNumber::divide(const ComplexNumber& object) {
	ComplexNumber object__(object.real, -object.imaginary);
	ComplexNumber denominator;
	ComplexNumber result;

	float numerator = object.real * object.real - (object.imaginary * -object.imaginary);
	denominator = this->multiply(object__);

	result.real = denominator.real / numerator;
	result.imaginary = denominator.imaginary / numerator;

	return result;
}

int main(void) {
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
			d = (a.subtract(b)).subtract(c);
			cout << "d = " << d << endl;
			break;

		case 3:
			cout << endl << "°ö¼À d = a * b * c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a.multiply(b.multiply(c));
			cout << "d = " << d << endl;
			break;
		case 4:
			cout << endl << "³ª´°¼À d = a / b / c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = (a.divide(b)).divide(c);
			cout << "d = " << d << endl;
			break;
		case 5:
			cout << endl << "cascading µ¡¼À d = a + b + c" << endl;
			cout << endl << "a = " << a << ", b = " << b << ", c = " << c << endl;
			d = a + b + c;
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