// 10.4.5 복잡한 template 사용
// frnd2tmp.cpp -- template class with non-template friends
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class HasFriend
{
private:
    T item;
    static int ct;
public:
    HasFriend(const T& i) : item(i) { ct++; }
    ~HasFriend() { ct--; }
    friend void counts();//모든 specialization에 대하여 friend function
    friend void reports(HasFriend<T>&); // template parameter
};

// each specialization has its own static data member
template <typename T>
int HasFriend<T>::ct = 0;

// non-template friend to all HasFriend<T> classes
void counts()
{
    cout << "counts():: int count: " << HasFriend<int>::ct << "; ";//static data member
    cout << "double():: double count: " << HasFriend<double>::ct << endl;//static data member
}

// non-template friend to the HasFriend<int> class
void reports(HasFriend<int>& hf)
{
    cout << "HasFriend<int>: " << hf.item << endl;
}

// non-template friend to the HasFriend<double> class
void reports(HasFriend<double>& hf)
{
    cout << "reports()::HasFriend<double>: " << hf.item << endl;
}

int main()
{
    cout << "No objects declared: " << endl;
    counts();
    HasFriend<int> hfi1(10);
    cout << endl << "After hfi1 declared: " << endl;
    counts();
    HasFriend<int> hfi2(20);
    cout << endl<<"After hfi2 declared: " << endl;
    counts();
    HasFriend<double> hfdb(10.5);
    cout << endl << "After hfdb declared: " << endl;
    counts();
    reports(hfi1);
    reports(hfi2);
    reports(hfdb);
    std::cin.get();
    return 0;
}
