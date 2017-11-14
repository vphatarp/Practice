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

//Receiver class
class Operation{
public:
	int add(int a, int b){
		return a+b;
	}
	int sub(int a, int b){
		return a-b;
	}
	int mul(int a, int b){
		return a*b;
	}
};

//The command class shall convert the requests into objects
//This can be later used to queue, to support undo-redo operations, to support logging etc.
class Command{
public:
	virtual int execute(int, int)=0;
	virtual ~Command(){};
};

//The concrete command subclass which specifies the coupling between the receiver and the action
class SubCommand:public Command{
	Operation* receiver;
	typedef int (Operation::* MathOperation) (int, int);
	MathOperation funcptr;
public:
	SubCommand(Operation* r, MathOperation f):receiver(r), funcptr(f){}
	virtual int execute(int a, int b){
		return (receiver->*funcptr)(a, b);
	}
};

//enum to keep track of the operation being performed
enum{
	ADD = 0,
	SUB,
	MUL,
};


//Logging class is being created to be able to store the history of operations performed
class logging{
public:
	int result;
	int integer1;
	int integer2;
	string op;
	logging(int r, int i1, int i2, string s):result(r), integer1(i1), integer2(i2), op(s){}
};

//CommandInvoker class shall be responsible to log the operations
//It can also be expanded to support undo-redo actions.

class CommandInvoker{
	vector<logging> log;
	Operation obj;
	Command* cmdArray[3] = {new SubCommand (&obj, &Operation::add), new SubCommand (&obj, &Operation::sub), cmdArray[MUL] = new	SubCommand (&obj, &Operation::mul)};
public:
	int operation(int a, int b, int c){
		string op;
		if(a == ADD){
			op = "Addition";
		}
		else if(a == SUB){
			op = "Subtraction";
		}
		else{
			op = "MUltiplication";
		}
		int result = cmdArray[a]->execute(b, c);
		log.push_back(logging(result, b, c, op) );
		return result;
	}
	void printLog(){
		for(auto it = log.begin();it != log.end(); ++it){
			cout<< it->op<< " was performed on the numbers "<<it->integer1<<" and "<<it->integer2<<" to obtain "<<it->result<<endl;
		}
	}
};

int main(){
	//will be simulating operation (((2 + 3)*90)+ 245 - 32)* 49
	CommandInvoker cd;
	int result = 0;
	result = cd.operation(ADD, 2, 3);
	result = cd.operation(MUL, result, 90);
	result = cd.operation(ADD, result, 245);
	result = cd.operation(SUB, result, 32);
	result = cd.operation(MUL, result, 49);
	cout<<"The result is "<< result<<endl;
	cd.printLog();
}

















