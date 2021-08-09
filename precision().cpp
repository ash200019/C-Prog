#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i;
	cout<<"Precision set to 3 digits: "<<endl;
	cout.precision(3);
	cout.width(10);
	cout<<"VALUE";
	cout.width(15);
	cout<<"SQRT_OF_VALUE"<<endl;
	for(i=1;i<=5;i++)
	{
		cout.width(8);
		cout<<i;
		cout.width(13);
		cout<<sqrt(i)<<endl;
	}
	cout<<"Precision set to 5 digits"<<endl;
	cout.precision(5);
	cout<<"sqrt(10) = "<<sqrt(10)<<endl;
	cout.precision(0);
	cout<<"sqrt(10) = "<<sqrt(10)<<" (default precision)"<<endl;
	return 0;
}
