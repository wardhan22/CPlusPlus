#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
class ThreadApplication
{
	mutex mtx;
	condition_variable cd;
	bool isCompleted;
public:
	ThreadApplication()
	{
		isCompleted = false;
	}
	bool CheckisCompleted()
	{
		return isCompleted;
	}
	void mainTask()
	{
		cout << "Main task is running in separate thread...\n";
		cout << "waiting for thread 2 to complete parallel task and notify\n";
		unique_lock<mutex> lock(mtx);
		//cd.wait(lock, bind(&ThreadApplication::CheckisCompleted, this)); //2nd argument is predicate of type bool name(){}
						//or
		//cd.wait(lock, [this]() {return CheckisCompleted() == true; });

		cout << "Thread 2 has completed the task and returned\n";
	}
	void Paralleltask()
	{
		cout << "This task is going on in parallel\n";
		cout << "This is thread 2 ...will notify thread1 running MainTask once this thread execution is done\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		lock_guard<mutex> lock(mtx); // acquire lock becuase isCompleted is shared data
		isCompleted = true;
		cd.notify_one();
	}
};
int main()
{
	ThreadApplication obj;
	thread th1(&ThreadApplication::mainTask, &obj);
	thread th2(&ThreadApplication::Paralleltask, &obj);
	th1.join();
	th2.join();
	return 0;
}