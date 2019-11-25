#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
class Account
{
	public:
		Account();
		virtual void main();
		virtual void setValue(string u,string n);
		string username;
		string password;
		string email;
		string fname;
		string lname;
};

#endif
