#ifndef LOGIN_H
#define LOGIN_H
#include "LinkedList.h"
#include "Account.h"
class Login : public LinkedList , public Account
{
	public:
		Login();
		void mainLogin();
		void setValue(string u,string n);
		int getVerify();
	protected:
		int verify;
};

#endif
