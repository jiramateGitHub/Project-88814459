#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <time.h>
using namespace std;
class Node
{
	public:
		Node(string u,string p,string f,string l,string e);
		Node(string u,string f,string l);
		Node *link;
		string Node_username;
		string Node_password;
		string Node_email;
		string Node_firstname;
		string Node_lastname;
};

#endif
