#include <iostream>
#include <queue>
using namespace std;

int n;

class Node {
    public :
        int pid,at,bt;
        Node(int pid,int at,int bt){
            this->at = at;
            this->pid = pid;
            this->bt= bt;
        }
        
};

class FCFS{
    private:
        queue <Node> processQ;
        queue 
    public:
        void addProcess(int pid,int at,int bt){
            Node newprocess(pid,at,bt);
            processQ.push(newprocess);
        }
        void print(){
            cout<<"PID\tAT\tBT\n"; 
            for(int i=0;i<n;i++){
                Node p = processQ.front();
                processQ.pop();
                cout<<p.pid<<"\t"<<p.at<<" \t"<<p.bt<<"  \n"; 
            }
        }
        void cwt(){
            int temp,,awt,ar[n];
            for(int i=0;i<n;i++){
                Node p = processQ.front();
                process
            }
        }
};


int main(){
    FCFS scheduler;
    cout<<"Enter the number of jobs : ";
    cin>>n;
    int at,bt;
    for(int i=0 ; i<n;++i){
        cout<<"Enter Arrival time and Burst time of Process "<<i+1<<" : ";
        cin>>at>>bt;
        scheduler.addProcess(i+1,at,bt);
    }

    scheduler.print();
    scheduler.cwt();

}