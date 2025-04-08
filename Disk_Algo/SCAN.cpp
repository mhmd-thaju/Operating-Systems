#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void SCAN(const vector<int>& req, int head, int disk_size, string dir){
	int st=0;
	vector <int> left,right,seq;
	
	if (dir == "left"){
		left.push_back(0);
	}else{
		right.push_back(disk_size-1);
	}

	for (int r:req){
		if(r<head){
			left.push_back(r);
		}
		else{
			right.push_back(r);
		}
	}
	sort(left.begin(),left.end(),greater <int> ());
	sort(right.begin(),right.end());
	if(dir == "left"){
		seq.insert(seq.end(),left.begin(),left.end());
		seq.insert(seq.end(),right.begin(),right.end());		
	}
	else{
		seq.insert(seq.end(),right.begin(),right.end());		
		seq.insert(seq.end(),left.begin(),left.end());
	}
	
	for(int t : seq){
		st += abs(t-head);
		head = t;
	}
	cout<<"SCAN Total head movements : "<<st<<endl;
}

int main(){
    int n,head,disk_size;
    string dir;
	cout<<"Enter number of disk requests : ";
    cin>>n;
    vector <int> requests (n);
    cout<<"Enter the disk requests : ";
    for(int i=0;i<n;i++){
    	cin>>requests[i];
	}
	cout<<"Enter inital head position : ";
	cin>>head;
	cout<<"Enter size of the disk : ";
	cin>>disk_size;
	cout<<"Enter the direction of scan (left / right) : ";
	cin>>dir;
	
	SCAN(requests,head, disk_size,dir);
  return 0;  
    
}
