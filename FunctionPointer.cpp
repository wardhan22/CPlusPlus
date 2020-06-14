#include <iostream>
using namespace std;
void fun()
{
	cout << "Fun called\n";
}
void fun1(int x)
{
	cout << "Fun1 called\n";
}
int fun2(int x, int y)
{
	cout << "Fun2 Called\n";
	return 10;
}

void TestFun(void(*fptr)())
{
	cout << "TestFun called\n";
	fptr();
}

void TestFun2(int(*fptr(int x, int y)))
{
	cout << "TestFun2 called\n";
	fptr(10, 20);
}

//int main()
//{
//	//TestFun(fun()); // error fun() should be passed without round brackets(). only function name should be passed 
//	TestFun(fun);
//	void(*fptr)() = fun;
//	fptr();
//
//	 // OR
//
//	void(*ff)();
//	ff = fun;
//	ff();
//
//	void(*fPtr1)(int x);
//	//fPtr1 = fun1(10); // error...never pass value here...
//	fPtr1 = fun1;
//	fPtr1(10); // values to arguments of function
//}