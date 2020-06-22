#include <iostream>
#include <mutex>
#include <vector>
using namespace std;

timed_mutex tmx;

void bar()
{
	int x = 0;
	
	if (tmx.try_lock_for(chrono::milliseconds(10000))) // wait on eah thread for 10 sec to try lock
	{
		this_thread::sleep_for(chrono::milliseconds(100));
		for (int i = 0; i < 1000; i++)
		{
			x++;
		}
		tmx.unlock();
	}
	else
	{
		cout << "Cannot lock\n";
	}
}
//int main()
//{
//	vector<thread> arr;
//	for (int i = 0; i < 10; i++)
//	{
//		this_thread::sleep_for(chrono::milliseconds(50));
//		arr.push_back(thread(bar));
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i].join();
//	}
//	return 0;
//}