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
    public:
        void addProcess(int pid,int at,int bt){
            Node newprocess(pid,at,bt);
            processQ.push(newprocess);
        }
        void print(){
            queue <Node> temp = processQ;
            cout<<"PID\tAT\tBT\n"; 
            for(int i=0;i<n;i++){
                Node p = temp.front();
                temp.pop();
                cout<<p.pid<<"\t"<<p.at<<" \t"<<p.bt<<"  \n"; 
            }
        }
        void ganttchart(){
            int temp=0,awt = 0,b[n+1];
            cout<<endl<<endl<<"_______Gnatt Chart________"<<endl;
            queue <Node> tmp = processQ;
            b[0]=temp;
            for(int i=0;i<n;++i){
                Node p = tmp.front();
                cout<<"|\tP"<<p.pid<<"\t";
                if(temp == p.at)
                {
                	temp += p.bt;
				}
				else if(temp > p.at ){
					awt += temp - p.at;
					temp += p.bt;
				}
                b[i+1]=temp;
                tmp.pop();    
            }
            cout<<"|\t\n";
            for (int i=0;i<n+1;++i)    cout<<b[i]<<"\t  \t";
            cout<<"\n\nTotal turnaround time : "<<temp<<endl;
            cout<<"Total Waiting time : "<<awt<<endl;
            cout<<"Average waiting time : "<<awt/n<<endl;
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
    scheduler.ganttchart();
}