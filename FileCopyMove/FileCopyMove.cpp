#include <iostream>
#include <fstream>
#include <cstdio> 
using namespace std;

void printfiles(){
        system("dir /b");
}
void copyfile(){
        int c;
        cout<<"Do you want to list all files (0/1)?";
        cin>>c;
        if(c==1)        printfiles();
        string sname,dname;
        cout<<"Enter the file name to copy : ";
        cin>>sname;
        cout<<"Enter the destination file name:";
        cin>>dname;
        ifstream src(sname,ios::binary);
        ofstream des(dname,ios::binary);

        if(!src){
                cerr<<"Error Opening source File!";
                return;
        }
        if(!des){
                cerr<<"Error Opening destination File!";
                return;
        }
        des<<src.rdbuf();
        cout<<"file copied successfully from " << sname <<" to "<<dname<<endl;
}

void movefile(){
        string sname,dname;
        int c;
        cout<<"Do you want to list all files (0/1)?";
        cin>>c;
        if(c==1)        printfiles();
        cout<<"Enter the file name to move : ";
        cin>>sname;
        cout<<"Enter the destination file name :";
        cin>>dname;
        ifstream src(sname,ios::binary);
        ofstream des(dname,ios::binary);

        if(!src){
                cerr<<"Error Opening source File!";
                return;
        }
        
        if(!des){
                cerr<<"Error Opening destination File!";
                return;
        }
        des<<src.rdbuf();
        src.close();
        int status = remove(sname.c_str());
        if(status == 0 ){
                cout<<"File Moved!";
        }
        else{
                cout<<"Error occured!";
        }

}

int main(){
    int c;
    cout<<"\t\t---MainMenu---\n\n";
    cout<<"1.Copy a file\n2.Move a file\n3.Exit\n";
    do{
            cout<<"\nEnter your choice : ";
        cin>>c;
        switch(c){
            case 1: copyfile();
                    break;
            case 2: movefile();
                    break;
            case 3: cout<<"Exiting...";
                    return 0;
            default: cout<<"Invalid choice!";
        }

    }while(c!=3);

} 