#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n;
    float avg=0;
    vector <int> b,w,a;
    cout<<"Enter number of process : ";
    cin>>n;
    b.resize(n);
    w.resize(n);
    a.resize(n);

    cout<<"Enter burst time for corresponding job :- "<<endl;
    for(int i=0;i<n;++i){
        cout<<"Process "<<i+1<<" : ";
        cin>>b[i];
        a[i]=i+1;
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(b[i]>b[j]){
                swap(b[i],b[j]);
                swap(a[i],a[j]);
            }
        }
    }
    w[0]=0;
    cout<<"\nProcess "<<a[0]<<" waiting time is 0";
    for(int i=1;i<n;++i){
        w[i]=b[i-1]+w[i-1];
        cout<<"\nProcess "<<a[i]<<" waiting time is "<<w[i];
        avg+=w[i];
    }

    cout<<"\nTotal waiting time : "<<avg;
    cout<<"\nAverage waitinig time : "<<avg/n;
    cout<<"\tGnatt Chart\n\t****************\n";
    for(int i=0;i<n;++i){
        cout<<"|\tP"<<a[i]<<"\t";
    }
    cout<<"|\t\n";
    for(int i=0;i<n;++i)    cout<<w[i]<<"\t  \t";
    cout<<w[n-1]+b[n-1];
    return 0;
}
