#ifndef SETTINGS_H
#define SETTINGS_H

#include "LinkedList.h"
#include "Account.h"
class Settings : public LinkedList,public Account
{
	public:
		Settings();
		void main();
		void case1_pass();
		void case2_log();
	protected:
		string u,p,fn,ln,em;
		string newPass;
		string oldPass;
		string line;
};

#endif
