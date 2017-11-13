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


//For learning proxy pattern, lets consider an example of accessing a file
//Which has different security levels for being accessed, based on the roles of the users
//Also we can keep a count on how many users are currently trying to access the file



class Resource{
protected:
	string name;
public:
	Resource(string s):name(s){}
	virtual void read()=0;
	virtual void write()=0;
	virtual void access()=0;
	virtual ~Resource(){}
};

class File:public Resource{
public:
	File(string s):Resource(s){}
	virtual void read(){
		cout<<"Read file by the name "<<name<<endl;
	}
	virtual void write(){
		cout<<"Write modifications to the file  "<<name<<endl;
	}
	virtual void access(){
		cout<<"Access file by the name "<<name<<endl;
	}
};

class FileProxy:public Resource{
	File* fileptr=nullptr;
	string userRole;
public:
	FileProxy(string filename, string role):Resource(filename), fileptr(new File(filename)), userRole(role){}
	virtual void read(){
		fileptr->read();
	}
	virtual void write(){
		if(userRole != "Admin"){
			cout<<"This particular user is not allowed to access the file."<<endl;
		}
		else{
			fileptr->write();
		}
	}
	virtual void access(){
		fileptr->access();
	}
};

int main(){
	Resource* r = new FileProxy("Database", "Admin");
	r->write();
	r->read();
}



