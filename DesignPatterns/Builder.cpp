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

//The first part making up the component
class UpperLimb{
public:
	string desc;
public:
	UpperLimb(string s):desc(s){}
};

//The second part making up the component
class LowerLimb{
public:
	string desc;
public:
	LowerLimb(string s):desc(s){}
};

//The third part making up the component
class SuperTrait{
public:
	string desc;
public:
	SuperTrait(string s):desc(s){}
};

//In this program we are trying to build the right superhero for the input
//Below is what superhero class looks like
class SuperHero{
public:
	std::shared_ptr<UpperLimb> ul;
	std::shared_ptr<LowerLimb> ll;
	std::shared_ptr<SuperTrait> st;
	void print();
};

void SuperHero::print(){
	if(ul != nullptr){
		cout<<ul->desc<<endl;
	}
	if(ll != nullptr){
		cout<< ll->desc<<endl;
	}
	if(st != nullptr){
		cout<< st->desc<<endl;
	}
}

class Builder{
public:
	//As per gang of four description Builder would not have pure virtual functions
	//Ideally the functions would have some default code to run
	//The sub classes would override them if needed
	virtual void getUpperLimb(){}
	virtual	void getLowerLimb(){}
	virtual	void getSuperTrait(){}
	virtual std::shared_ptr<SuperHero> getSuperHero(){return nullptr;}
	virtual ~Builder(){}
};

//Below is the concrete builder being constructed
class SuperHuman: public Builder{
	std::shared_ptr<SuperHero> superhero;
public:
	SuperHuman();
	virtual void getUpperLimb();
	virtual	void getLowerLimb();
	virtual	void getSuperTrait();
	virtual std::shared_ptr<SuperHero> getSuperHero();
};

SuperHuman::SuperHuman(){
	superhero = std::shared_ptr<SuperHero>(new SuperHero());
}

void SuperHuman::getUpperLimb(){
	superhero->ul = std::shared_ptr<UpperLimb>(new UpperLimb("Super Powerful Arms"));
}

void SuperHuman::getLowerLimb(){
	superhero->ll = std::shared_ptr<LowerLimb>(new LowerLimb("Super Powerful Legs"));
}

void SuperHuman::getSuperTrait(){
	superhero->st = std::shared_ptr<SuperTrait>(new SuperTrait("Super Human"));
}

std::shared_ptr<SuperHero> SuperHuman::getSuperHero(){
	return superhero;
}


//The descriptor shall call the functions needed to make the builder build the particular product
class Descriptor{
public:
	std::shared_ptr<SuperHero> createHero(std::shared_ptr<Builder> builder);
};
std::shared_ptr<SuperHero> Descriptor::createHero(std::shared_ptr<Builder> builder){
	builder->getLowerLimb();
	builder->getUpperLimb();
	builder->getSuperTrait();
	return builder->getSuperHero();
}

class SuperTurtle:public Builder{
	std::shared_ptr<SuperHero> superhero;
public:
	SuperTurtle();
	virtual void getUpperLimb();
	virtual	void getSuperTrait();
	virtual std::shared_ptr<SuperHero> getSuperHero();
};

SuperTurtle::SuperTurtle(){
	superhero = std::shared_ptr<SuperHero>(new SuperHero());
}

void SuperTurtle::getUpperLimb(){
	superhero->ul = std::shared_ptr<UpperLimb>(new UpperLimb("Three Fingered Arms, but extremely fast"));
}

void SuperTurtle::getSuperTrait(){
	superhero->st = std::shared_ptr<SuperTrait>(new SuperTrait("Extreme Ninja skills, much better than humans"));
}

std::shared_ptr<SuperHero> SuperTurtle::getSuperHero(){
	return superhero;
}

int main(){
	Descriptor d;
	std::shared_ptr<SuperHuman> sh(new SuperHuman());
	std::shared_ptr<SuperTurtle> sg(new SuperTurtle());
	std::shared_ptr<SuperHero> hero;
	cout<<"Starting up the super hero factory \n\n"<<endl;
	cout<<"Creating a super human with the following traits: "<<endl;
	hero = d.createHero(std::shared_ptr<Builder>(sh));
	hero->print();

	cout<<"\n\n";
	cout<<"Creating Ninja Turtles "<<endl;
	hero = d.createHero(std::shared_ptr<Builder>(sg));
	hero->print();
}




