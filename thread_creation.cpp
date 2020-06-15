#include<iostream>
#include<thread>
#include <functional>
using namespace std;

void fun()
{
	cout << "Fun called\n";
}
int fun(int x)
{
	x++;
	cout << "Fun called with x: " << x << endl;
	return x;
}

void boo()
{
	cout << "Thread creation\n";
}

class A
{
public:
	void operator()()
	{
		cout << "Function object(functor) called\n";
	}
};

int main()
{
	// thread creation using function pointer (functions)
	int(*fptr)(int);
	fptr = fun;  // overloaded functions can be passed to thread via function pointer
	cout << "Main begin\n";
	thread th(fptr,10);
	cout << "Main End\n";

	//thread th1;
	//th1 = thread(fptr);
	
	thread th1(boo); // creating thread by passing function (Function pointer)


	//thread creation using lambda
	thread th2([](int x) {cout << "Lambda x: " << x << endl; }, 10);

	//thread creation using function object (functors)
	A obj;
	thread th3(obj); // functor will be called. No need to pass like obj()

	thread th4((A())); // Double brackets are necessary if passed directly. 

	th.join();
	//th.join(); // call join on same thread twice will give error in run time. 
	th1.join();
	th2.join();
	th3.join();
	th4.join();  
	return 0;
}