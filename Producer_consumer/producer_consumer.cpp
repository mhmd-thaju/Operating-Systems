#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>

using namespace std;
queue <int> buffer;
const int buffer_size=5;
mutex mtx;
condition_variable cv_full;
condition_variable cv_empty;

void producer(){
    int item=1;
    while(true){
        this_thread::sleep_for(chrono::milliseconds(150));
        unique_lock <mutex> lock(mtx);
        cv_empty.wait(lock,[]{return buffer.size()<buffer_size;});
        buffer.push(item);
        cout<<"Produced : "<<item++<<endl;
        cv_full.notify_one();
    }
}

void consumer(){
    while(true){
        this_thread::sleep_for(chrono::milliseconds(200));
        unique_lock <mutex> lock(mtx);
        cv_full.wait(lock,[]{return !buffer.empty();});
        int item = buffer.front();
        buffer.pop();
        cout<<"Consumed : "<<item<<endl;
        cv_empty.notify_one();
    }
}

using namespace std;

int main(){
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();

    return 0;
}