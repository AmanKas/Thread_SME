#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

static int sharededVar = 1000;
// std::mutex m;
void func()
{
    for (int i = 0; i < 1000; i++ )
    {
        // std::lock_guard lg(m);
        sharededVar++;
        this_thread::sleep_for(5us);
    }
}

int main()
{
    std::thread t1(func);
    std::thread t2(func);

    t1.join();
    t2.join();

    cout << "sharededVar = " << sharededVar << endl;

    return 0;
}