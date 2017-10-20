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

using namespace std;

//Describes the abstract Composite class which represents the hierarchy
class Composite{
public:
	Composite(string s, string d, int sal):name(s), designation(d),salary(sal){}
	virtual void add(Composite* c) = 0;
	virtual void printInfo() = 0;
	virtual void remove(Composite* c)=0;
	virtual ~Composite(){}

	string name;
	string designation;
	int salary;
};


//Describes the Leaf Node
class Engineer:public Composite{
public:
	Engineer(string s, string d, int sal):Composite(s, d, sal){}
	virtual void add(Composite* c){}
	virtual void remove(Composite* c){}
	virtual void printInfo();
};

void Engineer::printInfo(){
	cout<<"At the designation of "<<designation<<" is "<<name<<" with a salary of "<<salary<<endl;
}


//Describes the Complex Nodes which actually represents a position or hierarchy rather than an individual
//Thus enabling the client to treat an individual and the position in the same way
class Manager:public Composite{
public:
	Manager(string s, string d, int sal):Composite(s, d, sal){}
	virtual void add(Composite* c);
	virtual void remove(Composite* c);
	virtual void printInfo();
	std::list<Composite* > childList;
};

void Manager::add(Composite* c){
	childList.push_back(c);
}

void Manager::remove(Composite* c){
	std::list<Composite*>::iterator it = childList.begin();
	while(*it != c){
		it++;
	}
	childList.erase (it);
}

void Manager::printInfo(){
	cout<<"At the designation of "<<designation<<" is "<<name<<" with a salary of "<<salary<<endl;
	if(!childList.empty()){
		for(std::list<Composite*>::iterator it = childList.begin(); it != childList.end(); it++ ){
			(*it)->printInfo();
		}
	}
}

//The class below shows that the positions can just be added without any loss of information 
//At the same time it is easier to do so with the Composite pattern
class TeamLeader:public Manager{
public:
	TeamLeader(string s, string d, int sal):Manager(s, d, sal){}
};




int main(){
	Engineer e("Vignesh", "Senior Software Engineer", 40000);
	Engineer e1("Vignesh1", "Senior Software Engineer", 40000);
	Engineer e2("Vignesh2", "Senior Software Engineer", 40000);
	Engineer e3("Vignesh3", "Senior Software Engineer", 40000);
	TeamLeader tl("tito", "Team Lead Protocol Design", 60000);
	Manager President("Vartak", "President", 10000000);
	Manager Director("Charles", "Director", 90000);
	President.add(&Director);
	Director.add(&e);
	Director.add(&e1);
	Director.add(&e2);
	Director.add(&tl);
	tl.add(&e3);
	President.printInfo();
	cout<<"\n\n\n\n\n";
	tl.remove(&e3);
	President.printInfo();
}
