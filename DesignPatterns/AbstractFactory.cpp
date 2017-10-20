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

class Code{
public:
	virtual void printInfo()=0;
	virtual void operation(int a, int b)=0;
	virtual ~Code(){}
};

class Code_PlatformA:public Code{
public:
	virtual void printInfo(){
		cout<<" I am running on Platform A "<<endl;
	}
	virtual void operation(int a, int b){
		cout<<"The result of the operation is "<<a+b<<endl;
	}
};

class Code_PlatformB:public Code{
public:
	virtual void printInfo(){
		cout<<" I am running on Platform B "<<endl;
	}
	virtual void operation(int a, int b){
		cout<<"The result of the operation is "<<a*b<<endl;
	}
};

class Factory{
public:
	Factory(Code* cx=nullptr):c(cx){}
	virtual Code* getInstance()=0;
	virtual ~Factory(){
		delete c;
	}
	Code* c;
};

class PlatformA_factory:public Factory{
public:
	PlatformA_factory(Code* cx=nullptr):Factory(cx){}
	virtual Code* getInstance(){
		if(!c){
			c = new Code_PlatformA();
		}
		return c;
	}
	~PlatformA_factory(){
		cout<<"Calling the destructor for PlatformA operation"<<endl;
	}
};

class PlatformB_factory:public Factory{
public:
	virtual Code* getInstance(){
		if(!c){
			c= new Code_PlatformB();
		}
		return c;
	}
	~PlatformB_factory(){
		cout<<"Calling the destructor for PlatformB operation"<<endl;
	}
};

class Client{
	Factory* f;
	Code* c_derived;
public:
	Client(Factory* fx, Code* c=nullptr):f(fx), c_derived(c){}
	void carryOperation(int a, int b){
		f->getInstance()->operation(a, b);
	}
	~Client(){
		delete f;
	}

};

int main(){
	int a=32, b=16;
	Factory* f = new PlatformB_factory();
	Client c_B(f);
	c_B.carryOperation(a, b);
	Factory* f_a = new PlatformA_factory();
	Client c_A(f_a);
	c_A.carryOperation(a, b);
}
