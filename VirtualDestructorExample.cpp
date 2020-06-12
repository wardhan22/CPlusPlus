#include <iostream>
using namespace std;

class Base
{
	int v;
	
protected:
	int  * p;
public:
	int x;
	virtual ~Base()
	{
		delete p;
		cout << "Base destructor called\n";
	}
	Base()
	{
		p = new int(5);
	}
	void fun()
	{
		cout << " Base Fun(non virtual)\n";
	}

	virtual void fun1()
	{
		cout << " Base fun1(Virtual)\n";
	}

};

class Derived :public Base
{
	int *q;
public:
	int x;
	Derived()
	{
		q = new int(20);
		p = new int(10);
	}
	 ~Derived()
	{
		delete q;
		delete p;
		p = nullptr;
		cout << "Derived destructor called\n";
	}
	void fun()
	{
		cout << " Derived fun(non virtual)\n";
	}

	void fun1()
	{
		cout << " Derived fun1(virtual)\n";
	}
};

int main()
{
	Base b1;
	Derived d1;
	Base * bb;
	Base * bb1 = new Base();
	Derived * dd;
	Derived *dd1 = new Derived;
	Base *b = new Derived();
	
	delete b;
}