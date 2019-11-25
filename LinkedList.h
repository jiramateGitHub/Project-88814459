#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
class LinkedList
{
	public:
		LinkedList();
		Node *head;
		Node *tail;
		void addNode(string u,string p,string f,string l,string e);
		void addNode(string u,string f,string l);
		void deleteNode(); 
		bool isEmpty();
		void remove_Node(string user); // request and status
		bool findUserPass(string u,string p);
		bool findUsername(string u);
		bool findPassword(string u,string e);
		bool findName(string f,string l);
		string getUsername(string f,string l);
	protected:
		int count;
};

#endif
