/*
* 클래스 상속, template, 예외처리 구현
*/
#include <iostream>
#include <ctime>
#include <string>
using namespace std;



class ExceptionError {
	public:
		virtual void Print() = 0;
};


class OverflowException : public ExceptionError {
	public:
		void Print() {
			cout << "overflow 예외 발생"<< endl;
		}
};


class RowRecordsOverflowException : public OverflowException { //한 행이 다 찼다
	public:
		void Print() {
			cout << "Row Records overflow 예외 발생" << endl;
		}
};


class TableRecordsOverflowException : public OverflowException {//테이블이 다 찼다.
	public:
		void Print() {
			cout << "Table Records overflow 예외 발생" << endl;
		}
};


class EmptyException : public ExceptionError {
	public:
		void Print() {
			cout << "empty 예외 발생" << endl;
		}
};


class NotFoundRecordException : public EmptyException {
	public:
		void Print() {
			cout << "Not found record 예외 발생" << endl;
		}
};





class Person {
	string pid;
	string pname;
	string key;
public:
	Person() {}
	Person(string pid, string pname) : pid(pid), pname(pname), key(pid) {}
	string GetName() { return pname; }
	void SetName(char* str) { pname = str; }
	string GetKey() {return key;}
};




class Employee : public Person {
private:
	string eno;
	string role;
public:
	Employee() : Person() {}
	Employee(string pid, string pname, string eno, string role) : Person(pid, pname), eno(eno), role(role) {}
	virtual void Print();
	virtual bool Equals(Employee* p);
	string Key() {return Person::GetKey();}
	friend ostream& operator<<(ostream& os, Employee& e);
};
ostream& operator<<(ostream& os, Employee& e) {
	cout << e.Person::GetKey() << " " << e.Person::GetName() << " " << e.eno;
	return cout;
}
bool Employee::Equals(Employee* p) {
	return true;
}
void Employee::Print() {
	cout << Person::GetKey() << " " << Person::GetName() << " " << eno << endl;
}


class Student {
private:
	string sid;
	string major;
	string key;
public:
	Student() {}
	Student(string sid, string major) : sid(sid), major(major), key(sid) {}
	void Print();
	string GetKey() {return key;}
	string GetMajor() {return major;}
};
void Student::Print() {
}


class WorkStudent : public Student {
private:
	string job;
public:
	WorkStudent() : Student() {}
	WorkStudent(string sid, string major, string job) : Student(sid, major), job(job) {}
	void Print();
	string Key() {return Student::GetKey();}
	friend ostream& operator<<(ostream&os, WorkStudent& ws);
};
ostream& operator<<(ostream&os, WorkStudent& ws) {
	os << ws.Student::GetKey() << " " << ws.Student::GetMajor();
	return os;
}
void WorkStudent::Print() {
	cout << Student::GetKey() << " " << Student::GetMajor() << " " << job << endl;
}



template <class T>
class RowRecords {
public:
	RowRecords(int maxKeys = 5, int unique = 1);// unique = 1은 중복이 없다
	~RowRecords();
	void Clear(); // RowRecords의 모든 레코드를 삭제한다 /will not use
	int Insert(const string key, T& record);
	int Remove(const string key);
	T& Search(const string key) const;
	void Print();
	int numKeys()const { return NumKeys; }
	int Find(const string key) const;
	T& GetRecord(int index);
	void Update(int index, T& record);
protected:
	int MaxKeys; //the number of cols
	int NumKeys; //current position
	string * Keys; 	//???
	T* Records;		//????

	int Init(const int maxKeys, const int unique);
	int Unique; // if true, each key value must be unique

};
template <class T>
void RowRecords<T>::Update(int index, T& record) {
	Records[index] = record;
}
template <class T>
T& RowRecords<T>::GetRecord(int index) {
	return Records[index];
}

