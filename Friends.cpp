#include "Friends.h"

Friends::Friends()
{
	status_accept = 0;
	status_sentRequest = 0;
	status_allFriend = 0;
	index_user = 0;
}

void Friends::addNode_data_user(){
	fstream file("Data_user/data_user.txt");
	while(file >> u >> p >> fn >> ln >> em){
		addNode(u,p,fn,ln,em);
	}
	file.close();
}


void Friends::addNode_data_friends(string user){
	fstream file(("Data_user/Data_Friends/"+user+".txt").c_str());
	while(file >> u >> fn >> ln ){
		addNode(u,fn,ln);
	}
	file.close();
}

void Friends::addNode_Data_Friends_Request(){
	fstream file(("Data_user/Data_Friends_Request/"+username+".txt").c_str());
	while(file >> u >> fn >> ln ){
		addNode(u,fn,ln);
	}
	file.close();
}

void Friends::addNode_Data_Sent_Request(){
	fstream file(("Data_user/Data_Sent_Request/"+username+".txt").c_str());
	while(file >> u >> fn >> ln ){
		addNode(u,fn,ln);
	}
	file.close();
}

void Friends::readFile_data_using(){
	fstream file("Data_user/data_using.txt");
		while(file >> u >> p >> fn >> ln >> em){
			username = u;
			fname = fn;
			lname = ln;
		}
	file.close();
}

void Friends::listNode(){
	Node *fpass;
	fpass = head;
	for(int i=0;i<count;i++){  
		cout << " " << i <<  ") Name : " << left << fpass->Node_firstname << " " << left << fpass->Node_lastname <<endl;
		choose_user[i] = fpass->Node_username;
		fpass = fpass->link;
	}
	delete fpass;
}

void Friends::main(){
	readFile_data_using();
	do{
		system("cls");
		show_status_accept(); //>> value status_accept
		show_status_sentRequest(); //>> value status_sentRequest
		show_status_allFriend();  //>> value allFriend
		cout << "\n\t>>>>> Friends Menu <<<<< " << endl;
		cout << "_______________________________________\n" << endl;
		cout << "\t1) Add Friend [+] 	" << endl;
		cout << "\t2) Unfriend [-] " << endl;
		cout << "\t3) Friend Requests (" << status_accept << ")" << endl;
		cout << "\t4) View Sent Requests (" << status_sentRequest << ")" << endl;
		cout << "\t5) View All Friends (" << status_allFriend << ")" << endl << endl;
		cout << "\t0) Back" << endl;
		cout << "_______________________________________\n" << endl;
		cout << "Enter your Selection : ";
		cin >> menu;
		if(menu == "1"){
			system("cls");
			main_addFriend();
		}
		if(menu == "2"){
			system("cls");
			main_unFriend();
		}
		if(menu == "3"){
			system("cls");
			main_acceptFriend();
		}
		if(menu == "4"){
			system("cls");
			main_sentRequest();
		}
		if(menu == "5"){
			system("cls");
			main_showList();
		}
	}while(menu != "0");
}


void Friends::main_addFriend(){
	int check = 0;
	cout << "\n\t>>>>> add Friend <<<<< " << endl;
	cout << "\tFind Firstname : ";
	cin >> findFname;
	cout << "\t     Lastname : ";
	cin >> findLname;
	
	if (findFname == fname && findLname == lname){
		check = 0;
		cout << "\n\tYou can not add a name yourself!!!" << endl << endl;
		system("pause");
	}else{
		check = 1;
	}
	
	if(check == 1){
		addNode_data_user(); //read New data_user.txt
		if(findName(findFname,findLname) == true){ //serach name in data_user.txt
			deleteNode(); //addNode_data_user()
			addNode_Data_Sent_Request();
			if(findName(findFname,findLname) != true){ //serach name in data_status_request.txt
				deleteNode(); //addNode_data_status_request
				addNode_data_friends(username); //read New data_friends.txt
				if(findName(findFname,findLname) != true){ //serach name in data_friends.txt
					deleteNode(); //addNode_data_friends
					addNode_Data_Friends_Request(); 
					if(findName(findFname,findLname) != true){
						deleteNode();
						printConfirm_addFriend();
					}else{
						deleteNode();
						main_acceptFriend();
					}
					
				}else{
					deleteNode(); //addNode_data_friends
					cout << "\n\tYou and " << findFname << " " << findLname <<" are friends!!!\n" << endl;
					system("pause");
				}
			}else{
				deleteNode(); //addNode_data_status_request
				cout << "\n\tYou have already submitted a request!!!\n" << endl;
				system("pause");
			}
		}else{
			deleteNode(); //addNode_data_user()
			cout << "\n\tCould not find name!!!" << endl << endl;
			system("pause");
		}
	} //check
}

