#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void SSTF(const vector<int>& req, int head){
	int st=0;
	int n = req.size();
	vector <bool> visited(n,false);
	//cout<<"ads";
	for(int i=0;i<n;i++)
	{
		int min_distance = INT_MAX;
		int min_index=-1;//cout<<"1";
		for(int j=0;j<n;++j)
		{
			//cout<<"2";
			if(!visited[j] && abs(head-req[j])<min_distance)
			{
				min_distance = abs(req[j]-head);
				min_index=j;
			//	cout<<"3";
			}
		}
		st += min_distance;
		head = req[min_index];
		visited[min_index] = true;
	}
	cout<<"SSTF Total head movements : "<<st<<endl;
}



int main(){
    int n,head;
    cout<<"Enter number of disk requests : ";
    cin>>n;
    vector <int> requests (n);
    cout<<"Enter the disk requests : ";
    for(int i=0;i<n;i++){
    	cin>>requests[i];
	}
	cout<<"Enter inital head position : ";
	cin>>head;
//	cout<<"Performing FCFS Disk Scheduling Algorithm ...";
	SSTF(requests,head);
  return 0;  
    
}
