/* NAME:  ANUBRATA DAS
 * ROLL NO: 720
 * class:B.Sc. Computer Science (Hons.)
 * SEMESTER & Year: 1ST, 2018 
 * REGISTRATION: A01-1122-117-018-2018
 */ 

/* 24.Create a class Box containing length, breadth and height. Include the 
 * following methods in it:
 * a. Calculate surface Area
 * b. Calcualate Volume
 * c. Increment, Overload ++operator (both prefix & postfix)
 * d. Decrement, Overload --operator (both prefix & postfix)
 * e. Overload operator == (to check equality of two boxes), as a friend function
 * f. Overload Assignment operator
 * g. Check if it is a Cube or cuboid
 * Write a program which takes input from the user for length, breadth and height
 * to test the above class. */
 
 #include <iostream>
 using namespace std;
 
 class Box {
	 private:
		 double length;
		 double breadth;
		 double height;
	 public:
		Box(double l, double b, double h): 
			length(l), breadth(b), height(h) {
				cout << "Box ctor: "; print(); cout << endl;
			}

		~Box(){ cout << "Box dtor: "; print(); cout << endl;}

		void print(){
			cout << "(L: " << length << ", B: " << breadth << ", H: " << height << ")";
		}
		
		friend ostream& operator<< (ostream& os, const Box &b) {
			os << "(" << b.length << " " << b.breadth << " " << b.height << ")";
			return os;
		}
		friend istream& operator>> (istream& is, Box &b) {
			is >> b.length >> b.breadth >> b.height;
		return is;
		}
	
		double SurfaceArea (){
			return 2.0 * (length*breadth + breadth*height + height*length);
		}
		
		double Volume(){
			return length * breadth * height;
		}
		
		Box& operator++ (){		//prefix increment operator
			++length; ++breadth; ++height;
			return *this;
		}
		
		Box operator++ (int){		//postfix increment operator
			Box b(length, breadth, height);
			++length; ++breadth; ++height;
			return b;
		}
		
		Box& operator-- (){		//prefix decrement operator
			--length; --breadth; --height;
			return *this;
		}
		
		Box operator-- (int){		//postfix decrement operator
			Box b(length, breadth, height);
			--length; --breadth; --height;
			return b;
		}
		
		Box& operator= (const Box& b){
			length = b.length; breadth = b.breadth; height = b.height;
			return *this;
		}
		
		friend bool operator== (const Box&, const Box&);
		
		void Cube_Cuboid(){
			if (length==breadth && length==height)
				cout << "It is cube" << endl;
			else
				cout << "It is cuboid" << endl;
		}
};


bool operator== (const Box& a, const Box& b){
	double x1, x2, x3, y1, y2, y3;
	if (a.length > a.breadth && a.length > a.height){
		x1 = a.length;
		if (a.breadth > a.height){x2 = a.breadth;	x3 = a.height;}
		else {x2 = a.height; x3 = a.breadth;}
	}
	else if (a.breadth > a.height) {
		x1 = a.breadth;
		if (a.length > a.height) {x2 = a.length; x3 = a.height;}
		else {x2 = a.height; x3 = a.length;}
	}
	else {
		x1 = a.height;
		if (a.breadth > a.length) {x2 = a.breadth; x3 = a.length;}
		else {x2 = a.length; x3 = a.breadth;}
	}
	
	if (b.length > b.breadth && b.length > b.height){
		y1 = b.length;
		if (b.breadth > b.height){y2 = b.breadth;	y3 = b.height;}
		else {y2 = b.height; y3 = b.breadth;}
	}
	else if (b.breadth > b.height) {
		y1 = b.breadth;
		if (b.length > b.height) {y2 = b.length; y3 = b.height;}
		else {y2 = b.height; y3 = b.length;}
	}
	else {
		y1 = b.height;
		if (b.breadth > b.length) {y2 = b.breadth; y3 = b.length;}
		else {y2 = b.length; y3 = b.breadth;}
	}
	return (x1==y1 && x2==y2 && x3==y3);
}

