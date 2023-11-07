#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

std::mutex m1;
std::mutex m2;

void process1()
{
    std::lock_guard lock1(m1);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::lock_guard lock2(m2);
    std::cout << "process 1 has acquired both the locks." << endl;
}
void process2()
{
    std::lock_guard lock1(m1);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::lock_guard lock2(m2);
    std::cout << "process 2 has acquired both the locks." << endl;
}

int main()
{
    std::thread t1(process1);
    std::thread t2(process2);

    t1.join();
    t2.join();


    return 0;
}