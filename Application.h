#ifndef APPLICATION_H
#define APPLICATION_H
#include "Account.h"
#include "Friends.h"
#include "Settings.h"
#include "Timeline.h"
class Application
{
	public:
		Application();
		void signOut();
		void print_Menu();
		void print_Profile();
	private:
		string u,p,fn,ln,em;
		string menu;
		Account *ps;
};

#endif
