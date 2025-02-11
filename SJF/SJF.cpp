#include <iostream>
#include <queue>
using namespace std;

float n;

class Node {
    public:
        int pid,at,bt;
        Node(int pid,int at,int bt){
            this->pid = pid;
            this->at = at;
            this->bt = bt;
        }
};

class SJF{
    private:
        priority_queue<Node > processQ;
    public:
        void addProcess(int pid,int at,int bt){
            Node newprocess(pid,at,bt);
            processQ.push(newprocess);
        }

        void print(){
            while(!processQ.empty()){
                Node p = processQ.top();
                cout<<p.pid<<"  "<<p.at<<"  "<<p.bt<<endl;
                processQ.pop();    
            }
            
        }
        
};

int main()
{
        SJF scheduler;
        cout<<"Enter the number of jobs : ";
        cin>>n;
        int at,bt;
        for(int i=0 ; i<n;++i){
            cout<<"Enter Arrival time and Burst time of Process "<<i+1<<" : ";
            cin>>at>>bt;
            scheduler.addProcess(i+1,at,bt);
        }
        scheduler.print();
        //scheduler.ganttchart();
}
