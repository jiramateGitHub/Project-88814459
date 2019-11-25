#include "Application.h"

Application::Application()
{

}

void Application::print_Menu(){
	do{
		system("cls");
		cout << "\n\t>>>>> Profile <<<<< " << endl;
		cout << "_______________________________________\n" << endl;
		print_Profile();
		cout << "_______________________________________\n" << endl;
		cout << "\t1) Friends " << endl;
		cout << "\t2) Timeline " << endl << endl;
		cout << "\t3) Settings " << endl << endl;
		cout << "\t0) Sign Out" << endl;
		cout << "_______________________________________\n" << endl;
		cout << " Enter your Selection : ";
		cin >> menu;
		if(menu == "1"){
			system("cls");
			ps = new Friends;
			ps->main();
			delete ps;
		}
		if(menu == "2"){
			system("cls");
			ps = new Timeline;
			ps->main();
			delete ps;		
		}
		if(menu == "3"){
			system("cls");
			ps = new Settings;
			ps->main();
			delete ps;	
		}
	}while(menu != "0");
}

void Application::signOut(){
	ofstream savedata("Data_user/data_using.txt");
	savedata << "";
	savedata.close();
}

void Application::print_Profile(){
	ifstream user("Data_user/data_using.txt");
	user >> u >> p >> fn >> ln >> em;
	user.close();
	cout << "\tName : " << fn << "\t" << ln << endl;
}

