#include "Registers.h"

Registers::Registers()
{
	check = 0;
}

void Registers::addData_user(){
	string u,p,fn,ln,em;
	ifstream user("Data_user/data_user.txt");
	while(user >> u >> p >> fn >> ln >> em){
		addNode(u,p,fn,ln,em);
	}	
	user.close();
}

void Registers::main(){
	deleteNode();
	cout << "\n\t>>>> Sign up <<<<" << endl;
	cout << "\n\tInput Username : ";
	cin >> username;
	addData_user();
	if(findUsername(username) == true){
		system("cls");
		check = 0;	
		cout << "\n\tDuplicated Username!!" <<endl;
		deleteNode();
		system("pause");
	}else{
		check = 1;
	}
		
	if(check == 1){	
		cout << "\tInput First Name : ";
		cin >> fname;
		cout << "\tInput Last Name  : ";
		cin >> lname;
		if(findName(fname,lname) == true){
			system("cls");
			check = 0;
			cout << "\n\tDuplicated Name!!" <<endl;
			deleteNode();
			system("pause");
		}else{
			check = 2;
			deleteNode();
		}
	}
	
	if(check == 2){
		cout << "\tInput Password : ";
		cin >> password;
		cout << "\tInput Email      : ";
		cin >> email;
		printConfirm();
	}
}

void Registers::saveFile(){
	ofstream savedata("Data_user/data_user.txt",ios::app);
	savedata << username << "\t";
	savedata << password << "\t";
	savedata << fname << "\t";
	savedata << lname << "\t";
	savedata << email << "\t\n";
	savedata.close();
			
	ofstream saveDF(("Data_user/Data_Friends/"+username+".txt").c_str());
	saveDF << "";
	saveDF.close();
			
	ofstream saveDRF(("Data_user/Data_Friends_Request/"+username+".txt").c_str());
	saveDRF << "";
	saveDRF.close();
			
	ofstream saveDSRF(("Data_user/Data_Sent_Request/"+username+".txt").c_str());
	saveDSRF << "";
	saveDSRF.close();
	
	ofstream log(("Data_user/History_Log/"+username+".txt").c_str());
	log << "";
  	log.close();
  	
  	ofstream post(("Data_user/History_Post/"+username+".txt").c_str());
	post << "";
  	post.close();
  	
  	ofstream savepost(("Data_user/Data_Post/"+username+".txt").c_str());
	savepost << "";
  	savepost.close();
}

void Registers::printConfirm(){
	string n;
	system("cls");
	cout << "\n\t>>>> Confirm information <<<<" << endl;
	cout << "\tUsername   : " << username << endl;
	cout << "\tPassword   : " << password << endl;
	cout << "\tFirst Name : " << fname << endl;
	cout << "\tLast Name  : " << lname << endl;
	cout << "\tEmail      : " << email << endl;
	pass:
		cout << "\nConfirm your information || (1)yes or (2)no" << endl;
		cin >> n;
		if(n == "1"){
			saveFile();
		}else if(n == "2"){
			
		}else{
			cout << "Please Enter (1) or (2) !!!" << endl;
			goto pass;
		}
}

