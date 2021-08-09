/* NAME:  ANUBRATA DAS
 * ROLL NO: 720
 * class:B.Sc. Computer Science (Hons.)
 * SEMESTER & Year: 1ST, 2018 
 * REGISTRATION: A01-1122-117-018-2018
 */ 

/* 28.Write a function that reverses the elements of an array in place.
 * The function must accept only one pointer value and return void. */
#include <iostream>
using namespace std;
template <typename T> 
void reverse(T *a, int n){
	for (int i = 0; i < n/2; ++i)
		swap(a[i],a[n-1-i]);
}

template <typename T>
void printArray(T *a, int n){
	for (int i = 0; i < n; ++i)
		cout << *(a+i) << " ";
	cout << endl;
}

int main(){
	int n;
	cout << "How many elements in the array: ";
	cin >> n;

	double *a = new double[n];
	cout << "Enter the elements: ";
	for (int i = 0; i < n; ++i)
		cin >> *(a+i);
	cout << "Original Array: ";
	printArray(a,n);
	reverse(a,n);
	cout << "Reverse Array: ";
	printArray(a,n);
	delete []a;
	return 0;
}

/*OUTPUT:
I>
How many elements in the array: 6
Enter the elements: 1
2
3
4
5
6
Original Array: 1 2 3 4 5 6
Reverse Array: 6 5 4 3 2 1

--------------------------------
Process exited after 6.167 seconds with return value 0
Press any key to continue . . .

II>
How many elements in the array: 5
Enter the elements: 4
5
3
1
0
Original Array: 4 5 3 1 0
Reverse Array: 0 1 3 5 4

--------------------------------
Process exited after 7.582 seconds with return value 0
Press any key to continue . . .
*/

