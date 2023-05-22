//7-3.INITIAL2.CPP 

#include<iostream>
using namespace std;
class A{
public:
    A(){
        cout << "Constructor of class A" << endl ;
    }
};
class B{
public:
    B(){
      cout << "Constructor of class B" << endl;
    }
};
class C{
public:
    C(){
      cout << "Constructor of class C" << endl;
    }
};
class D{
public:
    D(){
      cout << "Constructor of class D" << endl;
    }
};
class E{
public:
    E(){
      cout << "Constructor of class E" << endl;
    }
};
class F{
public:
    F(){
      cout << "Constructor of class F" << endl;
    }
};
class G: public A, public B, public C{
public:
    D d;
    E e;
    F f;
    G(){
      cout << "Constructor of class G, derived from A, B and C, having D,E,F objects inside" << endl;
    }
};
void main (){
    cout << "Defining an object of class G" << endl;
	{
		G g;//constructor, destructor 가 호출되는 순서를 이해
	}
    system("pause");
}