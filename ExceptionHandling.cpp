#include <iostream>
#include <exception>
#include<stdexcept> // to use runtime_error
using namespace std;

class Base
{
	int *p;
public:
	Base()
	{
		cout << "Base constructor\n";
		//throw 10; // Base constructor will not be called as object construction couldn't complete
	}
	~Base()
	{
		cout << "Base Destructor\n";
	}
};
class Derived :public Base
{
public:
	Derived()
	{
		cout << "Derived constructr\n";
		//throw 10; // Derivd destructor will not be called but base destructor will be called as base object construction done successfully
	}
	~Derived()
	{
		cout << "Derived Destructor\n";
	}
};

int main()
{
	try
	{
		int x = 10;
		int y = 0;
		if (y == 0)
			throw runtime_error("divide by zero exception");  
		int z = x / y;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	//Below scenario is when exception is thrown in constructor..either base or derived	
		/*try {
			Derived d;
		}
		catch(int b) {
		cout<<"Caught Exception\n";
		}
		catch(...) {
		cout<<"Caught Generic Exception";
		}*/

   //if exception is thrown after object creation both cons and dest will be called
		try
		{
			Derived dd;
			throw 10;
		}
		catch (int b) {
			cout << "Caught Exception\n";
		}
		catch (...) {
			cout << "Caught Generic Exception";
		}

	return 0;
}