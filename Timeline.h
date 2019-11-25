#ifndef TIMELINE_H
#define TIMELINE_H
#include "LinkedList.h"
#include "Account.h"
class Timeline : public LinkedList,public Account
{
	public:
		Timeline();
		void addNode_data_friends();
		void main();
		void write_post();
		void my_post(); 
		void story();
		void show_story(int indexx);
	protected:
		string u,p,fn,ln,em;
		string writePost;
		string user_friend[5000];
		string post[5000];
		string post_time[5000];
		int status_story[5000];
		int amount_friend;
		int index_user;
		int check;
};

#endif
