//Diamond Problem and ambiguity handling
#include <iostream>
using namespace std;
class Parent
{
protected:
	int x;
public:

	Parent()
	{
		cout << "Parent constructor\n";
	}
	Parent(int x)
	{
		cout << "Parent parameterised constructor "<<x<<"\n";
	}
	void fun()
	{
		cout << "fun in parent\n";
	}

	~Parent()
	{
		cout << "Parent destructor\n";
	}
};
class Child1 :virtual public Parent // with virtual parent will be called only one time
{

public:
	int x;
	Child1()
	{
		cout << "Child1 construtor\n";
	}
	Child1(int x) :x(x), Parent(x)
	{
		cout << "Child1 parameterized construtor " << x << "\n";
	}
	~Child1()
	{
		cout << "Child1 Destrutor\n";
	}
};
class Child2 :virtual public Parent
{

public:
	int x;							
	Child2(int x) :x(x),Parent(x)  // this parent(5) will be ignored and can be removed if deafult constructor is avilable in PArent class
	{								// call to parent constructor will be through grandchild initilizer list
		cout << "Child2 parameterized construtor " << x << "\n";
	}
	Child2()
	{
		cout << "Child2 construtor\n";
	}
	~Child2()
	{
		cout << "Child2 Destrutor\n";
	}
};
class GrandChild :public Child1, public Child2
{
public:
	GrandChild() :Child1(), Child2()  // order of call in initializer list do not matter
	{								// object of one class can be initialized only once
		cout << "GrandChild constructor\n";
	}
	GrandChild(int x) :Child1(10), Child2(20),Parent(5) // parent(5) will call the Parent parameterised constructor
	{													// if parent(5) is not used default will be called
		cout << "GrandChild constructor\n";
	}
	~GrandChild()
	{
		cout << "GrandChild destructor\n";
	}
};

/*
int main()
{
	//GrandChild d; // parent will be called two times if virtual is not used
	GrandChild d1(20); 
	d1.Child1::fun();
	cout << endl;
	return 0;
}
*/