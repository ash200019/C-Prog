/* NAME:  ANUBRATA DAS
 * ROLL NO: 720
 * class:B.Sc. Computer Science (Hons.)
 * SEMESTER & Year: 1ST, 2018 
 * REGISTRATION: A01-1122-117-018-2018
 */

/* 25. Create a structure Student containing fields for RollNo, Name, Class,
 * Year and Total Marks. Create 10 students and store them in a file. */
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
	const int maxLen = 20;	
	const int size = 3;		
	struct Student {
		int rollno;
		char name[maxLen];
		int sclass;
		int year;
		int total;
	};
	struct Student data[size];
	for (int i = 0; i < size; ++i){
		cout << "Data for student " << i+1 << ":" << endl;
		cout << "Roll No.(101-999): "; cin >> data[i].rollno; getchar();
		cout << "Name (MaxLength:" << maxLen-1 <<"): "; cin.getline(data[i].name,maxLen);
		cout << "Class (1 - 12): "; cin >> data[i].sclass;
		cout << "Year (yyyy): "; cin >> data[i].year;
		cout << "Total Marks (101-999): "; cin >> data[i].total;
	}
	
	ofstream outfile;
	outfile.open("students.txt");
	for (int i = 0; i < size; ++i){
		outfile << data[i].rollno << "\n";
		outfile << data[i].name << "\n";
		outfile << data[i].sclass << "\n";
		outfile << data[i].year << "\n";
		outfile << data[i].total << "\n";
	}
	outfile.close();
	return 0;
}

/*OUTPUT:
I>
Data for student 1:
Roll No.(101-999): 1
Name (MaxLength:19): SARBAJIT
Class (1 - 12): 11
Year (yyyy): 2018
Total Marks (101-999): 456
Data for student 2:
Roll No.(101-999): 2
Name (MaxLength:19): NILESH
Class (1 - 12): 11
Year (yyyy): 2018
Total Marks (101-999): 433
Data for student 3:
Roll No.(101-999): 3
Name (MaxLength:19): SOHAM
Class (1 - 12): 11
Year (yyyy): 2018
Total Marks (101-999): 411

--------------------------------
Process exited after 54.25 seconds with return value 0
Press any key to continue . . .

II>
Data for student 1:
Roll No.(101-999): 2
Name (MaxLength:19): ABC
Class (1 - 12): 12
Year (yyyy): 2000
Total Marks (101-999): 234
Data for student 2:
Roll No.(101-999): 4
Name (MaxLength:19): PQR
Class (1 - 12): 11
Year (yyyy): 2000
Total Marks (101-999): 238
Data for student 3:
Roll No.(101-999): 9
Name (MaxLength:19): XYZ
Class (1 - 12): 11
Year (yyyy): 2016
Total Marks (101-999): 334

--------------------------------
Process exited after 54.3 seconds with return value 0
Press any key to continue . . .
*/
