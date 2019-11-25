#include <iostream>
#include "Account.h"
#include "Login.h"
#include "Registers.h"
#include "ForgotPassword.h"
#include "Application.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


bool case_login(string u,string p){
	Login *log;
	log = new Login;
	log->setValue(u,p);
	log->mainLogin();
	if(log->getVerify() == 1){
		delete log;
		return true;
	}else{
		delete log;
		return false;
	}
}

int main(int argc, char** argv) {
	string username;
	string password;
	string email;
	string menu;
   ///////////////////////////////////////
	Account *ps;
	Application *mu;
	do{
		system("cls");
		cout << "\n\t>>>>> Main Menu <<<<< " << endl;
		cout << "_______________________________________\n" << endl;
		cout << "\t" << "1) Sign in" << endl;
		cout << "\t" << "2) Sign up " << endl;
		cout << "\t" << "3) Forgot Password " << endl << endl;
		cout << "\t" << "0) Exit Program" << endl;
		cout << "_______________________________________\n" << endl;
		cout << " Press Enter your Selection : ";
		cin >> menu;
		
       	if(menu == "1"){
			system("cls");
			cout << "\n\t>>>> Sign in <<<<" << endl;
			cout << "\n\tUsername : ";
			cin >> username;
			cout << "\tPassword : ";
			cin >> password;
			if(case_login(username,password)){
				mu = new Application;
				mu->print_Menu();
				mu->signOut();
	 			delete mu;
			}
		}
		
		if(menu == "2"){
			system("cls");
			ps = new Registers;
			ps->main();
			delete ps;
		}
		
		if(menu == "3"){
			system("cls");
			ps = new ForgotPassword;
			cout << "\n\t>>>> Forgot Password <<<<" << endl;
			cout << "\n\tInput Username : ";
			cin >> username;
			cout << "\tInput Email : ";
			cin >> email;
			ps->setValue(username,email);
			ps->main();
			delete ps;
		}
		
	}while(menu != "0");
	return 0;
}
