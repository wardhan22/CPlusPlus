#include <iostream>
#include <thread>
using namespace std;

void foo(int &y)
{
	
	auto fn =	[](int &x)
	{
		cout << "This is thread 2 x: ";
		x++;
		cout << x << endl;

	};
	fn(y);
}
//int main()
//{
//	auto fn = [](int &x)
//	{
//		cout << "This is thread 1 x: ";
//		x++;
//		cout << x << endl;
//	};
//
//	int y = 10;
//	fn(y);
//	cout << y << endl; // y value has become 11 now
//	
//	thread th(foo, ref(y));  // passing arguments by refernce
//
//	th.join(); //if this statement is no there or there at end, the main thread may have put old value of y. i.e y is printed before execution of th thread is finished
//	cout << y << endl; 
//
//	thread th1([](int &x)
//	{
//		cout << "This is thread 3 x: ";
//		x++;
//		cout << x << endl;
//	}, ref(y)); //use ref to pass by reference
//	
//	cout << y << endl;; //Here 12 is printed because main thread execute this statement before th1 could update y.
//	th1.join(); // if we put this join before printing y, then updated value of y would have printed.
//	return 0;
//}