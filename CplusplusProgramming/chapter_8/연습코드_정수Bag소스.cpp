//정수들의 Bag 클래스 구현과 사용
#include <iostream>
#include <string>
#include "time.h"
using namespace std;

#define DefaultSize 10
class Bag {
public:
    Bag(int MaxSize = DefaultSize); //생성자
    ~Bag(); // 소멸자
    virtual void Add(int); // 정수 하나를 bag에 삽입
    virtual int Delete(); //bag에서 정수 하나를 삭제
    bool IsFull();
    // bag이 포화상태이면 true, 그렇지 않으면 false를 반환
    bool IsEmpty();
    // bag이 공백 상태이면 true, 그렇지 않으면 false를 반환
    int Top();
    int Find();
    friend ostream& operator<< (ostream& stream, Bag b);
protected:
    void Full(); // bag이 포화상태일 때의 조치
    void Empty(); // bag이 공백 상태일 때의 조치
    int arr[DefaultSize];
    int MaxSize; // 배열의 크기
    int top; // 배열에서 원소가 들어 있는 가장 높은 위치
};

class Set : public Bag {
public:
    Set(int MaxSize = DefaultSize);      //생성자
    ~Set();      // 소멸자
                 //Set 자료구조에 맞게 Add(), Delete() 함수 재정의
    void Add(int);
    int Delete();
    friend ostream& operator<< (ostream& stream, Set s);
};


int main() {
    Set s;
    int select;
    int num;
    srand(time(NULL));
    while (1)
    {

        cout << "\n선택 1: 난수 생성하여 입력, 2.set 출력 정렬, 3.set에서 임의 삭제, 4. Set에서 find, 5. 종료" << endl;
        cin >> select;

        switch (select) {
        case 1://1: 난수 생성

            for (int i = 0; i < 10; i++) {
                s.Add(rand() % 100);
            }

            break;
        case 2:
            cout << "Set:: 전체 출력" << s << endl;
            break;

        case 3://

            for (int i = 0; i < 10; i++)
            {
                cout << "Set:: 삭제된 값 = " << s.Delete() << endl;
            }
            break;
        case 4://

            for (int i = 0; i < 10; i++)
            {
                cin >> num;
                s.Find(num);
                //
            }
            break;
        default:
            exit(0);

        }
    }
    system("pause");
    return 1;
}