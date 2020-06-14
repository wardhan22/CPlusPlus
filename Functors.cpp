#include <iostream>
using namespace std;
class A
{
	int y;
public:
	A(int z):y(z){}

	void operator()()
	{
		cout << "Functor called\n";
	}
	void operator()(int x)
	{
		y=y + x;
		cout << "Functor called " << x << endl;
	}
	void print() { cout << y << endl; }
};
int main()
{
	A obj(10); // constructor call..y is set to 10
	obj.print();
	obj(5); // call to operator()..value of y will be incremented to 5
	obj.print();
	return 0;
}