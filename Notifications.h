#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H
#include "LinkedList.h"
#include "Person.h"
class Notifications : public LinkedList,public Person 
{
	public:
		Notifications();
		void main();
		void show_noti();
		void delete_noti();
	protected:
		string u,p,fn,ln,em;
		string word[99];
};

#endif
