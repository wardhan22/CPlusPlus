#include<iostream>
using namespace std;

void funx()
{
	cout << "Fun called\n";
}

class A
{
	
public:
	int x;
	void(A::*fptr)(); //Need to use A::   // Function pointer
	void foo()
	{
		cout << "Foo called\n";
	}
	void bar(int x)
	{
		cout << "Bar called\n";
	}

	void test(void(*fptr)())
	{
		cout << "Test called\n";
		fptr();
	}

	void test(void(*fptr)(int x))
	{
		cout << "Test called\n";
		fptr(10);
	}

	void test(void(A::*fptr)())  // pointer to member function declaration ..use className::
	{
		cout << "Test called..This method can point to member function. Foo will be called\n";
		//fptr();// error
		(this->*fptr)(); // correct syntax..use std::function
	}
};
//
//int main()
//{
//	int A::*x = &A::x; // pointer to member variable
//
//	A obj;
//	obj.*x = 10; // changin value of pointer to member variable
//	cout << obj.x<< endl;
//	obj.test(funx);  // passing global method to test
//
//	//obj.test(obj.foo); // error during compilation. To fix this declare new test mehod with that points to member functions using className::
//	obj.test(&A::foo); // use &A:: to pass member function
//
//	obj.fptr = &A::foo;
//	(obj.*(obj.fptr))();  // complex syntax... (object.*(object.functionPointer))()
///*  obj.fptr--> return address which is stores in function pointer fptr
//	*(obj.fptr)--> dereferncing value at fptr which is nothing but a function
//	
//	obj.*(obj.fptr)() --> calling that function via obj as it is memeber function of class A. Last bracket is to call function
//	*/	
//
//	return 0;
//}