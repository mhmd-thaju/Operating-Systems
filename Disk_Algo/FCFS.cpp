#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void FCFS(const vector<int>& req, int head){
	int st=0;
	int distance,cur_track;
	for(int cur_track: req){
		distance = abs(cur_track -head);
		st+=distance;
		head=cur_track;
	}
	cout<<"FCFS Total head movements : "<<st<<endl;
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
	FCFS(requests,head);
  return 0;  
    
}
