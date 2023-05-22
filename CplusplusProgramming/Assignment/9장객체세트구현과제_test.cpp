/*
* ��ü���� Set�� �����ϴ� ���̺��� �迭�� ���� Ŭ���� �����ϱ�
*/
#include <iostream>
#include <string>
#define DefaultSize 50
using namespace std;

class Employee;

class Person { //�߻� Ŭ������ �����Ѵ�
protected:
    string pid;
    string pname;
public:
    string GetName() { return pname; }
    void SetName(); //���� ǥ�� �̸��� ??? �̷������� �ٲٴ� ��
    Person() {}
    Person(string pid, string pname) : pid(pid), pname(pname) { }
    virtual void Print() = 0;
    virtual bool Equals(string) = 0; //���ľ� �� ��ġ�� �� string �� �޾Ƽ� �ϴ� ������ ��ġ��
    virtual ~Person() {}
    virtual bool operator==(Employee&);
};
bool Person::operator==(Employee& e) {
    // cout << "Person::operator==" << endl;
    // Person* p = dynamic_cast<Person*>(e);
    Person& p = (Person&)e;
    return (pid == p.pid && pname == p.pname);
}
void Person::SetName() {
    // cout << "Person::SetName()" << endl;
    // cout << pname << endl;
    pname = "????";
    // cout << pname << endl;
}
bool Person::Equals(string str) {
    return pname == str;
}
void Person::Print() {
    cout << pname;
}

class Employee : public Person {
private:
    string eno;
    string role;
public:
    Employee() : Person() {}
    Employee(string pid, string pname, string eno, string role) : Person(pid, pname), eno(eno), role(role) {}
    void Print() override;
    bool Equals(string str);
    bool operator==(Employee&) override;
};
bool Employee::operator==(Employee& e) {
    // cout << "Employee::operator==" << endl;
    // Person* p = dynamic_cast<Person*>(e);
    Person& this_p = dynamic_cast<Person&>(*this);
    return (this_p.Person::operator==(e) && eno == e.eno && role == e.role);
}
bool Employee::Equals(string str) {
    return Person::Equals(str);
}
void Employee::Print() {
    Person::Print();
}

class Coder : public Employee {
private:
    string language;
public:
    Coder() :Employee() {}
    Coder(string pid, string pname, string eno, string role, string language) : Employee(pid, pname, eno, role), language(language) {}
    void Print() override;
    bool operator==(Employee&) override;
};
bool Coder::operator==(Employee& e) {
    // cout << "Coder::operator==" << endl;
    Coder& c = dynamic_cast<Coder&>(e);
    return (this->Employee::operator==(e) && language == c.language);
}
void Coder::Print() {
    Employee::Print();
    // cout << language;
}


class Student : public Employee {
private:
    string sid;
    string major;
public:
    Student(string sid, string major, string eno, string role, string pid, string pname) : Employee(pid, pname, eno, role), sid(sid), major(major) { }
    void Print() override;
    bool operator==(Employee&) override;
};
bool Student::operator==(Employee& e) {
    // cout << "Student::operator==" << endl;
    Student& s = dynamic_cast<Student&>(e);
    return (this->Employee::operator==(e) && sid == s.sid && major == s.major);
}
void Student::Print() {
    Employee::Print();
}



class Bag {
public:
    virtual void Add(Employee*); // ���� �ϳ��� bag�� ����
    virtual int Delete(string); //bag���� ���� �ϳ��� ����
    virtual Employee* Search(string);
    virtual void Print();
    bool IsFull();
    // bag�� ��ȭ�����̸� true, �׷��� ������ false�� ��ȯ
    bool IsEmpty();
    // bag�� ���� �����̸� true, �׷��� ������ false�� ��ȯ
    int Top();

protected:
    Bag(int bagSize) {//main ���� ȣ�� �� ��
        arr = new Employee*[bagSize];
        //for () { don't do this
            // arr[i] = new Employee(); //error 
        //}
        topBag = 0;
        bagMaxSize = bagSize;
    }
    void Full(); // bag�� ��ȭ������ ���� ��ġ
    void Empty(); // bag�� ���� ������ ���� ��ġ

