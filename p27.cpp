/* NAME:  ANUBRATA DAS
 * ROLL NO: 720
 * class:B.Sc. Computer Science (Hons.)
 * SEMESTER & Year: 1ST, 2018 
 * REGISTRATION: A01-1122-117-018-2018
 */ 

/*27. copy the contents of one text file to another file, after removing
 * all whitespaces. In C++, whitespace refers primarily to spaces, tabs,
 * and (sometimes) newlines.*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
	char ch;
	ifstream infile;
	ofstream outfile;
	
	infile.open("file1.txt", ios::in);
	if (!infile){
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	
	outfile.open("file2.txt", ios::out);
	if (!outfile){
		cerr << "File could not be opened for writing" << endl;
		exit(EXIT_FAILURE);
	}
	
	cout << "Contents of the inputfile:" << endl;
	while(infile){
		infile.get(ch);
		cout << ch;
		if (ch != ' ' && ch != '\t' && ch != '\n')
			outfile.put(ch);
	}
	
	infile.close();
	outfile.close();
	return 0;
}

/*OUTPUT:

File could not be opened

--------------------------------
Process exited after 0.09082 seconds with return value 1
Press any key to continue . . .

*/

