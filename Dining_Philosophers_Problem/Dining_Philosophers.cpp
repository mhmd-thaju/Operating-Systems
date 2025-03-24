#include <iostream>
#include <vector>
#include <mutex>
#include <thread>

using namespace std;

const int NUM_PHILOSOPHERS = 5;
mutex forks[NUM_PHILOSOPHERS];

void philosopher(int i){
    cout<<"Philosopher "<<i+1<<" is thinking "<<endl;
    this_thread::sleep_for(chrono::seconds((i+3)%5));
    int leftfork = i;
    int rightfork =(i+1)% NUM_PHILOSOPHERS;
    unique_lock <mutex> lockleft(forks[leftfork]);
    cout<<"Philospher "<<i+1<<" picked left fork "<<leftfork<<endl;
    unique_lock <mutex> lockright(forks[rightfork]);
    cout<<"Philospher "<<i+1<<" picked right fork "<<rightfork<<endl;
    cout<<"Philosopher "<<i+1<<" is eating"<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout<<"Philosopher "<<i+1<<" finished eating and is releasing forks"<<endl;
}

int main(){
    vector <thread> philosophers;
    for(int i=0;i<NUM_PHILOSOPHERS;++i){
        philosophers.push_back(thread(philosopher,i));
    }
    for(auto&t : philosophers){
        t.join();
    }
    return 0;
}
