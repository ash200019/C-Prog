/* NAME:  ANUBRATA DAS
 * ROLL NO: 720
 * class:B.Sc. Computer Science (Hons.)
 * SEMESTER & Year: 1ST, 2018 
 * REGISTRATION: A01-1122-117-018-2018
 */ 

/* 21.Create Matrix class. Write a menu-driven program to
 * perform following Matrix operations (a 2-D implementaion):
 * a) Sum  b) Difference  c) Product  d) Transpose  */
 
#include <iostream>
using namespace std;

class Matrix {
	private:
		int **p;
		int m, n;
	public:
		Matrix(int row = 2, int col = 2) {
			m = row;
			n = col;
			p = new int* [m];
			for (int i = 0; i < m; ++i)
				p[i] = new int[n];
		}
		Matrix(const Matrix& a) {
			m = a.m;
			n = a.n;
			p = new int* [m];
			for (int i = 0; i < m; ++i)
				p[i] = new int[n];
			for (int i = 0; i < m; ++i)
				for (int j = 0; j < n; ++j)
					p[i][j] = a.p[i][j];
		}
		~Matrix() {
			for (int i = 0; i < m; ++i)
				delete p[i];
			delete p;
		}
		void accept() {
			cout << "Enter matrix elements: "
				<< m << " Rows and " << n << " Columns" << endl;
			for(int i = 0; i < m; ++i) {
				cout << "Row " << i+1 << ":" << endl;
				for(int j = 0; j < n; ++j)
					cin >> p[i][j];
			}
		}

		void display() {
			cout << "The matrix is:" << endl;
			for(int i = 0; i < m; ++i) {
				for(int j = 0; j < n; ++j)
					cout << p[i][j] << " ";
				cout << endl;
			}
		}

		Matrix operator -(Matrix & m2) {
			Matrix A(m, n);
			for(int i = 0; i < m; ++i) {
				for(int j = 0; j < n; ++j) {
					A.p[i][j] = p[i][j] - m2.p[i][j];
				}
			}
			return A;
		}
	
		void transpose() {
			cout << "Transpose of the given matrix" << endl;
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < m; ++j)
					cout << p[j][i] << " ";
				cout << endl;
			}
		}
	
		Matrix operator +(const Matrix & m2) {
			Matrix A(m, n);
			for(int i = 0; i < m; ++i) {
				for(int j = 0; j < n; ++j) {
					A.p[i][j] = p[i][j] + m2.p[i][j];
				}
			}
			return A;
		}
		
		Matrix& operator = (const Matrix& a) {
			for (int i = 0; i < m; ++i)
				for (int j = 0; j < n; ++j)
					p[i][j] = a.p[i][j];
			return *this;
		}
		friend Matrix operator * (Matrix&, Matrix&);
};

Matrix operator * (Matrix& a , Matrix& b) {
//	if(a.n == b.m) {
	Matrix c(a.m, b.n);
	for(int i = 0; i < a.m; i++) {
		for(int k = 0; k < b.n; k++) {
			c.p[i][k] = 0;
			for(int j = 0; j < a.n; j++)
				c.p[i][k] += a.p[i][j] * b.p[j][k];
		}
	}
	return c;
}

int main() {
	Matrix a(3,4);
	cout << "Matrix A" << endl;
	a.accept(); a.display();

	cout << "Matrix B" << endl;
	Matrix b(3,4);
	b.accept(); b.display();
	
	cout << "Matrix C" << endl;
	Matrix c(4,5);
	c.accept(); c.display();
	
	Matrix d(3,4), e(3,5);
	
	int option;
	do {
		cout << endl;
		cout << "1. Sum: [d = a + b]" << endl;
		cout << "2. Difference: [d = a - b]" << endl;
		cout << "3. Product: e[e = a * c]" << endl;
		cout << "4. Transpose of c" << endl;
		cout << "5. Quit the program" << endl << endl;
		do {
			cout << "Select an option (1 - 5): ";
			cin >> option;
		} while (option < 1 || option > 5);
		cout << endl;
		switch (option) {
			case 1: d = a + b;
				cout << "Sum of A and B:" << endl;
				d.display();
				break;
			case 2: d = a - b;
				cout << "Difference of A and B:" << endl;
				d.display();
				break;
			case 3: e = a * c;
				cout << "Product of A and C:" << endl;
				e.display();
				break;
			case 4:	cout << "Transpose of A:" << endl;
				a.transpose();
				break;
			case 5: printf("Quitting the program\n");
		}
	} while (option != 5);
	return 0;
}

/*OUTPUT:

Matrix A
Enter matrix elements: 3 Rows and 4 Columns
Row 1:
2
3

4
5
Row 2:
67
1
2
3
Row 3:
4
5
6
7
The matrix is:
2 3 4 5
67 1 2 3
4 5 6 7
Matrix B
Enter matrix elements: 3 Rows and 4 Columns
Row 1:
8
1
5
6
Row 2:
7
8
9
2
Row 3:
3
4
5
6
The matrix is:
8 1 5 6
7 8 9 2
3 4 5 6
Matrix C
Enter matrix elements: 4 Rows and 5 Columns
Row 1:
7
7
8
9
1
Row 2:
2
3
4
6
7
Row 3:
8
1
2
3
4
Row 4:
6
6
7
8
1
The matrix is:
7 7 8 9 1
2 3 4 6 7
8 1 2 3 4
6 6 7 8 1

1. Sum: [d = a + b]
2. Difference: [d = a - b]
3. Product: e[e = a * c]
4. Transpose of c
5. Quit the program

Select an option (1 - 5): 1

Sum of A and B:
The matrix is:
10 4 9 11
74 9 11 5
7 9 11 13

1. Sum: [d = a + b]
2. Difference: [d = a - b]
3. Product: e[e = a * c]
4. Transpose of c
5. Quit the program

Select an option (1 - 5): 2

Difference of A and B:
The matrix is:
-6 2 -1 -1
60 -7 -7 1
1 1 1 1

1. Sum: [d = a + b]
2. Difference: [d = a - b]
3. Product: e[e = a * c]
4. Transpose of c
5. Quit the program

Select an option (1 - 5): 3

Product of A and C:
The matrix is:
82 57 71 88 44
505 492 565 639 85
128 91 113 140 70

1. Sum: [d = a + b]
2. Difference: [d = a - b]
3. Product: e[e = a * c]
4. Transpose of c
5. Quit the program

Select an option (1 - 5): 4

Transpose of A:
Transpose of the given matrix
2 67 4
3 1 5
4 2 6
5 3 7

1. Sum: [d = a + b]
2. Difference: [d = a - b]
3. Product: e[e = a * c]
4. Transpose of c
5. Quit the program

Select an option (1 - 5): 5

Quitting the program

--------------------------------
Process exited after 45.82 seconds with return value 0
Press any key to continue . . .

*/
