#include "Timeline.h"

Timeline::Timeline(){
	for(int i = 0;i<5000;i++){
		user_friend[i] = "";
		post[i] = "";
		post_time[i] = "";
		status_story[i] = 0;
	}
}

void Timeline::addNode_data_friends(){
	string nu,nfn,nln;
	fstream file(("Data_user/Data_Friends/"+u+".txt").c_str());
	while(file >> nu >> nfn >> nln ){
		addNode(nu,nfn,nln);
	}
	file.close();
}

void Timeline::main(){
	string menu;
	ifstream user("Data_user/data_using.txt");
	user >> u >> p >> fn >> ln >> em;
	user.close();
	do{
		system("cls");
		cout << "\n\t>>>>> View Timeline <<<<< " << endl;
		cout << "_______________________________________\n" << endl;
		cout << "\t1) Write a post" << endl;
		cout << "\t2) My post" << endl;
		cout << "\t3) Timeline" << endl;
		cout << "\n\t0) Back" << endl;
		cout << "_______________________________________\n" << endl;
		cout << " Enter your Selection : ";
		cin >> menu;
		if(menu == "1"){
			system("cls");
			write_post();
		}else if(menu == "2"){
			system("cls");
			my_post();
		}else if(menu == "3"){
			system("cls");
			story();
		}else if(menu == "0"){
			menu = "4";
		}
	}while(menu != "4");
	
}

void Timeline::write_post(){
	string n;
	cout << "\n\t>>>>> Write a post <<<<< " << endl;
	cout << "_______________________________________\n" << endl;
	cout << "\tMessage to post (Do not use Spacebar) : ";
	cin >> writePost;
	pass:
		check = 0;
		cout << " You want to confirm? || (1)yes or (2)no : ";
		cin >> n;
		if(n == "1" || n == "2"){
			if(n == "1"){
				check = 1;
			}
		}else{
			cout << "Please select (1) or (2) !!!" << endl;
			goto pass;
		}
	if(check == 1){
		fstream file(("Data_user/Data_Post/"+u+".txt").c_str(),ios::app);
		file << writePost << endl;
		file.close();
		
		ofstream savetime(("Data_user/History_Post/"+u+".txt").c_str(),ios::app);
		time_t rawtime;
  		time (&rawtime);
		savetime << ctime(&rawtime);
  		savetime.close();
  		
  		cout << "\n Your post has been revealed." << endl;
		system("pause");
	}
}

void Timeline::my_post(){
	int index = 0;
	cout << "\n\t>>>>> View My Posts <<<<< " << endl;
	cout << "_______________________________________\n" << endl;
	string line;
	fstream file1(("Data_user/Data_Post/"+u+".txt").c_str());
	while(getline(file1,line)){
		post[index] = line;
		index++;
	}
	file1.close();
	
	index = 0;
	fstream file2(("Data_user/History_Post/"+u+".txt").c_str());
	while(getline(file2,line)){
		post_time[index] = line;
		index++;
	}
	file2.close();
	
	for(int i = 0;i<index;i++){
		cout << " Post : " << post_time[i] << " : " << post[i] << endl; 
	}
	
	cout << "\n_______________________________________\n" << endl;
	system("pause");
}

void Timeline::story(){
	string line;
	amount_friend = 0;
	cout << "\n\t>>>>> View Stories <<<<< " << endl;
	cout << "_______________________________________\n" << endl;
	//////////////////////////////////////////////////////////////////////////////////////
	addNode_data_friends();
	if(isEmpty()){
		cout << "\n---> Not Stories" << endl;
	}else{
		Node *tmp;
		tmp = head;
		for(int i=0;i<count;i++){
			amount_friend++;
			user_friend[i] = tmp->Node_username;
			status_story[i] = 0;
			fstream file(("Data_user/Data_Post/"+user_friend[i]+".txt").c_str());
			while(getline(file,line)){
				status_story[i]++;
			}
			file.close();
			cout << i << ") Name : " << tmp->Node_firstname << " "  << tmp->Node_lastname << " (" << status_story[i] << ")" << endl;
			tmp = tmp->link;
		}
		delete tmp;
	}
	deleteNode();
	//////////////////////////////////////////////////////////////////////////////////////
	cout << "_______________________________________\n" << endl;
	string n;
	pass:
		cout << " You want to view stories? || (1)yes or (2)no : ";
		cin >> n;
		if(n == "1" || n == "2"){
			if(n == "1"){
				cout << "\n\tInput number want to add : ";
				cin >> index_user;
				if(index_user > amount_friend){
					cout << "\n --->Not Number!!" << endl;
					system("pause");
				}else{
					if(status_story[index_user] == 0){
						cout << "\n --->Not Story!!" << endl;
						system("pause");
					}else{
						show_story(index_user);
					}
				}
				
			}
		}else{
			cout << "Please select (1) or (2) !!!" << endl;
			goto pass;
		}
}

void Timeline::show_story(int indexx){
	system("cls");
	int index = 0;
	cout << "\n\t>>>>> View Stories <<<<< " << endl;
	cout << "_______________________________________\n" << endl;
	string line;
	fstream file1(("Data_user/Data_Post/"+user_friend[indexx]+".txt").c_str());
	while(getline(file1,line)){
		post[index] = line;
		index++;
	}
	file1.close();
	
	index = 0;
	fstream file2(("Data_user/History_Post/"+user_friend[indexx]+".txt").c_str());
	while(getline(file2,line)){
		post_time[index] = line;
		index++;
	}
	file2.close();
	
	for(int i = 0;i<index;i++){
		cout << " Post : " << post_time[i] << " : " << post[i] << endl; 
	}
	
	cout << "\n_______________________________________\n" << endl;
	system("pause");
}

