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
//Implementor shall be an abstract class
//The code implementors can be added to other platforms without affecting the abstraction codes above
//or the client codes
class CodeImplementor{
public:
	virtual void run() =0;
	virtual ~CodeImplementor(){}
};

class LinuxCodeImplementor:public CodeImplementor{
public:
	virtual void run(){
		cout<<"Linux Platform "<<endl;
	}
};

class WindowsCodeImplementor:public CodeImplementor{
public:
	virtual void run(){
		cout<<"Windows Platform "<<endl;
	}
};

//In bridge pattern we separate the abstraction and the implementation
//So that both can grow independent of each other and there would not be any difference
//in how the client will interact
//In this case, lets say, there is a behavior "Code" which is of several types
//and the code of each type needs to be run on multiple platforms
//The bridge pattern would be very useful in this case
//Since we can add types or code for additional platforms without affecting each other

class Code{
public:
	virtual void desc() = 0;
	virtual void run() = 0;
	void getImplementor(string s);
	virtual ~Code(){
		delete implementor;
	}
	CodeImplementor* implementor;
};

//The task below can also be delegated to a factory pattern
//which shall pick the right implementor based on certain parameters
void Code::getImplementor(string s){
	if(s == "Linux"){
		implementor = new LinuxCodeImplementor();
	}
	else{
		implementor = new WindowsCodeImplementor();
	}
}

class Code_type1:public Code{
public:
	Code_type1(string s){
		getImplementor(s);
	}
	virtual void desc(){
		cout<<"Code of Type 1 compatible on Linux and Windows platform"<<endl;
	}
	virtual void run(){
		cout<<"Code of Type1 running on ";
		implementor->run();
	}
};

class Code_type2:public Code{
public:
	Code_type2(string s){
		getImplementor(s);
	}
	virtual void desc(){
		cout<<"Code of Type 2 compatible on Linux and Windows platform"<<endl;
	}
	virtual void run(){
		cout<<"Code of Type2 running on ";
		implementor->run();
	}
};




int main(){
	Code* codeptr = new Code_type1("Linux");
	codeptr->desc();
	codeptr->run();
	cout<<"\n\n";
	delete codeptr;
	codeptr = new Code_type2("Windows");
	codeptr->desc();
	codeptr->run();
	delete codeptr;
}


