#include "LinkedList.h"

LinkedList::LinkedList()
{
	count = 0;
}

void LinkedList::addNode(string u,string p,string f,string l,string e){
	Node *newNode = new Node(u,p,f,l,e);
	if(count == 0){
		head = newNode;
		tail = newNode;
	}else{
		tail->link = newNode;
		tail = newNode;
	}
	count++;
}

void LinkedList::addNode(string u,string f,string l){
	Node *newNode = new Node(u,f,l);
	if(count == 0){
		head = newNode;
		tail = newNode;
	}else{
		tail->link = newNode;
		tail = newNode;
	}
	count++;
}

bool LinkedList::isEmpty(){
	if(count == 0){
		return true;
	}else{
		return false;
	}
}

void LinkedList::deleteNode(){
	//cout << "Delete Node" << endl;
	for(int i = 0; i < count; i++){
		Node *tmp = head;
		//cout << "Del head: " << head << " |temp: " << tmp << " |link: " << tmp->link << endl;
		head = head->link;
		delete tmp;
	}
 	head = NULL;
	tail = NULL;
	count = 0;
}

void LinkedList::remove_Node(string user){
	//cout << "remove_Node User:" << user << endl;
	//showNode();
	int round = 1;
	Node *ptemp;
	for(Node *temp = head;temp != NULL;temp = temp->link){
		if(round == 1){
			ptemp = temp;	
			if(temp->Node_username == user){
				if(temp == head && temp == tail){
					delete temp;
					head = NULL;
					tail = NULL;
				}else if(temp == head){
					head = head->link;
					delete temp;
				}
				count--;
				break;
			}
		}else{
			if(temp->Node_username == user){
				if(temp == tail){
					tail = ptemp;
					tail->link = NULL;
					delete temp;
				}else{
					ptemp->link = temp->link;
					delete temp;
				}
				count--;
				break;
			}else{
				ptemp = temp;
			}
		}
		round++;
	}
	//showNode();
}

bool LinkedList::findUserPass(string u,string p){
	for(Node *temp = head;temp != NULL;temp = temp->link){
		//cout << "head: " << head << " |temp: " << temp << " |link: " << temp->link << endl;
		if(temp->Node_username == u && temp->Node_password == p){
			//cout << "found it " << u << " : " << temp << endl;
			ofstream savedata("Data_user/data_using.txt");
			savedata << temp->Node_username << "\t";
			savedata << temp->Node_password << "\t";
			savedata << temp->Node_firstname << "\t";
			savedata << temp->Node_lastname << "\t";
			savedata << temp->Node_email << "\t\n";
			savedata.close();
			
			ofstream savetime(("Data_user/History_Log/"+temp->Node_username+".txt").c_str(),ios::app);
			time_t rawtime;
  			time (&rawtime);
			savetime << ctime(&rawtime);
  			savetime.close();
  			
			return true;
		}
	}
}

bool LinkedList::findUsername(string u){
	for(Node *temp = head;temp != NULL;temp = temp->link){
		if(temp->Node_username == u){
			return true;
		}
	}
}

bool LinkedList::findPassword(string u,string e){
	for(Node *temp = head;temp != NULL;temp = temp->link){
		if(temp->Node_username == u && temp->Node_email == e){
			return true;
		}
	}
}

bool LinkedList::findName(string f,string l){
	for(Node *temp = head;temp != NULL;temp = temp->link){
		if(temp->Node_firstname == f && temp->Node_lastname == l){
			return true;
		}
	}
}

string LinkedList::getUsername(string f,string l){
	for(Node *temp = head;temp != NULL;temp = temp->link){
		if(temp->Node_firstname == f && temp->Node_lastname == l){
			return temp->Node_username;
		}
	}
}
