#include <iostream>
using namespace std;

class Base
{
protected:  // if protected is used, in main we won't be able to access below methods via BAse pointer
public:
	void fun()
	{
		cout << this;  // this will point to type of object pointer stores...not the type of pointer. Virtual, non virtual doesn't matter
		cout << " Base Fun(non virtual)\n";
	}

	virtual void fun1()
	{
		cout << this; // this will point to type of object pointer stores...not the type of pointer
		cout << " Base fun1(Virtual)\n";
	}

};

class Derived :public Base
{
private:  // base class pointer can call virtual method of derived class declared private
	void fun()
	{
		cout << this;// this will point to type of object pointer stores...not the type of pointer
		cout << " Derived fun(non virtual)\n";
	}

	void fun1()
	{
		cout << this;// this will point to type of object pointer stores...not the type of pointer
		cout << " Derived fun1(virtual)\n";
	}
};

//int main()
//{
//	Base *bb = new Derived;
//	Base *b;;
//	Derived d;
//	//d.fun(); // make derived scope public
//	//d.fun1();
//	b = &d;
//	b->fun();
//	b->fun1();
//	b = new  Base();
//	b->fun();
//	b->fun1();
//	//b->fun(); //compilation error..fun is inacessible in main because in Base it is declared via protected 
//	//b->fun1(); // The pointer is of type BAse. So method should be public to use in base.
//}