void Friends::printConfirm_addFriend(){
	cout << "\n\t>>>> Confirm information <<<<" << endl;
	cout << "\tName   : " << findFname << " " << findLname << endl;
	string n;
	pass:
		cout << "\nConfirm your want to add friends? || (1)yes or (2)no : ";
		cin >> n;
		if(n == "1" || n == "2"){
			if( n == "1"){
				addFriend_saveFile();
			}
		}else{
			cout << "Please select (1) or (2) !!!" << endl;
			goto pass;
		}
}

void Friends::addFriend_saveFile(){
	addNode_data_user();
	
	string user = getUsername(findFname,findLname);
	
	fstream addRF(("Data_user/Data_Friends_Request/"+user+".txt").c_str(),ios::app);
	addRF << username << "\t" << fname << "\t" << lname << endl;
	addRF.close();
	
	fstream addSRF(("Data_user/Data_Sent_Request/"+username+".txt").c_str(),ios::app);
	addSRF << user << "\t" << findFname << "\t" << findLname << endl;
	addSRF.close();
	
	deleteNode();
}

void Friends::main_showList(){
	cout << "\n\t>>>>> View All Friends <<<<< " << endl;
	cout << "_______________________________________\n" << endl;
	addNode_data_friends(username);
	listNode();
	deleteNode();
	cout << "_______________________________________\n" << endl;
	system("pause");
}

void Friends::main_sentRequest(){
	int i = 0;
	cout << "\n\t>>>>> View Sent Requests <<<<< " << endl;
	cout << "_______________________________________\n" << endl;
	fstream file(("Data_user/Data_Sent_Request/"+username+".txt").c_str());
	while ( getline (file,line) ){
		line.erase(0,2);
      	cout << "\t" << i+1 << ") " << line << endl;
      	i++;
    }
	file.close();
	cout << "_______________________________________\n" << endl;
	system("pause");
}

void Friends::main_acceptFriend(){
	deleteNode();
	string n;
	cout << "\n\t>>>>> Friend Requests <<<<< " << endl;
	addNode_Data_Friends_Request();
	listNode();
	
	pass:
		cout << " You want to confirm? || (1)yes or (2)no : ";
		cin >> n;
		if(n == "1" || n == "2"){
			
		}else{
			cout << "Please select (1) or (2) !!!" << endl;
			goto pass;
		}
		
	if(n == "1" && count > 0){
		cout << "\n\tInput number want to add : ";
		cin >> index_user;
		if(index_user <= count){
			printConfirm_Accept();
		}else{
			cout << "Can not find number" << endl;
			system("pause");
			deleteNode();
		}
	}
	deleteNode(); //addNode_Data_Friends_Request()
}


void Friends::show_status_accept(){
	status_accept = 0;
	ifstream file(("Data_user/Data_Friends_Request/"+username+".txt").c_str());
	while ( getline (file,line) ){
     	  status_accept++;
   	}
	file.close();
}

void Friends::printConfirm_Accept(){
	int check = 0;
	Node *gpass;
	gpass = head;
	for(int i=0;i<count;i++){  
		if(choose_user[index_user] == gpass->Node_username){ //choose_user form list Node
			cout<<"\n AddFriend Name : " << left << gpass->Node_firstname << " " << left << gpass->Node_lastname 
				<<" Complete."<<endl;
			
			findFname = gpass->Node_firstname;
			findLname = gpass->Node_lastname;
			check = 1;
		}
		gpass = gpass->link;
	}
	delete gpass;
	deleteNode();
	cout << "----------------------------------" << endl;
	if(check == 1){
		addNode_Data_Friends_Request();
		saveFile_accept(choose_user[index_user]); // save Data Friend
		remove_Node(choose_user[index_user]);
		remove_Data_Friends_Request();
		deleteNode();
		fstream file(("Data_user/Data_Sent_Request/"+choose_user[index_user]+".txt").c_str());
		while(file >> u >> fn >> ln ){
			addNode(u,fn,ln);
		}
		file.close();
		remove_Node(username);
		remove_Data_Sent_Request(choose_user[index_user]);
		deleteNode();
	}
	system("pause");
}

