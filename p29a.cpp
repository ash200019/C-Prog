/* NAME:  ANUBRATA DAS
 * ROLL NO: 720
 * class:B.Sc. Computer Science (Hons.)
 * SEMESTER & Year: 1ST, 2018 
 * REGISTRATION: A01-1122-117-018-2018
 */ 


/* 29.Write a program that will read 10 integers from user and store them
 * in an arryay. Implement array using pointers. The program will print 
 * the array elements ina ascending and descending order. */
#include <iostream>
using namespace std;

void selSort(int *a, int n, int order){
	int min_idx, i, j;
	for (i = 0; i < n; ++i){
		min_idx = i;
		for (j = i+1; j < n; ++j){
			if (order == 1){
				if (*(a+j) < *(a+min_idx))
					min_idx = j;
			}
			else {
				if (*(a+j) > *(a+min_idx))
					min_idx = j;
			}
		}
		if (min_idx != i)
			swap(*(a+i), *(a+min_idx));
	}
}

void printArray(int *a, int n){
	for (int i = 0; i < n; ++i)
		cout << *(a+i) << " ";
	cout << endl;
}

int main(){
	int n;
	cout << "How many elements in the array: ";
	cin >> n;
	int *a = new int[n];
	cout << "Enter the elements: ";
	for (int i = 0; i < n; ++i)
		cin >> *(a+i);
	cout << "Array elements before sorting: ";
	printArray(a,n);
	cout << "Array elements in ascending order: ";
	selSort(a,n,1);
	printArray(a,n);
	cout << "Array elements in descending order: ";
	selSort(a,n,2);
	printArray(a,n);
	delete []a;
	return 0;
}
/*OUTPUT:
I>
How many elements in the array: 6
Enter the elements: 3
4
5
6
7
8
Array elements before sorting: 3 4 5 6 7 8
Array elements in ascending order: 3 4 5 6 7 8
Array elements in descending order: 8 7 6 5 4 3

--------------------------------
Process exited after 7.022 seconds with return value 0
Press any key to continue . . .

II>
How many elements in the array: 8
Enter the elements: 2
4
5

7
8
9
0
1
Array elements before sorting: 2 4 5 7 8 9 0 1
Array elements in ascending order: 0 1 2 4 5 7 8 9
Array elements in descending order: 9 8 7 5 4 2 1 0

--------------------------------
Process exited after 9.004 seconds with return value 0
Press any key to continue . . .
*/
