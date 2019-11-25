#ifndef FORGOTPASSWORD_H
#define FORGOTPASSWORD_H
#include "LinkedList.h"
#include "Account.h"
class ForgotPassword : public LinkedList,public Account
{
	public:
		ForgotPassword();
		void main();
		void setValue(string u,string n);
		void print(string user);
};

#endif
