/*
 * copy_constructor.cpp
 *
 *  Created on: Jan 1, 2021
 *      Author: Hardik
 *
 * Copy constructor is a constructor used to create a new object as a copy of existing object.
 * - When copy constructor is called ?
 *   Copy constructor called when we create a new object from existing object. For Example,
 *   	A a;  // Default constructor call!
 *   	A b = a; //Copy constructor call! As b is uninitialized and new object;
 *   	A c;
 *   	c = b // No copy constructor called because  c & b both are already initialized.
 *   	A d(c) //Explicit call of the copy constructor.
 * Compiler defines the default copy constructor in each class. However, copy constructor define by
 * compile may not sufficient/useful in some scenario. For example, Class A & Class B both are
 * different class and want to create object of class B from Class A object.
 * 		A a
 * 		B b = a; // here default copy constructor will not work, we have to rewrite copy constructor.
 */

#include <iostream>
#include <vector>

using namespace std;

static int count = 0;
class A {
	friend class B;
	int a;
	int b;
public:
	 A() : a(0), b(0){}

	 //user defined copy constructor
	 // First Argument must be the object pass by reference to avoid the
	 // recursive call of the copy constructor.
	 A(const A &a_ref) {
		std:: cout << "Copy Constructor A" << std::endl;
		this->a = a_ref.a;
		this->b = a_ref.b;
		count++;
	}

	void print (void) {
		//std:: cout << a << ": " << b << std::endl;
		std:: cout << count << std::endl;
	}
};


class B {
	int aa;
	int bb;
public:
	 B() : aa(0), bb(0){}


	 //user defined copy constructor to copy the object a into b
	 // First Argument must be the object pass by reference to avoid the
	 // recursive call of the copy constructor.
	 B(const A &a_ref) {
		std:: cout << "Copy Constructor B" << std::endl;
		this->aa = a_ref.a;
		this->bb = a_ref.b;
		count++;
	}

	 // user defined copy constructor
	 // First Argument must be the object pass by reference to avoid the
	 // recursive call of the copy constructor.
	 B(const B &b_ref) {
			std:: cout << "Copy Constructor B - 2" << std::endl;
			this->aa = b_ref.aa;
			this->bb = b_ref.bb;
			count++;
		}


	void print (void) {
		//std:: cout << a << ": " << b << std::endl;
		std:: cout << count << std::endl;
	}
};

int main (void) {

	A a;
	A aa = a; //Class A copy constructor called.

	B b = a; //Copy Constructor B called
	B bb = b; //Copy Constructor B - 2 called

	b.print();
	bb.print();
	aa.print();

	count = 0;
	/*
	 * problem with copy constructor + STL (Vector).
	 * In following for loop, 10 objects are
	 * pushing into vector but the copy constructor called 25 times.
	 * This is because of dynamic memory allocation inside the vector (probably) on each push_back.
	 */

	std::vector<A> obj_vec;
	for (int i = 0;i < 10; i++) {
		obj_vec.push_back(A());
	}
	std::cout << count << std::endl;

	count = 0;
	obj_vec.clear();

	/**
	 * Following line will resolve the above issue. We allocate the required memory block
	 * before pushing the object. This will prevent the memory extension and copying the
	 * object in new memory.
	 */
	obj_vec.reserve(10);
	for (int i = 0;i < 10; i++) {
		obj_vec.push_back(A());
	}
	std::cout << count << std::endl;
	return 0;
}



