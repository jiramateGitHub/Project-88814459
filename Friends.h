#ifndef FRIENDS_H
#define FRIENDS_H
#include "LinkedList.h"
#include "Account.h"
class Friends : public LinkedList,public Account 
{
	public:
		Friends();
		void addNode_data_user();
		void addNode_data_friends(string user);
		void addNode_Data_Friends_Request();
		void addNode_Data_Sent_Request();
		void readFile_data_using();
		void listNode();
		
		void main();
			void main_addFriend(); // case (1)
				void addFriend_saveFile();
				void printConfirm_addFriend();
				
			void main_unFriend();
				void printConfirm_Unfriend();
				void remove_Data_Friends(string user);
				
			void main_acceptFriend(); //case (3)
				void show_status_accept();
				void printConfirm_Accept();
				void saveFile_accept(string user);
				
				void remove_Data_Friends_Request();
				void remove_Data_Sent_Request(string user);
				
			void main_sentRequest(); // case (4)
				void show_status_sentRequest();
				
			void main_showList(); // case (5)
				void show_status_allFriend();
			
	protected:
		int status_accept;
		int status_sentRequest;
		int status_allFriend;
		int index_user;
		string choose_user[999];
		
		string line;
		string menu;
		string findFname;
		string findLname;
		string u,p,fn,ln,em;
};

#endif
