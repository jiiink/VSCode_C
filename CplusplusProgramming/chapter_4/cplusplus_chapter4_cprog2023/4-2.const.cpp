//4-2. const.cpp   4.2.2 상수 pointer 선언 - 상수 pointer를 함수로 전달할 때 많이 사용됨
// 아래 소스코드는 상수 pointer를 테스트하기 위한 용도의 소스 코드

//remove the comment, and check why error occured
#include<iostream>
using namespace std;
void square(const int* const);
void sum(int* const);
void add(const int*);

int main(void){
    //pointer 상수를 공부하는 소스코드
    int i1 = 5;
    int i2 = 10;
    int i3 = 15;
    int i4 = 20;
	int *p1 = &i1; //pointer
    const int* pc_a = &i2; //pointer-to-constant
    const int* pc_b = &i2; //*p is constant
    //(*pc_a)++; //pc_a is pointer_to_const. *pc_a is const. So cannot change *pc_a.
    int* const cp_a = &i3; //constant pointer //p is constant
    int* const cp_b = &i3; //must initiallized
    //(*cp_a)++; //cp_a is const_pointer. cp_a is const. So can change *cp_a.
    const int* const cpc_a = &i4; //constant pointer-to-const
    const int* const cpc_b = &i4; 
    //(*cpc_a)++; //cpc_a is const_pointer_to_const. *cpc_a is const. So cannot change *cpc_a.
    cout << "초기 값" << endl;
    cout << "*pi : " << *p1 << " \t" << "*pc_a : " << *pc_a << "\t";
    cout << "*cp_a : " << *cp_a << "\t" << "*cpc_a : " <<  *cpc_a << endl<< endl;

	int *pi = &i1;//에 대하여 pointer-to-constant, constan pointer, constant pointer-to-const에 대한 치환이 가능한지를 조사
    //pi = pc_a; //int* =! const int*   //error
    //pc_a = pi; //상수를 가리키던 포인터가 다른 걸 가리키도록 변경 가능하다?
    //cout<<"*pc_a : "<<*pc_a<<endl;;

    //pi = pc_a;//const int*  형식의 값을 int*에 assign할 수 없다
    //pi = cp_a; //상수 포인터가 가리키던 걸 다른 포인터가 가리킬 수 있다?
    //cp_a = pi; //cp_a is const. so can't change
    //(*pi)++; //i3++;
    //pi = cpc_a;//const int*  형식의 값을 int*에 assign할 수 없다
    //cp_a = pc_a; //cp_a is lvalue
	//pointer-to-constant에 대하여 치환이 가능한지를 조사
    cout << "pointer-to-constant에 가능한 치환" << endl;
	pc_a = pi; //pointer
	//(*pc_a)++; //*pc_a is const.
    cout << "*pc_a : " << *pc_a << "\t";
    pc_a = cp_a;  //const_pointer
    cout << "*pc_a : " << *pc_a << "\t";
    pc_a = cpc_a; //const_pointer_to_const
    cout << "*pc_a : " << *pc_a << "\t";
    pc_a = pc_b; //pointer_to_const
    cout << "*pc_a : " << *pc_a << endl << endl;
    //*pc_a = *pi;  //식이 수정할 수 있는 lvalue여야 한다, 수정할 수 없다는 뜻
    //*pc_a = *cp_a; 
    //*pc_a = *cpc_a;
    //*pc_a = *pc_b;
    //*pc_a is const. so assign to pc_a

	//constan pointer에 대하여 치환이 가능한지를 조사
    //cp_a = pi; //식이 수정할 수 있는 lvalue여야 한다, 수정할 수 없다는 뜻
    //cp_a = pc_a;
    //cp_a = cpc_a;
    //cp_a = cp_b;
    cout << "constant pointer에 가능한 치환" << endl;
    *cp_a = *pi; 
    cout << "*cp_a : " << *cp_a << "\t";
    *cp_a = *pc_a;
    cout << "*cp_a : " << *cp_a << "\t";
    *cp_a = *cpc_a;
    cout << "*cp_a : " << *cp_a << "\t";
    *cp_a = *cp_b;
    cout << "*cp_a : " << *cp_a << endl << endl;
    //cp_a is const. so assign to *cp_a
	
	//constant pointer-to-const에 대하여 치환이 가능한지를 조사
    //both of cpc_a and *cpc_a are const. So can't assign
    //cpc_a = pi;    
    //cpc_a = pc_a;
    //cpc_a = cp_a;
    //cpc_a =cpc_b;
    //*cpc_a = *pi;
    //*cpc_a = *pc_a;
    //*cpc_a = *cp_a;
    //*cpc_a = *cpc_b;

    //pointer 상수를 사용하는 소스코드: parameter 전달시에 주로 사용한다 
    square(pi);
    sum(pi);
    add(pi);
    square(pc_a);
    //sum(pc_a);
    add(pc_a);
    square(cp_a);
    sum(cp_a);
    add(cp_a);
    square(cpc_a);
    //sum(cpc_a);
    add(cpc_a);

    system("pause");
}

void square(const int* const p) {
   // int* a = p;
   // int* const b = p;
    int const* c = p;
    int const* const d = p;
}
void sum(int* const q) {
    int* a = q;
    int* const b = q;
    int const* c = q;
    int const* const d = q;
}
void add(const int* q) {
    //int* a = q;
    //int* const b = q;
    int const* c = q;
    int const* const d = q;
}