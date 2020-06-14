//Reference geeksforgeeks.org   
#include<iostream> 
using namespace std;

class Base {
public:
	Base()
	{
		cout << "base\n";
	}
	~Base()
	{
		cout << "~base\n";
	}
};
class Derived : public Base {
public:
	Derived()
	{
		cout << "Derived\n";
	}

	~Derived()
	{
		cout << "~Derived\n";
	}
};
//int main()
//{
//	Derived d;
//	try {
//	
//		throw d;  // A new object will be created. Multiple constructor and destructor are getting called. Need to check reason behind this
//	}
//	catch (Base b) {
//		cout << "Caught Base Exception\n";
//	}
//	catch (Derived d) { 
//		cout << "Caught Derived Exception\n";
//	}
//	getchar();
//	return 0;
//}
