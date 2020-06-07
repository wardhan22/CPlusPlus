//Multiple inheritance and ambiguity handling

#include <iostream>
using namespace std;
class Base1
{
	
public:
	int x;
	void fun()
	{
		cout << "Base 1 Fun\n";
	}
	Base1()
	{
		cout << "Base1 construtor\n";
	}
	Base1(int x):x(x)
	{
		cout << "Base1 parameterized construtor "<<x<<"\n";
	}
	~Base1()
	{
		cout << "Base1 Destrutor\n";
	}
};
class Base2
{
	
public:
	int x;
	void fun()
	{
		cout << "Base 2 Fun\n";
	}

	Base2(int x):x(x)
	{
		cout << "Base2 parameterized construtor " << x << "\n";
	}
	Base2()
	{
		cout << "Base2 construtor\n";
	}
	~Base2()
	{
		cout << "Base2 Destrutor\n";
	}
};
class Derived :public Base1, public Base2
{
public:
	Derived():Base2(20), Base1(10)  // order of call in initializer list do not matter
	{								// object of one class can be initialized only once
		cout << "Derived constructor, values are: Base1: ";
		cout << Base1::x << " Base2: ";;
		cout << Base2::x<<endl;
	}
	~Derived()
	{
		cout << "Derived destructor\n";
	}
};
// uncomment main to run this program..

int main()
{
	Derived d;
	d.Base1::fun();  // resolve ambiguous call...fun is present in both Base1, base2 
	d.Base2::fun();
	cout << endl;
	return 0;
}
