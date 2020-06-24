#include<iostream>
#include <Windows.h>
#include <thread>
#include <mutex>
#include<string>
#include<condition_variable>
#include<string>

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
	void printEvenOdd(const string &s,const bool &isOdd)
	{
		unique_lock<mutex> lock(mtx,defer_lock); // use defer_lock or call unlock before acquiring the lock again
		while (count <= n)
		{
			lock.lock();
			cd.wait(lock, [this,isOdd]() {return (count % 2 == 1)== isOdd; });
			if (count <= n)
				cout  <<s<<" : "<< count << endl;
			count++;
			lock.unlock();
			cd.notify_all();
		}
	}
	
};

int main()
{
	OddEven obj(10);
	thread th1(&OddEven::printEvenOdd, &obj,"Even", false);
	thread th2(&OddEven::printEvenOdd, &obj, "odd", true);
	th1.join();
	th2.join();
	return 0;
}