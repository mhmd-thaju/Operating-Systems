#include <iostream>
#include <string>
#include <direct.h>
#include <sys/stat.h>
using namespace std;

const size_t size = 1024; 
char buffer[size]; 

void print_lf(string fn,string ex){
	string command = "dir "+fn+"."+ex+" /b";
	cout<<endl;
	system(command.c_str());
	cout<<endl;
}

void list_file(){
	int l;
	//system("cls");
	string fn = "*",ex = "*";
	cout<<"\t\t---List File Detail---\n";
	cout<<"1.List all Files\n2.List of Extention files\n3.List of Namewise\n";
	cout<<"Enter choice : ";
	cin>>l;
	switch(l){
		case 1:
			cout<<"List of all Files \n";
			print_lf(fn,ex);
			break;
		case 2:
			cout<<"Enter the extention : ";
			cin>>ex;
			cout<<"List of ."<<ex<< " Files \n";
			print_lf(fn,ex);
			break;
		case 3:
			cout<<"Enter Name wise (eg.Sys*.*) : ";
			cin>>fn;
			fn.append("*");
			print_lf(fn,ex);
			break;
		default:
			break;
	}
}

int directory_exists(string drname){
	struct stat info; 
	if (stat(drname.c_str(), &info) != 0) { return false; // Directory does not exist 
	} else if (info.st_mode & S_IFDIR) { return true; // Directory exists 
	} return false;
}

void directory(){
	cout<<"Current directory : "<<buffer<<endl;
	string drname;
	cout<<"Enter the name of directory : ";
	cin>>drname;
	if(directory_exists(drname)){
		cout<<drname <<" Directory already exists !\n";
	}else{
		mkdir(drname.c_str());
		cout<<"Directory successfully created!\n";
	}
}

void change_dir(){
	int c;
	cout<<"\t\t ---Change working directory---\n";
	cout<<"1.Step by step backward\n2.Goto Root directory\n3.Forward directory\nEnter your choice : ";
	cin>>c;
	switch(c){
		case 1:
			chdir("..");
			break;
		case 2:
			chdir("/");
			break;
		case 3:
			string fn;
			cout<<"Enter Directory name : ";
			cin>>fn;
			//chdir(fn.c_str());
			if (chdir(fn.c_str()) == 0) {
                cout << "Moved to directory: " << fn << " successfully." << endl;
            } else {
                cerr << "Failed to move to directory: " <<  endl;
            }
			break;
		//default:
		//	break;
	}
	cout<<"Current working directory : "<<getcwd(buffer, size)<<endl;
	
}

int main()
{
	system("cls");
	 if (getcwd(buffer, size) != NULL) {
        cout << "Current working directory: " << buffer << endl;
    } 
    else {
        cerr << "Error getting current working directory" << endl;
    }
	int ch;
	do{
		//system("cls");
		cout<<"\t\t---Main Menu---"<<endl;
		cout<<"1.Display List of Files"<<endl;
		cout<<"2.Create New Directory"<<endl;
		cout<<"3.Change working directory"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch){
			case 1 : 
					list_file();
					break;
			case 2:
					directory();
					break;
			case 3:
					change_dir();
				    break;
			case 4:
				return 0;
			default:
				cout<<"Invalid choice!!\n";
				break;
		}
		
	}while(ch!=4);
	return 0;
}