template <class T>
RowRecords<T>::RowRecords(int maxKeys, int unique) : NumKeys(0), Keys(0), Records(0) {
	Init(maxKeys, unique);
}
template <class T>
int RowRecords<T>::Init(const int maxKeys, const int unique) {
	Unique = unique != 0;
	MaxKeys = maxKeys;
	Keys = new string[maxKeys];
	Records = new T[maxKeys];

	return 0;
}
template <class T>
RowRecords<T>::~RowRecords() {
	delete Keys;
	delete Records;
}
template <class T>
void RowRecords<T>::Clear() {
	NumKeys = 0;
}
template <class T>
int RowRecords<T>::Insert(const string key, T & record) {
	cout << "RowRecords::Insert" << endl;
	int index;
	if (NumKeys != 0) {
		index = Find(key);
		if (Unique && index >= 0) return 0; //주어진 key가 이미 존재함
	}
	if (NumKeys == MaxKeys) throw OverflowException(); //Full일 때 예외처리 
	// for (int i = NumKeys - 1; i >= 0; i--) {
	// 	if (key > Keys[i])break; //insert into location i+1 //정렬해서 넣는 거 아님//그냥 뒤에 붙인다.
	// 	Keys[i + 1] = Keys[i]; //밀려 넣는 거임 Append 
	// 	Records[i + 1] = Records[i];
	// }
	Keys[NumKeys] = key;
	Records[NumKeys] = record;
	// Keys[i + 1] = key;
	// T[i + 1] = record;
	NumKeys++;
	return 1;
}
template <class T>
int RowRecords<T>::Remove(const string key) {
	int index = Find(key);
	if (index < 0) return 0; //key not in index
	cout << "numkeys : " << NumKeys << endl;
	for (int i = index; i < NumKeys-1; i++) {
		Keys[i] = Keys[i + 1];
		Records[i] = Records[i + 1];//값만 바꾸면, 여기서 delete가 없어서 heap 메모리에 남아있을 것이다.
	}
	NumKeys--;
	return 1;
	// return index;
}
template <class T>
T& RowRecords<T>::Search(const string key) const{
	// cout << "Search" << endl;
	int index = Find(key);
	if (index != -1) return Records[index];
	// throw EmptyException();
	throw NotFoundRecordException();
}
template <class T>
void RowRecords<T>::Print() {
	if (NumKeys == 0) throw EmptyException();
	cout << "max keys = " << MaxKeys << " num keys = " << NumKeys << endl;
	for (int i=0; i<NumKeys; i++) {
		cout << "\tKey[" << i << "] " << Keys[i] << " Records = " << Records[i] << endl;
	}
}
template <class T>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
int RowRecords<T>::Find(const string key) const{ //현재 줄에서 key가 이미 있는지 찾는다? //기존 key가 있으면 입력을 안 하도록.. //중복 체크하는 것임
	// for (int i = 0; i < NumKeys; i++) {
	// 	if (Keys[i] < key) continue;
	// 	if (Keys[i] == key) {//there is same key
	// 		if (record == Records[i])
	// 			return i;
	// 	}
	// }
	if (NumKeys == 0) throw EmptyException();
	for (int i = 0; i <= NumKeys; i++) {
		// if (Keys[i] < key) continue;
		if (Keys[i] == key) {//there is same key
			return i;
		}
	}
	return -1;
}





