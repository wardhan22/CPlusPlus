#include <iostream>
#include <mutex>
#include <vector>
using namespace std;

timed_mutex tm;

void foo()
{
	int x=0;
	if (tm.try_lock())
	{
		this_thread::sleep_for(chrono::milliseconds(100));
		for (int i = 0; i < 1000; i++)
		{
			x++;
		}
		tm.unlock();
	}
	else
	{
		cout << "Cannot lock\n";
	}
	tm.unlock();
}
//int main()
//{
//	vector<thread> arr;
//	for (int i = 0; i < 10; i++)
//	{
//		this_thread::sleep_for(chrono::milliseconds(50));
//		arr.push_back(thread(foo));
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i].join();
//	}
//	return 0;
//}