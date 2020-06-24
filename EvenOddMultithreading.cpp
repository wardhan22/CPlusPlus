#include<iostream>
#include <Windows.h>
#include <thread>
#include <mutex>
#include<condition_variable>

using namespace std;
//This program works..but this is not the correct wayt to implement thread synchronization. 
//Here one thread will keep on acquiring lock and relaesing it in loop until another thread will increment the value.
//Please note that we are incrementing the value in if condition i.e cout statement that's why this program works.
class EvenOdd
{
	int n;
	mutex mtx;
	condition_variable cd;
	int count;

public:
	EvenOdd(int x) :n(x) {
		count = 1;
	}
	void printEven()
	{
		while (count <= n)
		{
			mtx.lock();
			if (count<=n && count % 2 == 0)
				cout << "Even :" << count++ << endl;
			mtx.unlock();
		}
	}
	void printOdd()
	{
		while (count <= n)
		{
			this_thread::sleep_for(chrono::seconds(1));
			mtx.lock();
			if (count <= n && count % 2 != 0)
				cout << "Odd :" << count++ << endl;
			mtx.unlock();
		}
	}
};

//int main()
//{
//	EvenOdd obj(10);
//	thread th1(&EvenOdd::printOdd, &obj);
//	thread th2(&EvenOdd::printEven, &obj);
//	th1.join();
//	th2.join();
//	return 0;
//}