template <class T>
class RecordTable {
public:
	T& Read(string  key);//read by key
	int Append(T& record);
	int Update(string key, T& record);
	int Delete(string key);
	void Print();
	RecordTable(int, int);
	~RecordTable();
protected:
	int MaxKeys; //the number of max cols
	int MaxRecords; //the number of max rows
	int NumRecords; //top of row
	RowRecords<T>** data; //pointer of row
};
template <class T>
RecordTable<T>::RecordTable(int MaxRecords, int MaxKeys) : MaxRecords(MaxRecords), MaxKeys(MaxKeys) {
	NumRecords = 0;
	data = new RowRecords<T>* [MaxRecords];
	for (int i = 0; i < MaxRecords; i++) {
		data[i] = new RowRecords<T>(MaxKeys);
	}

}
template <class T>
RecordTable<T>::~RecordTable() {
	for (int i = 0; i < MaxRecords; i++) {
		delete data[i];
	}
}
template <class T>
T& RecordTable<T>::Read(string key) {
		for (int i = 0; i <= NumRecords; i++) {
			// try {//try 와 catch 를 여기서 할지, main 에서 할지
			int result = data[i]->Find(key);//data[i]는 row records이고 여기에 key가 있는지를 조사 //
			// }
			// catch () {

			// }
			// cout << "result : " << result << endl;
			if (result >= 0)
				return data[i]->Search(key);//Search(key)를 사용하여 row records에서 해당 레코드를 가져온다
		}
		throw NotFoundRecordException();
	// cout << "Read" << endl;
}
template <class T>
int RecordTable<T>::Append(T & record) {
	string key = record.Key(); //아마도 파라미터의 객체에서 key 값을 가져오는 건가본데 //해시함수에서 가져오는건가 아무튼 그렇다고 함...
	int i = NumRecords; //현재 입력할 줄
	//NumRecords에 있는 row records가 append할 수 있는지를 조사한다.
	if (data[i]->numKeys() == MaxKeys) //data[i] 는 한 줄
	{ //한 줄이 꽉 찼을 때
		i = ++NumRecords;
	}

	if (i == MaxRecords) {
		throw TableRecordsOverflowException();
	}
	int result = data[i]->Insert(key, record);

	return result;
}
template <class T>
int RecordTable<T>::Update(string key, T& record) {
	for (int i = 0; i <= NumRecords; i++) {
		int result = data[i]->Find(key);//data[i]는 row records이고 여기에 key가 있는지를 조사
		if (result >= 0) {//바꾼다는 동작..
			// data[i]->Remove(key);
			// data[i]->Insert(key, record);
			data[i]->Update(result, record);
			return 1;
		}
	}
	return 0;
}
template <class T>
int RecordTable<T>::Delete(string key) { //예외처리 해야됨
	int deletedRowIndex = 0;
	T* recordBeMoved_ptr = nullptr;
	
	for (int i=0; i<=NumRecords; i++) {
		if (data[i]->Remove(key)) {
			deletedRowIndex = i;
			// recordBeMoved_ptr = &data[deletedRowIndex+1]->GetRecord(0);
		}
	}
	
	for (int i=deletedRowIndex; i<NumRecords-deletedRowIndex; i++) {
		recordBeMoved_ptr = &data[i+1]->GetRecord(0);
		data[i]->Insert(recordBeMoved_ptr->Key(), *recordBeMoved_ptr);
		data[i+1]->Remove(recordBeMoved_ptr->Key());
	}

	return 1;
}
template <class T>
void RecordTable<T>::Print() {//예외처리 해야 됨
	try {
		for (int i=0; i<=NumRecords; i++) {
			// cout << "in loop" << endl;
			data[i]->Print();
		}
	} catch (EmptyException& error) {
		error.Print();
	}
}










