#include<iostream>
#include <Windows.h>
#include <thread>
#include <mutex>
#include<condition_variable>

using namespace std;

class OddEven
{
	int n;
	mutex mtx;
	condition_variable cd;
	int count;

public:
	OddEven(int x) :n(x) {
		count = 1;
	}
	void printEven()
	{
		unique_lock<mutex> lock(mtx,defer_lock);
		while (count <= n)
		{
			lock.lock();
			cd.wait(lock, [this]() {return (count % 2 == 0); });
			if (count <= n)
				cout << "Even :" << count << endl;
			count++;
			lock.unlock();
			cd.notify_all();
		}
	}
	void printOdd()
	{
		unique_lock<mutex> lock(mtx, defer_lock);
		while (count <= n)
		{
			lock.lock();
			cd.wait(lock, [this]() {return (count % 2 == 1); });
			if (count <= n)
				cout << "Odd :" << count << endl;
			count++;
			lock.unlock();
			cd.notify_all();
		}
	}
};

//int main()
//{
//	OddEven obj(10);
//	thread th1(&OddEven::printOdd, &obj);
//	thread th2(&OddEven::printEven, &obj);
//	th1.join();
//	th2.join();
//	return 0;
//}