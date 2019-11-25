#include "Notifications.h"

Notifications::Notifications()
{
}

void Notifications::main(){
	cout << "\n\t>>>>> View Notifications <<<<< " << endl;
	cout << "_______________________________________\n" << endl;
	show_noti();
	cout << "_______________________________________\n" << endl;
	string n;
	pass:
		cout << " You want to clear all notifications? || (1)yes or (2)no : ";
		cin >> n;
		if(n == "1" || n == "2"){
			if(n == "1"){
				delete_noti();
			}
		}else{
			cout << "Please select (1) or (2) !!!" << endl;
			goto pass;
		}
}
void Notifications::delete_noti(){
	ofstream noti;
	noti.open(("Data_user/Notifications/"+u+".txt").c_str(),ios::out);
	if(noti.is_open()){
		noti << "";
	}
	noti.close();
}
void Notifications::show_noti(){
	ifstream user;
	user.open("Data_user/data_using.txt");
	if(user.is_open()){
		while(user >> u >> p >> fn >> ln >> em){
		}
	}
	user.close();
	////////////////////////////////////////////////////////////////
	string line;
	int i=0;
	ifstream noti;
	noti.open(("Data_user/Notifications/"+u+".txt").c_str());
	if(noti.is_open()){
		while(getline(noti,line)){
			word[i] = line;
			i++;
		}
		int index = 0;
		for(int j=i-1;j>=0;j--){
			if(j == i-1){
				cout << index+1 << ") " << word[j] << " (NEW) "<< endl;
			}else{
				cout << index+1 << ") " << word[j] << endl;
			}
			
			index++;
		}
			
	}else{
		cout << "Not File.\n";
	}
	noti.close();
}
