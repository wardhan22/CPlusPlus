#include <iostream>
#include<functional>
using namespace std::placeholders;
using namespace std;

void fun(int x)
{
	cout << "Fun called "<<x<<"\n";
}

void boo(int x, int y, int z)
{
	cout << "Fun2 called " << x << " " << y << " " << z << endl;
}

class A
{
	function<void(int)> fn;
public:
	void test(const function<void(int)> &f) // constant reference
	{
		fn = f;
		fn(10);
	}
	void operator()()
	{
		cout << "Functor\n";
	}
};

int main()
{
	//Lambda 
	int x = 10;
	auto f = [&] () ->int {
		x++;
		cout << x;
		return x;
	};
	cout<<f();
	cout << x;

	// Std::function and std::Bind
	function<void(int)> fn;
	fn = fun; //function<void(int)> is used in place of function pointer
	fn(10);
	
	function<void()> fn1; // here no need to specify argument as int because we are going to pass value via bind
	fn1 = bind(fun, 10); // passing 10 as parameter to fun1. 
	fn1();

	function<void(int)> fn2;
	fn2 = bind(fun, _1); // use namespace std::placeholders;Here _1 is placeholder. 
	fn2(10);

	function<void()> boo1; // here argument list is empty
	boo1 = bind(boo, 10, 20, 30);
	boo1();

	function<void(int)> boo2; // here argument list is empty
	boo2 = bind(boo, 10, 20, _1);  // _1 is place holder
	boo2(30);

	// placeholder can be used to change the order as well

	boo2 = bind(boo, _1, 10, 20);
	boo2(30);


	// function can also be used to store funtor as well as lambda

	function<void()> lambda = []() {cout << "Lambda called\n"; };
	lambda();
	A obj;
	function<void()> functor = obj;
	functor();

	/*we can also store lambda, function and functors in a vector of std::function*/


	A obj1;
	obj.test(fun);
	obj.test([](int x) {cout << "Lambda called "<<x<<"\n"; });
	return 0;
}