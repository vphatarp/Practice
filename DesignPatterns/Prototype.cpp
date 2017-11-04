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

//The program below will be used to clone the superHeroes for evil
//As soon as prototypes of each superHero is created, multiple clones shall be created of each superHero


//Prototype class
class SuperHero{
public:
	//Defining 2 static functions and 2 static data members
	 static shared_ptr<SuperHero> toClone(string& type);
	 static void addPrototype(shared_ptr<SuperHero> heroType);
	 static int noTypes;

	 //Virtual functions would be the ones shared between the Base and Derived classes
	 //In the sense the interface
     virtual void desc()=0;
     virtual shared_ptr<SuperHero> clone()=0;
     virtual ~SuperHero(){}
     
     //The string below would be used by the client to differentiate between the objects to be cloned
     string heroName;
private:
     //Holding a map of SuperHero names to the prototypes
     //Each sub class will be registering itself which will be stored in this map
     static unordered_map<string, shared_ptr<SuperHero> > _prototypes;
};

//Declaring static data members
unordered_map<string, shared_ptr<SuperHero> > SuperHero::_prototypes = {{"", nullptr}};
int SuperHero::noTypes =0;

//Defining static member functions
void SuperHero::addPrototype(shared_ptr<SuperHero> heroType){
        _prototypes[heroType->heroName] = heroType;
}

shared_ptr<SuperHero> SuperHero::toClone(string& type){
	return _prototypes[type]->clone();
}


//The subclass
class SuperMan:public SuperHero{
public:
	//Each of the subclass shall have a static object
	//to be used for registering with the parent class
        static SuperMan _superman;
        static int count;
        int id;
public:
        virtual void desc(){
                cout<<"I am SuperMan with ID "<<id<<endl;
        }
        virtual shared_ptr<SuperHero> clone();
        SuperMan(); //Shall be used only for static object
        SuperMan(const SuperMan& s);  //Will do a deep copy of the prototype
};

int SuperMan::count =0;
SuperMan SuperMan::_superman;

SuperMan::SuperMan(){
        heroName = "SuperMan";
        addPrototype(shared_ptr<SuperMan>(this, [](SuperMan* ){}));
        //Extremely important to declare a custom deleter
        //Since the pointer is not actually owned by this class, an error is raised if the pointer is deleted
        //Causing the program to crash
        //The custom deleter is instructing not to delete the pointer
        //the static object will be deleted when the program ends
}

SuperMan::SuperMan(const SuperMan& s){
	heroName = s.heroName;
    id = ++count;
}
shared_ptr<SuperHero> SuperMan::clone(){
        return shared_ptr<SuperMan>(new SuperMan(SuperMan::_superman));
}

//The second subclass
class Flash:public SuperHero{
public:
        static Flash _flash;
        static int count;
        int id;
public:
        virtual void desc(){
                cout<<"I am Flash with ID "<<id<<endl;
        }
        virtual shared_ptr<SuperHero> clone();
        Flash();
        Flash(const Flash& s);
};

int Flash::count =0;
Flash Flash::_flash;

Flash::Flash(){
       heroName = "Flash";
       addPrototype(shared_ptr<Flash>(this, [](Flash* s){}));
}

Flash::Flash(const Flash& s){
        heroName = s.heroName;
        id = ++count;
}
shared_ptr<SuperHero> Flash::clone(){
        return shared_ptr<Flash>(new Flash(Flash::_flash));
}

int main(){
	//As can be seen the client has no idea about the underlying subclasses and how those are created.
	vector<shared_ptr<SuperHero> > vec;
	string super = "Flash";
	for(int i=0;i<10;i++){
		vec.push_back(SuperHero::toClone(super));
		vec[i]->desc();
	}
	super = "SuperMan";
	for(int i=10;i<20;i++){
		vec.push_back(SuperHero::toClone(super));
		vec[i]->desc();
	}
}










