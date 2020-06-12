#include<iostream>
using namespace std;
//Reference geeksforgeeks.org
class Array
{
	int *arr;
	int size;
public:
	Array(int x)
	{
		arr = new int[x];
		size = x;
	}
	int &operator [](int x)
	{
		if (x >= size)
		{
			cout << "Error...out of bond index\n";
			exit(0);
		}
		return arr[x];
	}
};
class Conversion
{
public:
	int num, den;
	Conversion(int x = 0, int y = 0)
	{
		num = x; den = y;
	}
};

class Fraction
{
	int numerator;
	int denominator;
public:
	operator double()
	{
		return numerator / denominator;
	}

	operator int()
	{
		return numerator * denominator;
	}

	operator Conversion()
	{
		return Conversion(numerator,denominator);
	}
	Fraction(int x, int y)
	{
		numerator = x;
		denominator = y;
	}

};

class NewDelete
{
public:

void * operator new(size_t n)
{
	
	cout << "new called\n";
	return malloc(n);
}

void * operator new[](size_t n)
{
	cout << "new [] called\n";
	return malloc(n);
}

void operator delete(void * p)
{
	free(p);
	cout << "delete called\n";
}

void operator delete[](void * p)
{
	free(p);
	cout << "delete [] called\n";
}

};
int main()
{
	NewDelete * p = new NewDelete[10];
	delete []p;

	Array x(10);
	x[5] = 10;
	cout << x[5]<<endl;
	//x[10] = 11; 
	Fraction fraction(50, 20);
	double f = fraction;
	int i = fraction; // convert frcation obj to int

	Conversion s;
	s= fraction;  // convert frcation obj to conversion obj
	cout << f << " " << i << " " << s.num << " " << s.den;
	return 0;
}