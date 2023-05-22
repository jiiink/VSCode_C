//8.2 dynamicBinding.cpp   8.5 virtual 함수
#include <iostream>
using namespace std;
/*
실습예제 8.2
1) 내용
본 source code는 virtual을 통하여 동적 binding에 대하여 알아보는 내용이다.
2) 방법
가. class Person의 Print()함수에 virtual이 있는 경우와 없는 경우를 각각 실행하여 차이를 확인해보자.
나. class Person의 Print()함수에 virtual을 지우고 class Foreigner의 Print()함수에 virtual을 추가했을 때 wc->Print()의 결과 값이 어떻게 출력되는지 확인해보자.
다. class Person, Foreigner, China의 Print()함수에 전부 virtual로 선언했을 때 실행하여 결과 값을 확인해보자.
*/
class Person{
protected:
    char* name;
public:
    Person(char* n):name(n){}
    virtual void Print(){
        cout<<"\tPerson::Print(): name is "<<name<<endl;
    }
    virtual void Print(char* ch){
        cout<<"\tPerson::Print(char*ch): name is "<<ch<<endl;
    }
};
//class Foreigner : protected Person { //assign이 동작하지 않는다 
class Foreigner : public Person{
    char *nation;
public:
    Foreigner(char* name, char *country):Person(name), nation(country){}
//주석1   
//*
    void Print(){
        cout<<"\tForeigner::Print(): nation = "<<nation<<endl;
    }
//*/
//주석2
/*
     virtual void Print(){
        cout<<"\tForeigner::virtual_Print():name = " <<name << endl;
    }
*/	 
    void Print(char* ch){
		Person::Print(ch);
        cout<<"\tForeigner::Print(char* ch):name = " << ch << endl;
    }
    virtual void show() {
        cout << "\tForeigner::virtual_Show():name = " << name << endl;
    }
};
class ChinaForeigner : public Foreigner{
    int level;
public:
    ChinaForeigner(char* n, char *country, int level):Foreigner(n, country), level(level){}
    void Print(){
        cout<<"\tChinaForeigner::Print():name - "<<name<<endl;
    }
    void show() {
    //virtual void show() { //virtual을 사용하지 않아도 되지만 virtual 함수임으로 readable
        cout << "\tChinaForeigner::virtual_Show():level = " << level << endl;
    }
};

void main(){
    Person* wp;
    Person* wf;
    Person* wc;

    wp = new Person("John");
    wf = new Foreigner("elintoo","Korea");
    wc = new ChinaForeigner("chailyn","China", 2);

    cout<<"Prints the name : "<<endl;
    wp->Print();
    wf->Print();
    wc->Print();
    wc->Person::Print();
	cout << "After wp = wf;" << endl;
    wp = wf;
    wp->Print();

	cout << "After wp = wc;" << endl;
    wp = wc;
    wp->Print();
    //wf, wc 객체가 parameter가 있는 Print()를 호출하였을 때의 결과를 비교해보자
	wf->Print("Sera"); 
    wc->Print("Sera"); 
    //변수 wp에 class Person에서 유도된 class Foreigner의
    //한 객체에 대한 pointer를 치환하는 것은 가능하다.
	cout << "wp = new Foreigner(Mario);" << endl;
    wp = new Foreigner("Mario","France");
    cout<<endl << "Re-prints the name of the man after the new assignment:"<<endl;
    wp->Print();
    Foreigner* foreigner;
    foreigner = new ChinaForeigner("Hong","china",1);
    foreigner->show();
    //wf->show();
    system("pause");
}


