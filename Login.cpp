#include "Login.h"

Login::Login()
{
	verify = 0;
}

int Login::getVerify(){
	return verify;
}

void Login::setValue(string u,string n){
	username = u;
	password = n;
}

void Login::mainLogin(){	
	string u,p,fn,ln,em;
	ifstream user; //read file
	user.open("Data_user/data_user.txt");
	if(user.is_open()){
		while(user >> u >> p >> fn >> ln >> em){
				addNode(u,p,fn,ln,em); //add to Node linklist
		}
		user.close();
		if(isEmpty() == false){
			if(findUserPass(username,password) == true){
				verify = 1;
			}else{
				cout << "\n\tUsername or Password incorrect!" << endl;
				system("pause");
			}
			deleteNode();
		}else{
			deleteNode(); //delete Node Linklist
			cout << endl << "\tNot Data Username & Password in System!!" << endl;
			system("pause");
		}
			
	}else{
		system("cls");
		cout << endl << "\tNot Data in System!!" << endl;
		system("pause");
	}	
}

