#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
class Node {
    public :
        int pid,at,bt,pr;
        Node(int pid,int at,int bt,int pr) : pid(pid),at(at),bt(bt),pr(pr){}        
};

class Priority{
    private:
        queue <Node> processQ;
        vector <Node> pro;
    public:
        void addProcess(int pid,int at,int bt,int pr){
            Node newprocess(pid,at,bt,pr);
            pro.push_back(newprocess);
        }
        void sort_(){
            for(int i=0;i<n;++i){
                for(int j=i+1;j<n;++j){
                    if(pro[i].pr > pro[j].pr)
                    swap(pro[i],pro[j]);
                }
            }
            for(int i=0;i<n;i++){
                processQ.push(pro[i]);
            }
        }
        void ganttchart(){
            sort_();
            int temp=0,b[n+1];
            float awt=0.0;
            cout<<endl<<endl<<"_______Gnatt Chart________"<<endl;
            queue <Node> tmp = processQ;
            b[0]=temp;
            for(int i=0;i<n;++i){
                Node p = tmp.front();
                cout<<"|\tP"<<p.pid<<"\t";
                temp += p.bt;
				awt += temp ;
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
    Priority scheduler;
    cout<<"Enter the number of jobs : ";
    cin>>n;
    int pr,bt;
    for(int i=0 ; i<n;++i){
        cout<<"Enter Burst time and Priority of Process "<<i+1<<" : ";
        cin>>bt>>pr;
        scheduler.addProcess(i+1,0,bt,pr);
    }
    scheduler.ganttchart();
}
