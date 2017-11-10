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


//Flyweight design pattern basically reduces the number of objects that need to be created
//By taking into account the fact that some data would be shared between objects
//So instead of assigning the space for the same data again and again
//The objects can contain references to the shared data
//Which can be shared between multiple objects thus reducing the amount of memory or resources needed
//In this example we will create a flyweight class for holding recurring first name for class Person


//Using Flyweight pattern, the memory used for creating 10000 objects with the same first name is 240001
//and without the pattern, the memory for creating the same number of objects is 400000;

class StringFactory{
	static std::unordered_map<std::string, std::shared_ptr<string> > nameMap;
public:
	static std::shared_ptr<string> getName(string s){
		auto iter = nameMap.find(s);
		if(iter != nameMap.end()){
			return iter->second;
		}
		nameMap[s] = make_shared<string>(s);
		return nameMap[s];
	}
};

std::unordered_map<std::string, std::shared_ptr<string> > StringFactory::nameMap;

class Person{
	std::shared_ptr<string> first = nullptr;
	static int id;
	int no;
public:
	Person(string s){
		first = StringFactory::getName(s);
		no = ++id;
	}
	void printInfo();
};

int Person::id = 0;

void Person::printInfo(){
	cout<<"The person "<<*first<<" has an id "<<no<<endl;
}

int main(){
	std::vector<Person> p;
	int total = 0;
	for(int i=0; i<10000;i++){
		p.emplace_back(Person("John"));
		total += sizeof(p[i]);
	}
	total += sizeof(StringFactory);
	cout<<"Total memory usage "<<total<<endl;
}


/*
 * Program without Flyweight pattern
 * The output of the program is "Total memory usage 400000 "


class Person{
	string first;
    static int id;
    int no;
public:
    Person(string s){
    	first = s;
    	no = ++id;
    }
    void printInfo();
};

int Person::id = 0;

void Person::printInfo(){
	cout<<"The person "<<first<<" has an id "<<no<<endl;
}

int main(){
	std::vector<Person> p;
    int total = 0;
    for(int i=0; i<10000;i++){
    	p.emplace_back(Person("John"));
    	total += sizeof(p[i]);
    }
    cout<<"Total memory usage "<<total<<endl;
}

*/

