#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream ofile("example.txt");
    if(!ofile){
        cerr<<"Error : Unable to  open `example.txt` for writing."<<endl;
        return 1;
    }
    string s;
    cout<<"Enter the text to write : ";
    cin>>s;
    ofile<<s;
    cout<<"Number of bytes written : "<<s.size()<<endl;
    ofile.close();

    ifstream ifile("example.txt");
    if(!ifile){
        cerr<<"Error ";
    }
    

}