int main()	
{
	double length, breadth, height;
	cout << "Enter dimensions of the box: ";
	cin >> length >> breadth >> height;
	Box b1(length,breadth,height);
	cout << "Surface Area = " << b1.SurfaceArea() << endl;
	cout << "Volume = " << b1.Volume() << endl;

	cout << "New dimensions of box b1 after pre-increment: ";
	cout << ++b1 << endl;

	cout << "New dimensions of box b1 after pre-decrement: ";
	cout << --b1 << endl;	

	cout << "Post-increment" << endl;
	Box b2(b1++);
	cout << "Dimensions of the new box b2: " << b2 << endl;
	cout << "Dimensions of the original box b1: " << b1 << endl;

	cout << "Post-decrement" << endl;
	Box b3(b1--);
	cout << "Dimensions of the new box b3: "; b3.print(); cout << endl;
	cout << "Dimensions of the original box b1: "; b1.print(); cout << endl;
	
	if (b1 == b3)
		cout << "Boxes b1 and b3 are equal" << endl;
	else
		cout << "Boxes b1 and b3 are not equal" << endl;
	
	if (b1 == b2)
		cout << "Boxes b1 and b2 are equal" << endl;
	else
		cout << "Boxes b1 and b2 are not equal" << endl;
	
	Box b4(breadth,length,height);
	cout << "New box b4 has been created. It's dimensions are: " << b4 << endl;
	if (b1 == b4)
		cout << "Boxes b1 and b4 are equal" << endl;
	else
		cout << "Boxes b1 and b4 are not equal" << endl;
	cout << "Box b1: "; b1.Cube_Cuboid();

	return 0;
}

/*OUTPUT:

I>
Enter dimensions of the box: 2
2
3
Box ctor: (L: 2, B: 2, H: 3)
Surface Area = 32
Volume = 12
New dimensions of box b1 after pre-increment: (3 3 4)
New dimensions of box b1 after pre-decrement: (2 2 3)
Post-increment
Box ctor: (L: 2, B: 2, H: 3)
Dimensions of the new box b2: (2 2 3)
Dimensions of the original box b1: (3 3 4)
Post-decrement
Box ctor: (L: 3, B: 3, H: 4)
Dimensions of the new box b3: (L: 3, B: 3, H: 4)
Dimensions of the original box b1: (L: 2, B: 2, H: 3)
Boxes b1 and b3 are not equal
Boxes b1 and b2 are equal
Box ctor: (L: 2, B: 2, H: 3)
New box b4 has been created. It's dimensions are: (2 2 3)
Boxes b1 and b4 are equal
Box b1: It is cuboid
Box dtor: (L: 2, B: 2, H: 3)
Box dtor: (L: 3, B: 3, H: 4)
Box dtor: (L: 2, B: 2, H: 3)
Box dtor: (L: 2, B: 2, H: 3)

--------------------------------
Process exited after 230.1 seconds with return value 0
Press any key to continue . . .

II>
Enter dimensions of the box: 2
2
3
Box ctor: (L: 2, B: 2, H: 3)
Surface Area = 32
Volume = 12
New dimensions of box b1 after pre-increment: (3 3 4)
New dimensions of box b1 after pre-decrement: (2 2 3)
Post-increment
Box ctor: (L: 2, B: 2, H: 3)
Dimensions of the new box b2: (2 2 3)
Dimensions of the original box b1: (3 3 4)
Post-decrement
Box ctor: (L: 3, B: 3, H: 4)
Dimensions of the new box b3: (L: 3, B: 3, H: 4)
Dimensions of the original box b1: (L: 2, B: 2, H: 3)
Boxes b1 and b3 are not equal
Boxes b1 and b2 are equal
Box ctor: (L: 2, B: 2, H: 3)
New box b4 has been created. It's dimensions are: (2 2 3)
Boxes b1 and b4 are equal
Box b1: It is cuboid
Box dtor: (L: 2, B: 2, H: 3)
Box dtor: (L: 3, B: 3, H: 4)
Box dtor: (L: 2, B: 2, H: 3)
Box dtor: (L: 2, B: 2, H: 3)

--------------------------------
Process exited after 230.1 seconds with return value 0
Press any key to continue . . .
*/
