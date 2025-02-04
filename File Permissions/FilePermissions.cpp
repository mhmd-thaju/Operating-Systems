#include <iostream>
#include <windows.h>
using namespace std;
int main(){
    char name[15];
    DWORD attrib;
    int n;

    system("cls");
    cout<<"\t\t---MainMenu--\n\n1.OnlyRead\n2.OnlyWrite\n3.Exit\n\nEnter your choice : ";
    cin>>n;
    switch(n){
        case 1:
                cout<<"Enter the file name : ";
                cin>> name;
                attrib = FILE_ATTRIBUTE_READONLY;
                cout<<"\n"<<name<<" file read permissions accepted !";
                break;
        case 2:
                cout<<"Enter the file name : ";
                cin>>name;
                attrib = FILE_ATTRIBUTE_ARCHIVE;
                cout<<"\n"<<name<<" file write permissions accepted !";
                break;
        case 3:
                return 0;
        default:
                cout<<"\nInvalid Choice!";
    }
    if(SetFileAttributes(name,attrib)==0)
    {
        cerr<<"Unbale to set attribute!";
    }
    else {
        cout<<"\n File attributes set successfully";
    }
    

}