    Employee** arr; //> �����ڿ��� arr = new Employee*[Size]; > arr[i] = new Employee();
    int bagMaxSize; // �迭�� ũ��
    int topBag; // �迭���� ���Ұ� ��� �ִ� ���� ���� ��ġ //table�� col �� ����, ũ�Ⱑ �� ���� 0���� ���߰���?
    //*
    // ~Bag() {
    //     for (int i = 0; i < bagMaxSize; i++) {
    //         delete arr[i];
    //     }
    //     delete[] arr;
    // }
    // */
};
int Bag::Delete(string str) {
    // cout << "Bag::Delete()" << endl;
    int result = 0;
    // cout << topBag << endl;
    for (int i=0; i<topBag; i++) {
        if (arr[i]->Equals(str)) {
            arr[i]->SetName();
            result++;
        }
    }
    // cout << result << endl;

    return result;
}
Employee* Bag::Search(string str) {
    for (int i=0; i<bagMaxSize; i++) {
        if (arr[i]->Equals(str)) {
            return arr[i];
        }
    }
    return nullptr;
}
void Bag::Add(Employee* e) {
    // cout << "Bag::Add() " << topBag << endl;
    arr[topBag] = e;
    topBag++;
}
void Bag::Print() {
    for (int i=0; i<bagMaxSize; i++) {
        cout << " | ";
        arr[i]->Print();
        // cout << " | ";
    }
    cout << " |" << endl;
}

class Set : public Bag {
public:
    Set(int setSize) : Bag(setSize) {} //set �� �����ڸ� main���� ȣ��
    void Add(Employee*); //check duplicate
    int Delete(string); //���� ǥ��?
    void Print() override;
    Employee* Search(string);
    bool IsDuplicate(Employee*);
};
int Set::Delete(string str) {
    // cout << "Set::Delete()" << endl;
    return Bag::Delete(str);
}
void Set::Print() {
    Bag::Print();
}
Employee* Set::Search(string str) {
    return Bag::Search(str);
}
bool Set::IsDuplicate(Employee* e) {
    for (int i=0; i<topBag; i++) {
        if (*arr[i] == *e) {
            return true;
        }
    }
    return false;
}
void Set::Add(Employee* e) {
    // cout << "Set::Add()" << endl;
    if (IsDuplicate(e)) {
        cout << "It is duplicate" << endl;
    } else {
        Bag::Add(e);
    }
    // Bag::Add(e);
}


class RecordSet : public Set { //recordSet �� table �� �� �� 
    int setMaxSize;//5���� ���ڵ� ��
    int topRecordSet;//�ش� ���ڵ弼Ʈ���� �Է��� ��ġ
public:
    RecordSet(int maxSize) : Set(maxSize), setMaxSize(maxSize) {
        topRecordSet = 0;
    }
    Employee* Search(string);
    void Print();
    int Delete(string);
    void Add(Employee* e); //setMaxSize check //
};
int RecordSet::Delete(string str) {
    // cout << "RecordSet::Delete()" << endl;
    return Set::Delete(str);
}
Employee* RecordSet::Search(string str) {
    return Set::Search(str);
}
void RecordSet::Print() {
    Set::Print();
}
void RecordSet::Add(Employee* e) {
    // cout << "RecordSet::Add()" << endl;
    // cout << topRecordSet << ", " << setMaxSize << endl;
    if (topRecordSet < setMaxSize) {
        Set::Add(e);
        topRecordSet++;
    } else { //�� ���� �� ä��� ���� �ε����� �ʱ�ȭ
        topRecordSet = 0;
    }
}





class RecordTable { // table�� �� ���� Employee* �� ����. �� ���� Employee* ���� array �̴�.
    int tableMaxSize; //���̺� ���� ��
    int topRecordTable; //���� ���� ��ġ //���� ��ġ // 0�̸� ù ��° �� //�׷� ���� �����Ұǰ�? �� ���� ũ�Ⱑ �� ���� ����
    RecordSet** data;
    int capacity; //�� ���� �ִ� ���� ����
    int count; //���� �࿡ ����ִ� ��ü�� ����
public: //numberSet : number of Set .
    RecordTable(int numberSet, int numberRecords) : tableMaxSize(numberSet), capacity(numberRecords) {
        count = 0;
        topRecordTable = 0; //���� ���� ��ġ
        data = new RecordSet* [numberSet];//10���� set
        for (int i = 0; i < numberSet; i++) {
            data[i] = new RecordSet(numberRecords);//�� set�� 5�� records
            // cout << i << endl;
        }
    }
    void Add(Employee*); // ���� �ϳ��� bag�� ���� //call recordSet::Add()
    int Delete(string);
    Employee* Search(string);
    void Print();
};
int RecordTable::Delete(string str) {
    // cout << "RecordTable::Delete()" << endl;
    int result = 0;
    
    for (int i=0; i<=topRecordTable; i++) {
        result += data[i]->RecordSet::Delete(str);
    }

    return result;
}
void RecordTable::Add(Employee* e) {
    // cout << topRecordTable << ", " << tableMaxSize << ", " << count << ", " << capacity << endl;
    if (topRecordTable < tableMaxSize) {
        if (count < capacity) {
            data[topRecordTable]->RecordSet::Add(e);
            count++;
        } else { //���� ������ �Ѿ�� �� �� ������ �ֳ�����
            // cout << "else" << endl;
            topRecordTable++;
            count = 0;
            // cout << topRecordTable << ", " << tableMaxSize << ", " << count << ", " << capacity << endl;
            data[topRecordTable]->RecordSet::Add(e);
            count++;
        }
    }
}
void RecordTable::Print() {
    for (int i=0; i<=topRecordTable; i++) {
        data[i]->Print();
        // cout << "|" << endl;
    }
}
Employee* RecordTable::Search(string str) {
    for (int i=0; i<=topRecordTable; i++) {
        if (data[i]->RecordSet::Search(str)) {
            return data[i]->RecordSet::Search(str);
        }
    }
    return nullptr;
}


