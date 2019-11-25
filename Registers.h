#ifndef REGISTERS_H
#define REGISTERS_H
#include "LinkedList.h"
#include "Account.h"
class Registers : public LinkedList,public Account
{
	public:
		Registers();
		void main();
		void printConfirm();
		void saveFile();
		void addData_user();
	protected:
		int check;
};

#endif