void Friends::show_status_sentRequest(){
	status_sentRequest = 0;
	ifstream file(("Data_user/Data_Sent_Request/"+username+".txt").c_str());
	while ( getline (file,line) ){
        status_sentRequest++;
    }
	file.close();
}

void Friends::saveFile_accept(string user){
	ofstream saveDF1(("Data_user/Data_Friends/"+username+".txt").c_str(),ios::app);
	saveDF1 << user << "\t" << findFname << "\t" << findLname << endl;
	saveDF1.close();
	
	ofstream saveDF2(("Data_user/Data_Friends/"+user+".txt").c_str(),ios::app);
	saveDF2 << this->username << "\t" << this->fname << "\t" << this->lname << endl;
	saveDF2.close();
}

void Friends::remove_Data_Friends_Request(){
	fstream file(("Data_user/Data_Friends_Request/"+username+".txt").c_str(),ios::out);
	for(Node *temp = head;temp != NULL;temp = temp->link){
		file << temp->Node_username << "\t" << temp->Node_firstname << "\t" << temp->Node_lastname << endl; 
	}
	file.close();
}

void Friends::remove_Data_Sent_Request(string user){
	fstream file(("Data_user/Data_Sent_Request/"+user+".txt").c_str(),ios::out);
	for(Node *temp = head;temp != NULL;temp = temp->link){
		file << temp->Node_username << "\t" << temp->Node_firstname << "\t" << temp->Node_lastname << endl; 
	}
	file.close();
}

void Friends::show_status_allFriend(){
	status_allFriend = 0;
	fstream file(("Data_user/Data_Friends/"+username+".txt").c_str());
	while ( getline (file,line) ){
     	status_allFriend++;
   	}
	file.close();
}

void Friends::main_unFriend(){
	deleteNode();
	string n;
	addNode_data_friends(username);
	cout << "\n\t>>>>> Unfriend <<<<< " << endl;
	listNode();
	pass:
		cout << " You want to unfriend? || (1)yes or (2)no : ";
		cin >> n;
		if(n != "1" || n != "2"){
			
		}else{
			cout << "Please select (1) or (2) !!!" << endl;
			goto pass;
		}
		
	if(n == "1" && count > 0){
		cout << "\n\tInput number want to unfriend : ";
		cin >> index_user;
		if(index_user <= count){
			printConfirm_Unfriend();
		}else{
			cout << "Can not find number" << endl;
			system("pause");
			deleteNode();
		}
	}
	deleteNode();
}

void Friends::printConfirm_Unfriend(){
	int check = 0;
	Node *gpass;
	gpass = head;
	for(int i=0;i<count;i++){  
		if(choose_user[index_user] == gpass->Node_username){
			cout<<"\n Unfriend Name : " << left << gpass->Node_firstname << " " << left << gpass->Node_lastname 
				<<" Complete."<<endl;
			findFname = gpass->Node_firstname;
			findLname = gpass->Node_lastname;
			check = 1;
		}
		gpass = gpass->link;
	}
	delete gpass;
	cout << "----------------------------------" << endl;
	if(check == 1){
		remove_Node(choose_user[index_user]);
		remove_Data_Friends(username);
		deleteNode();
		////////////////////////////////////////////////////////////
		addNode_data_friends(choose_user[index_user]);
		remove_Node(username);
		remove_Data_Friends(choose_user[index_user]);
		deleteNode();
		
	}
	system("pause");
}

void Friends::remove_Data_Friends(string user){
	fstream file(("Data_user/Data_Friends/"+user+".txt").c_str(),ios::out);
	for(Node *temp = head;temp != NULL;temp = temp->link){
		file << temp->Node_username << "\t" << temp->Node_firstname << "\t" << temp->Node_lastname << endl; 
	}
	file.close();
	
}
