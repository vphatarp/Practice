/*
 * main.cpp
 *
 *  Created on: Sep 29, 2017
 *      Author: eebo
 */




#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <initializer_list>
#include <memory>

using namespace std;

class Operation;

//Keeping the example simple by recording only the integer value from the operation class
class Memento{
	int value;
public:
	friend class Operation;  //This allows the Operation class below complete access to this class but the other classes 
	                         //The other classes will have access for just passing the objects or pointers to Memento class
	Memento(int v):value(v){}
};

//Operation class is the Originator
class Operation{
	int result;
public:
	Operation(int i=0):result(i){}
	void add(int b){
		result += b;
	}
	void sub(int b){
		result -= b;
	}
	void mul(int b){
		result = result * b;
	}
	int getResult(){
		return result;
	}
	//Passes on the snapshot to the Caretaker class
	Memento* createMemento(){
		return new Memento(result);
	}
	//Command back from Caretaker to undo the operation
	void setMemento(Memento* m){
		result = m->value;
		delete m;
	}
};

//The command class shall convert the requests into objects
//This can be later used to queue, to support undo-redo operations, to support logging etc.
class Command{
public:
	virtual void execute(int)=0;
	virtual ~Command(){};
};

//The concrete command subclass which specifies the coupling between the receiver and the action
class SubCommand:public Command{
	Operation* receiver;
	typedef void (Operation::* MathOperation) (int);
	MathOperation funcptr;
public:
	SubCommand(Operation* r, MathOperation f):receiver(r), funcptr(f){}
	virtual void execute(int a){
		(receiver->*funcptr)(a);
	}
};

//enum to keep track of the operation being performed
enum{
	ADD = 0,
	SUB,
	MUL,
	INIT,
};


//Logging class is being created to be able to store the history of operations performed
class logging{
public:
	int integer1;
	string op;
	logging(int i1, string s):integer1(i1), op(s){}
};

//CommandInvoker class shall be responsible to log the operations
//It can also be expanded to support undo-redo actions.

//CommandInvoker class is the Caretaker class
class CommandInvoker{
	vector<logging> log;
	Operation obj;
	Command* cmdArray[3] = {new SubCommand (&obj, &Operation::add), new SubCommand (&obj, &Operation::sub), new	SubCommand (&obj, &Operation::mul)};
	vector<Memento* > memList;
public:
	CommandInvoker(int a):obj(a){
		log.push_back(logging(a, "Initialized"));
		memList.push_back(obj.createMemento());
	}

	void operation(int a, int c){
		string op;
		if(a == ADD){
			op = "Addition";
		}
		else if(a == SUB){
			op = "Subtraction";
		}
		else if(a == MUL){
			op = "Multiplication";
		}
		else{
			op = "Initialized";
		}
		cmdArray[a]->execute(c);
		memList.push_back(obj.createMemento());
		log.push_back(logging(c, op) );
	}

	void undoOperation(){
		memList.pop_back();
		obj.setMemento(memList[memList.size() - 1]);
		log.pop_back();

	}

	void printLog(){
		for(auto it = log.begin();it != log.end(); ++it){
			if(it->op == "Initialized"){
				cout<<"The object was initialized with value "<<it->integer1<<endl;
			}
			else{
				cout<< it->op<< " was performed on the object with  "<<it->integer1<<endl;
			}

		}
	}
	int getResult(){
		return obj.getResult();
	}
};

int main(){
	//will be simulating operation (((2 + 3)*90)+ 245 - 32)* 49
	CommandInvoker cd(2);
	cd.operation(ADD, 3);
	cd.operation(MUL, 90);
	cd.operation(ADD, 245);
	cd.operation(SUB, 32);
	cd.operation(MUL, 49);
	cout<<"The result of the above operations is "<<cd.getResult()<<endl;
	cd.undoOperation();
	cout<<"The result of the above operations is "<<cd.getResult()<<endl;
	cd.printLog();
}
