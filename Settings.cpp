#include "Settings.h"

Settings::Settings()
{

}

void Settings::main(){
	string menu;
	ifstream file("Data_user/data_using.txt");
	file >> username >> password >> fname >> lname >> email;
	file.close();
	do{
		system("cls");
		cout << "\n\t>>>>> Settings <<<<< " << endl;
		cout << "_______________________________________\n" << endl;
		cout << "\t1) Change Password" << endl;
		cout << "\t2) History Logged In\n" << endl;
		cout << "\t0) Back" << endl;
		cout << "_______________________________________\n" << endl;
		cout << " Enter your Selection : ";
		cin >> menu;
		if(menu == "1"){
			system("cls");
			case1_pass();
		}
		if(menu == "2"){
			system("cls");
			case2_log();
		}	
	}while(menu != "0");
	
}

void Settings::case1_pass(){
	cout << "\n\t>>>>> Change Password <<<<< " << endl;
	cout << "__________________________________________\n" << endl;
	cout << "\t Input New Password : ";
	cin >> newPass;
	cout << "\t Input Old Password : ";
	cin >> oldPass;
	if(oldPass == password){
		fstream file("Data_user/data_user.txt");
		while(file >> u >> p >> fn >> ln >> em){
			addNode(u,p,fn,ln,em);
		}
		file.close();

		remove_Node(username);
		
		ofstream saveNode(("Data_user/data_user.txt"),ios::out);
		for(Node *temp = head;temp != NULL;temp = temp->link){
			saveNode << temp->Node_username << "\t" << temp->Node_password << "\t" 
					<< temp->Node_firstname << "\t" << temp->Node_lastname << "\t" 
					<< temp->Node_email << endl; 
		}
		saveNode.close();
		
		/////////////////////////////////////////////
		ofstream user("Data_user/data_user.txt",ios::app);
		user << username << "\t";
		user << newPass << "\t";
		user << fname << "\t";
		user << lname << "\t";
		user << email << "\t\n";
		user.close();
		/////////////////////////////////////////////
		ofstream uing("Data_user/data_using.txt");
		uing << username << "\t";
		uing << newPass << "\t";
		uing << fname << "\t";
		uing << lname << "\t";
		uing << email << "\t\n";
		uing.close();
		/////////////////////////////////////////////
		deleteNode();
		cout << "\n\tChange Password Complete." << endl;
	}else{
		cout << "\n\tOld Password incorrect!" << endl;
	}
	system("pause");
}

void Settings::case2_log(){
	cout << "\n\t>>>>> History Logged In <<<<< " << endl;
	cout << "_________________________________________________\n" << endl;
	fstream myfile(("Data_user/History_Log/"+username+".txt").c_str());
    while ( getline (myfile,line) ) {
        cout << " " << line << endl;
    }
    myfile.close();
	cout << "_________________________________________________\n" << endl;
	system("pause");
}
