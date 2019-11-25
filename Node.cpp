#include "Node.h"

Node::Node(string u,string p,string f,string l,string e)
{
	this->Node_username = u ;	
	this->Node_password = p;	
	this->Node_firstname = f;
	this->Node_lastname = l;
	this->Node_email = e;
	link = NULL;
}

Node::Node(string u,string f,string l){
	this->Node_username = u ;	
	this->Node_firstname = f;
	this->Node_lastname = l;
	link = NULL;
}

