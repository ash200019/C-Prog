/* NAME:  ANUBRATA DAS
 * ROLL NO: 720
 * class:B.Sc. Computer Science (Hons.)
 * SEMESTER & Year: 1ST, 2018 
 * REGISTRATION: A01-1122-117-018-2018
 */ 


/*26.Write a program to retrieve the student information from file created 
 * in the previous question and print it in the following format:
   Roll No.   Name		Marks
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	ifstream infile;
	infile.open("students.txt", ios::in);
	if (!infile){
		cerr << "Could not open input file: students.txt" << endl;
		exit(EXIT_FAILURE);
	}
	const int maxLen = 20;	// name string
	struct Student {
		int rollno;
		char name[maxLen];
		int sclass;
		int year;
		int total;
	};
	struct Student s;
	
	
	cout << left << setw(10) << "Roll No." << setw(maxLen+2) << "Name" << setw(5) << "Marks" << endl;
	for (int i = 0; i < 3; ++i) {
		infile >> s.rollno >> s.name >> s.sclass >> s.year >> s.total;
		cout << left << setw(10) << s.rollno << setw(maxLen+2) << s.name << setw(5) << s.total << endl;
	}
	infile.close();
	return 0;
}
/*OUTPUT:

Roll No.  Name                  Marks
2         ABC                   234
4         PQR                   238
9         XYZ                   334

--------------------------------
Process exited after 1.364 seconds with return value 0
Press any key to continue . . .+99565

