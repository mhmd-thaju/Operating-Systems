#include <iostream>
#include <queue>
using namespace std;

int n,s=1;

class Node{
    public:
        int pid,at,bt;
        Node(int pid,int at,int bt) : pid(pid),at(at),bt(bt){}
};

class RR{
    private:
        queue <Node> readyQ;
    public:
        void addProcess(int pid,int at,int bt){
            Node newprocess(pid,at,bt);
            readyQ.push(newprocess);
        }
        void gnattchart(){
            float avg= 0;
            int t=0,tt[20]={0},e=n-1;
            cout<<"\t\t Gnatt Chart\n\t************************************\n";
            Node temp = readyQ.front();
            while(!readyQ.empty()){
                readyQ.pop();
                if(temp.bt-s>0){
                    cout<<"|\tP"<<temp.pid<<"\t";
                    temp.bt-=s;
                    readyQ.push(temp);
                    avg+=s*e;
                    tt[t]=s+tt[t-1];
                }
                else{
                    cout<<"|\tP"<<temp.pid<<"\t";
                    avg+=temp.bt*e--;
                    tt[t]=temp.bt+tt[t-1];
                    temp.bt=0;
                }

                temp = readyQ.front();
                t++;
            }
            cout<<"|\n0";
            for(int i=0;i<t;i++){
                cout<<"\t  \t"<<tt[i];
            }
            cout<<"\nTotal waiting time : "<<avg<<endl;
            cout<<"Average waiting time : "<<avg/n;

        }
};

int main(){
    RR scheduler;
    cout<<"Enter time slice (quantum) : ";
    cin>>s;
    cout<<"Enter number of job : ";
    cin>>n;
    int at,bt;
    for(int i=0 ; i<n;++i){
        cout<<"Enter Burst time of Process "<<i+1<<" : ";
        cin>>bt;
        scheduler.addProcess(i+1,0,bt);
    }
    scheduler.gnattchart();
}
