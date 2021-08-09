/* NAME:  ANUBRATA DAS
 * ROLL NO: 720
 * class:B.Sc. Computer Science (Hons.)
 * SEMESTER & Year: 1ST, 2018 
 * REGISTRATION: A01-1122-117-018-2018
 */ 

/* 22.Create the Person class. Create some objects of this class ( by
 * taking information from the user). Inherit the class Person to create
 * two classes Teacher and Student class. Maintain the respective 
 * information in the classes and create, display and delete objects of
 * these two classes (Use Runtime Polymorphism). */

#include <iostream>
#include <string>

using namespace std;

class Person {
	private:
		int dataP;
	public:
		Person(int x = 0) : dataP(x) {
			cout << "Person::ctor: (dataP = " << dataP << ")" << endl;
		}
		virtual ~Person() {
			cout << "Person::dtor: (dataP = " << dataP << ")" << endl;
		}
		virtual void getValue() const {
			cout << "dataP: " << dataP << endl;
			return;
		}
};
class Teacher : public Person {
	private:
		int dataT;
	public:
		Teacher(int x, int y = 0) : Person(x), dataT(y) {
			cout << "Teacher::ctor (dataT = " << dataT << ")" << endl;
		}
		virtual ~Teacher(){
			cout << "Teacher::dtor: (dataT = " << dataT << ")" << endl;
		}
		void getValue() const {
			Person::getValue();
			cout << "dataT: " << dataT << endl;
		}
};

class Student : public Person {
	private:
		int dataS;
	public:
		Student(int x, int y) : Person(x), dataS(y) {
			cout << "Student::ctor (dataS = " << dataS << ")" << endl;
		}
		virtual ~Student(){cout << "Student::dtor: (dataS = " << dataS << ")" << endl;}
		void getValue() const {
			Person::getValue();
			cout << "dataS: " << dataS << endl;
		}
};

int main(){
	int data_P, data_T, data_S;
	cout << "Enter data_P for Person 1: "; cin >> data_P;
	Person *ptrPerson1 = new Person(data_P);
	ptrPerson1->getValue();

	cout << "Enter data_P for Person 2: "; cin >> data_P;
	Person person2(data_P);
	Person *ptrPerson2 = &person2;
	ptrPerson2->getValue();
	cout << endl;

	cout << "Teacher 1 data:" << endl;
	cout << "data_P, data_T: "; cin >> data_P >> data_T;
	Person *ptrTeacher1 = new Teacher(data_P,data_T);
	ptrTeacher1->getValue();
	cout << endl;

	cout << "Student 1 data:" << endl;
	cout << "data_P, data_S: "; cin >> data_P >> data_S;
	Person *ptrStudent1 = new Student(data_P,data_S);
	ptrStudent1->getValue();
	cout << endl;
	
	delete ptrPerson1; cout << endl;
	delete ptrTeacher1; cout << endl;
	delete ptrStudent1; cout << endl;
	// object person2 was created statically.
	return 0;
}

/*OUTPUT:

I>
Enter data_P for Person 1: 34
Person::ctor: (dataP = 34)
dataP: 34
Enter data_P for Person 2: 12
Person::ctor: (dataP = 12)
dataP: 12

Teacher 1 data:
data_P, data_T: 34
12
Person::ctor: (dataP = 34)
Teacher::ctor (dataT = 12)
dataP: 34
dataT: 12

Student 1 data:
data_P, data_S: 34
12
Person::ctor: (dataP = 34)
Student::ctor (dataS = 12)
dataP: 34
dataS: 12

Person::dtor: (dataP = 34)

Teacher::dtor: (dataT = 12)
Person::dtor: (dataP = 34)

Student::dtor: (dataS = 12)
Person::dtor: (dataP = 34)

Person::dtor: (dataP = 12)

--------------------------------
Process exited after 20.63 seconds with return value 0
Press any key to continue . . .


II>
Enter data_P for Person 1: 23
Person::ctor: (dataP = 23)
dataP: 23
Enter data_P for Person 2: 12
Person::ctor: (dataP = 12)
dataP: 12

Teacher 1 data:
data_P, data_T: 65
32
Person::ctor: (dataP = 65)
Teacher::ctor (dataT = 32)
dataP: 65
dataT: 32

Student 1 data:
data_P, data_S: 12
11
Person::ctor: (dataP = 12)
Student::ctor (dataS = 11)
dataP: 12
dataS: 11

Person::dtor: (dataP = 23)

Teacher::dtor: (dataT = 32)
Person::dtor: (dataP = 65)

Student::dtor: (dataS = 11)
Person::dtor: (dataP = 12)

Person::dtor: (dataP = 12)

--------------------------------
Process exited after 9.008 seconds with return value 0
Press any key to continue . . .

*/



