#include <iostream>
#include <ctime>
using namespace std;
class Point {
	int ix;
	int iy;

public:
	Point() {}
	Point(int x, int y) {
		ix = x;
		iy = y;
	}

	string toString() {
		cout << "<" << ix << ", " << iy << ">";
	}

	int getX() {
		return ix;
	}

	int getY() {
		return iy;
	}

	void setX(int x) {
		ix = x;
	}

	void setY(int y) {
		iy = y;
	}

	bool equals(Point p) {
		if ((this->ix == ((Point)p).ix) && (this->iy == ((Point)p).iy))
			return true;
		else return false;
	}
	friend ostream& operator<<(ostream& os, Point& p);
};
ostream& operator<<(ostream& os, Point& p) {
	os << p.ix << " " << p.iy;
	return os;
}
class EmptyStackException : public std::exception {
public:
	EmptyStackException() {}
};

//--- 실행시 예외: 스택이 가득 참 ---//
class OverflowStackException : public std::exception {
public:
	OverflowStackException() {}
};

class Stack {
	//--- 실행시 예외: 스택이 비어있음 ---//
	// generic class는 Throwable을 상속받을 수 없다 - 지원하지 않는다

	Point data[100];           // 스택용 배열
	int capacity; // 스택의 크기
	int top; // 스택 포인터
public:
//--- 생성자(constructor) ---//
	Stack(int capacity = 100) {
		top = 0;
		this->capacity = capacity;

	}

	//--- 스택에 x를 푸시 ---//
	bool push(Point x) throw (OverflowStackException) {
		cout<<"top = " <<top << "capacity = " << capacity;
		if (top >= capacity) //full stack
			throw OverflowStackException();

		data[top++] = x;
		return true;

	}

	//--- 스택에서 데이터를 팝(정상에 있는 데이터를 꺼냄) ---//
	Point pop() throw (EmptyStackException) 
	{
		if (top <= 0) //empty stack
			throw EmptyStackException();
		return data[--top];
	}

	//--- 스택에서 데이터를 피크(peek, 정상에 있는 데이터를 들여다봄) ---//
	Point peek() throw (EmptyStackException) {
		if (top <= 0)
			throw EmptyStackException();
		return data[top - 1];
	}

	//--- 스택을 비움 ---//
	void clear() {
		top = 0;
	}

	//--- 스택에서 x를 찾아 인덱스(없으면 –1)를 반환 ---//
	int indexOf(Point x) {
		for (int i = top - 1; i >= 0; i--) // 꼭대기 쪽부터 선형 검색
			if (data[i].equals(x))
				return i; // 검색 성공
		return -1; // 검색 실패
	}

	//--- 스택의 크기를 반환 ---//
	int getCapacity() {
		return capacity;
	}

	//--- 스택에 쌓여있는 데이터 갯수를 반환 ---//
	int size() {
		return top;
	}

	//--- 스택이 비어있는가? ---//
	bool isEmpty() {
		return top <= 0;
	}

	//--- 스택이 가득 찼는가? ---//
	bool isFull() {
		return top >= capacity;
	}

	//--- 스택 안의 모든 데이터를 바닥 → 꼭대기 순서로 출력 ---//
	void dump() {
		if (top <= 0)
			cout<<"stack이 비어있습니다.";
		else {
			for (int i = 0; i < top; i++)
				cout<<" " << data[i]<<endl;
			cout << endl;
		}
	}
};
// 4장 소스코드의 Point 버젼을 학습한 후에 Queue 버젼을 구현한다.

/*
 * objectStack에 point 객체를 push, pop하는 코드를 구현 실습한다
 */


 void main() {

		Stack st; // 최대 8 개를 push할 수 있는 stack
		srand((unsigned int)time(NULL));
		int rndx = 0, rndy = 0;
		Point p; int menu;
		while (true) {
		
			cout << "현재 데이터 개수" << st.size() << "용량 = " << st.getCapacity() << endl;;
			cout<<"(1)push　(2)pop　(3)peek　(4)dump　(0)종료: ";

			
			cin >> menu;
		
			if (menu == 0)
				break;

			switch (menu) {
			case 1: // 푸시
			
				rndx = rand() % 10;
				rndy = rand() % 10;
				p = Point(rndx, rndy);
				try {
					st.push(p);
				}
				catch (OverflowStackException e) {
					cout<<"stack이 가득찼있습니다.";
				}
				break;

			case 2: // 팝
				try {
					p = st.pop();
					cout<<endl<<"pop한 데이터는 "<< p<< "입니다.";
				}
				catch (EmptyStackException e) {
					cout<<"stack이 비어있습니다.";
				}
				break;

			case 3: // 피크
				try {
					p = st.peek();
					cout<<endl<<"peek한 데이터는 " << p << "입니다.";
				}
				catch (EmptyStackException e) {
					cout<<"stack이 비어있습니다.";
				}
				break;

			case 4: // 덤프
				st.dump();
				break;
			}
		}
	}
