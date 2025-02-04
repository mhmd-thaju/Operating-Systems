#include <iostream>
#include <fstream>

using namespace std;

void createfile(){
    string fname;
    cout<<"Enter File name (include .txt): ";
    cin>>fname;
    ofstream fcr(fname.c_str());
    if(fcr){
        cout<<"File Created Successfully";
    }else{
    cout<<"Error Creating File";}
    fcr<<"Ihf";
}
void renamefile(){
    string fname,fnewname;
    cout<<"Enter the current file name (include .txt): ";
    cin>>fname;
    cout<<"Enter the new file name (include .txt): ";
    cin>>fnewname;
    if(rename(fname.c_str(),fnewname.c_str())==0){
        cout<<"File renamed Successfully!";
    }else{
        cout<<"Error Occured !";
    }
}
void deletefile(){
    string fname;
    cout<<"Enter the file name (include .txt): ";
    cin>>fname;
    if(remove(fname.c_str())==0){
        cout<<"File "<<fname<<" deleted successfully!";
    }else{
        cout<<"Error Occured";
    }
}

void editfile(){
    string fname,content;
    cout<<"Enter the file name (include .txt): ";
    cin>>fname;
    ofstream fed(fname.c_str(),ios::trunc);
    if(!fed){
        cout<<"Error opening file for editing ";
    }else{
        cout<<"Enter the content to edit : ";
        cin.ignore();
        getline(cin,content);
        fed<<content;
        cout<<"Edit Successful";
        fed.close();
    }
}

int main(){
    int ch;
    cout<<"\n\t\t---MainMenu---\n1.Create a File\n2.Rename a File\n3.Delete a File\n4.Edit a File\n5.Exit"<<endl;
    do{
        cout<<"\n\nEnter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:
                    createfile();
                    break;
            case 2:
                    renamefile();
                    break;
            case 3:
                    deletefile();
                    break;
            case 4: 
                    editfile();
                    break;
            case 5:
                    cout<<"Exiting...";
                    return 0;
        }
    }while(ch!=5);
}