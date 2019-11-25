#include "ForgotPassword.h"

ForgotPassword::ForgotPassword(){
}

void ForgotPassword::setValue(string u,string n){
	username = u;
	email = n;
}

void ForgotPassword::main(){
	string u,p,fn,ln,em;
	
	ifstream user("Data_user/data_user.txt");
	while(user >> u >> p >> fn >> ln >> em){
		addNode(u,p,fn,ln,em);
	}
	user.close();
	
	if(isEmpty() == false){
		if(findPassword(username,email) == true){
			print(username);
		}else{
			cout << "\n\t Username or Email Incorrect!!!" << endl;
		}
		system("pause");
	}else{
		cout << endl << "\n\t Not Data Username&Password in System!!" << endl;
		system("pause");
	}
	deleteNode();
}

void ForgotPassword::print(string user){
	Node *fpass;
	fpass = head;
	for(int i=0;i<count;i++){  
		if(user == fpass->Node_username){
			cout<<"=============================================="<<endl;
			cout<<" Forgot Password"<<endl;
			cout<<"=============================================="<<endl;
			cout<<" Username : " << fpass->Node_username <<endl;
			cout<<" Password : " << fpass->Node_password <<endl;
			cout<<" Name     : " << fpass->Node_firstname << " " << left << fpass->Node_lastname <<endl;
			cout<<" Email    : " << fpass->Node_email <<endl;
			cout<<"=============================================="<<endl;
		}
		fpass = fpass->link;
	}
	cout << endl;
	delete fpass;
}