int main() { //nothing to touch in main
    Employee* members[30];//Employee �������� �����ϴ� ���� �ذ� �ʿ� 
    RecordTable table(10, 5);//10���� record sets, �� set�� 5���� records 1���� set�� ���Ե� record �� ��. ��ġ 2���� ó�� (10��, 5��) �� ���� Person �� ��ü
    int select;
    Employee* p;
    int result;
    while (1)
    {
        cout << "\n���� 1: member  ��ü 30�� �Է�, 2.table ���, 3: table ��ü ã��,4. table���� ��ü ����, 5. ����" << endl;
        cin >> select;
        switch (select) {
        case 1://table�� ��ü 30�� �Է�
        {
            members[0] = new Coder("000p1", "hong", "E1", "Coding", "C++");
            members[1] = new Coder("000p1", "hong", "E1", "Coding", "C++");
            members[2] = new Coder("000p3", "kime", "E3", "Test", "JAVA");
            members[3] = new Coder("000p4", "leee", "E4", "Test", "C#");
            members[4] = new Coder("000p5", "koee", "E5", "Design", "GO");
            members[5] = new Coder("000p6", "choe", "E6", "Design", "GO");
            members[6] = new Coder("000p7", "hane", "E7", "Sales", "PYTHON");
            members[7] = new Coder("000p8", "naae", "E8", "Sales", "C");
            members[8] = new Coder("000p9", "youe", "E9", "Account", "C++");
            members[9] = new Coder("00p10", "sone", "E10", "Production", "C#");
            members[10] = new Student("s011", "coding", "E33", "manager", "23001", "hong");
            members[11] = new Student("s012", "coding", "E33", "manager", "23002", "onge");
            members[12] = new Student("s013", "coding", "E33", "manager", "23003", "dong");
            members[13] = new Student("s014", "coding", "E33", "manager", "23004", "fong");
            members[14] = new Student("s015", "coding", "E33", "manager", "23005", "tong");
            members[15] = new Student("s016", "coding", "E33", "manager", "23006", "hong");
            members[16] = new Student("s017", "coding", "E33", "manager", "23007", "mong");
            members[17] = new Student("s018", "coding", "E33", "manager", "23008", "kong");
            members[18] = new Student("s019", "coding", "E33", "manager", "23009", "long");
            members[19] = new Student("s020", "coding", "E33", "manager", "23010", "hong");
            members[20] = new Student("s021", "coding", "E53", "manager", "23111", "lime");
            members[21] = new Student("s022", "coding", "E53", "manager", "23212", "mime");
            members[22] = new Student("s023", "coding", "E53", "manager", "23313", "bime");
            members[23] = new Student("s024", "coding", "E53", "manager", "23414", "dime");
            members[24] = new Student("s025", "coding", "E53", "manager", "23515", "rime");
            members[25] = new Student("s026", "coding", "E53", "manager", "23616", "qime");
            members[26] = new Student("s021", "coding", "E53", "manager", "23717", "fime");
            members[27] = new Student("s021", "coding", "E53", "manager", "23818", "hime");
            members[28] = new Student("s027", "coding", "E53", "manager", "23919", "jime");
            members[29] = new Student("s027", "coding", "E53", "manager", "24020", "jjje");
        }
            cout << (*members[0] == *members[1]) << endl;
            // cout << (1 == 1) << endl;

            for (int i = 0; i < 30; i++) {
                table.Add(members[i]);
            }
            break;
        case 2:
            // table�� ��� ��ü ����ϱ�
            //table ������� ����ؾ� �Ѵ�: | *** | ???? | === |���� ����Ѵ�.

            table.Print(); //�ϴ� pid �θ� ����� ����
            break;
        case 3:
            // table���� ��ü ã��

            p = table.Search("mmm");
            if (p == nullptr) cout << "mmm�� �������� �ʴ´�" << endl;
            else
                p->Print();
            break;
        case 4:
            //table���� ��ü �����ϱ�
            result = table.Delete("kkkk"); // �� �̸��� ��� �����ϴ� �ǰ�����
            if (result > 0)
                cout << "������ records ����" << result << endl;
            else 
                cout << "no deleted object" << endl;

            break;
        default:
            exit(0);
        }
    }
    system("pause");
    return 1;
}