int main() {
	Employee* members[30];//Employee 선언으로 변경하는 문제 해결 필요 
	WorkStudent* workers[20];
	RecordTable<Employee> etable(2, 5);//10개의 record sets, 각 set은 5개의 records
	RecordTable<WorkStudent> wtable(10, 5);
	int select;
	Employee* e; 
	WorkStudent* ws;
	Employee specialE("special", "gfg", "dfd", "gf");
	WorkStudent specialWs("special", "gfg", "dfd");

	int result;

	while (1)
	{
		cout << "\n선택 1: member  객체 30개 입력, 2.table 출력, 3: table 객체 찾기,4. table에서 객체 삭제, 5. update, 6. end" << endl;
		cin >> select;
		switch (select) {
		case 1://table에 객체 30개 입력
		{
			members[0] = new Employee("p1", "hong", "E1", "Coding");
			members[1] = new Employee("p2", "hee", "E2", "Coding");
			members[2] = new Employee("p3", "kim", "E3", "Test");
			members[3] = new Employee("p4", "lee", "E4", "Test");
			members[4] = new Employee("p5", "ko", "E5", "Design");
			members[5] = new Employee("p6", "choi", "E6", "Design");
			members[6] = new Employee("p7", "han", "E7", "Sales");
			members[7] = new Employee("p8", "na", "E8", "Sales");
			members[8] = new Employee("p9", "you", "E9", "Account");
			members[9] = new Employee("p10", "song", "E10", "Production");
			workers[0] = new WorkStudent("s011", "coding", "hong");
			workers[1] = new WorkStudent("s012", "coding", "ong");
			workers[2] = new WorkStudent("s013", "coding", "dong");
			workers[3] = new WorkStudent("s014", "coding", "fong");
			workers[4] = new WorkStudent("s015", "coding", "tong");
			workers[5] = new WorkStudent("s016", "coding", "nong");
			workers[6] = new WorkStudent("s017", "coding", "mong");
			workers[7] = new WorkStudent("s018", "coding", "kong");
			workers[8] = new WorkStudent("s019", "coding", "long");
			workers[9] = new WorkStudent("s020", "coding", "pong");
			workers[10] = new WorkStudent("s021", "coding", "lim");
			workers[11] = new WorkStudent("s022", "coding", "kim");
			workers[12] = new WorkStudent("s023", "coding", "bim");
			workers[13] = new WorkStudent("s024", "coding", "dim");
			workers[14] = new WorkStudent("s025", "coding", "rim");
			workers[15] = new WorkStudent("s026", "coding", "qim");
			workers[16] = new WorkStudent("s027", "coding", "fim");
			workers[17] = new WorkStudent("s028", "coding", "him");
			workers[18] = new WorkStudent("s029", "coding", "jim");
			workers[19] = new WorkStudent("s030", "coding", "jjj");
		}
			try {
				for (int i = 0; i < 10; i++) {//table 오버플로우는 여기서 catch //한 줄 오버플로우는 여기서 catch 할 필요 없음
					etable.Append(*members[i]);
				}
				for (int i = 0; i < 20; i++) {
					wtable.Append(*workers[i]);
				}
			} catch (TableRecordsOverflowException& error) {
				error.Print();
			}
		
			break;
		case 2:
			// table의 모든 객체 출력하기
			//table 모양으로 출력해야 한다: | *** | ???? | === |으로 출력한다.
			etable.Print();
			wtable.Print();
			break;
		case 3:
			// table에서 객체 찾기
			// try {
			// 	e = &etable.Read("p1");
			// 	if (e == nullptr) cout << "kim이 존재하지 않는다" << endl; //예외처리 하면 이런 코드 필요없음
			// 	else
			// 		e->Print();

			// 	ws = &wtable.Read("s011");
			// 	if (ws == nullptr) cout << "kim이 존재하지 않는다" << endl;
			// 	else
			// 		ws->Print();
			// }
			// catch(EmptyException& error) {
			// 	error.Print();
			// }
			try {
				try {
					e = &etable.Read("p1");
					e->Print();
					ws = &wtable.Read("s011");
					ws->Print();
				} catch (NotFoundRecordException& error) {
					error.Print();
				}
			} catch (EmptyException& error) {
				error.Print();
			}
			
			break;
		case 4:
			//table에서 객체 삭제하기
			try {
				result = etable.Delete("p1");
				if (result > 0)
					cout << "삭제된 records 숫자" << result << endl;
			} catch (EmptyException& error) {
				error.Print();
			}
			try {
				result = wtable.Delete("s011");
				if (result > 0)
					cout << "삭제된 records 숫자" << result << endl;
			} catch (EmptyException& error) {
				error.Print();
			}
			break;
		case 5: 
			result = etable.Update("p2", specialE);
			if (result > 0)
				cout << "삭제된 records 숫자" << result << endl;
			
			result = wtable.Update("s012", specialWs);
			if (result > 0)
				cout << "삭제된 records 숫자" << result << endl;
			
			break;
		default:
			exit(0);

		}
	}
	system("pause");
	return 1;
}