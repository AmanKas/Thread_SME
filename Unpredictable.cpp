#include<iostream>
#include<thread>
using namespace std;

void func(int x)
{
     std::cout << "Thread_id" << this_thread::get_id() << "Value of x is " << x << endl;
}

int main()
{
     std::thread t1(func, 1);
     std::thread t2(func, 2);
     t2.join();
     t1.join();
     return 0;
}

