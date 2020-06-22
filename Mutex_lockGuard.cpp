#include <iostream>
#include <mutex>
#include <vector>

using namespace std;

class Sample
{
	mutex mtx;
	int m_shared;
public:
	Sample()
	{
		m_shared = 5;
	}
	void foo()
	{
		mtx.lock(); 
		this_thread::sleep_for(std::chrono::milliseconds(100));
		for(int i=0;i<500;i++)
		m_shared++;
		mtx.unlock();
	}

	void bar()
	{
		lock_guard<mutex> lock(mtx);
		this_thread::sleep_for(std::chrono::milliseconds(100));
		for (int i = 0; i<500; i++)
		m_shared--;
	}
	int getShared()
	{
		return m_shared;
	}
};

int test()
{
	Sample obj;
	vector<std::thread> arr;
	for (int i = 0; i < 5; i++)
	{
		arr.push_back(thread(&Sample::foo, &obj)); // move constructor..temporary object will be created and moved
	}

	for (int i = 0; i < 5; i++)
	{
		arr.push_back(thread(&Sample::bar, &obj)); // move constructor..temporary object will be created and moved
	}

	for (int i = 0; i < 10; i++)
	{
		arr[i].join();
	}

	return obj.getShared();
}
//int main()
//{
//	for (int i = 0; i < 100; i++)
//	{
//		if (test() != 5)
//		{
//			cout << "value is diff\n";
//		}
//	}
//	return 0;
//}