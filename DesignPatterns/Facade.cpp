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

//For this example, lets consider at some point in time
//Cooking would be completely automated
//Right from shopping to cutting to operating the stove and checking if the food tastes good
//Of this complex system, we would be automating making pasta
//Writing a facade class for making pasta simplifies the interface for the client

//Seems more like composition, but it does hide the interface originally in the complex system
//And also provides and easier interface for the client to operate

class GroceryShopping{
public:
	void pickVegetables(){
		cout<<"Pick the right vegetables for making the dish"<<endl;
	}
	void pickFruits(){
		cout<<"Pick up the right fruits for a healthy intake"<<endl;
	}
	void refillDetergents(){
		cout<<"Refill all the washing liquids in the house"<<endl;
	}
	void getBottledWater(){
		cout<<"Getting bottled water this time"<<endl;
	}
	void getPasta(){
		cout<<"The family prefers elbows and alfredo sauce"<<endl;
	}
};

class Cullinary{
public:
	void washIngredients(){
		cout<<"Thoroughly wash the vegetables needed "<<endl;
	}
	void cutVegetables(){
		cout<<"Fine chop the vegetables"<<endl;
	}
	void grateVegetables(){
		cout<<"Grate the vegetables needed"<<endl;
	}
	void addCheese(){
		cout<<"Add the right amount of cheese and sauce"<<endl;
	}
};

class OperateStove{
public:
	void turnOn(){
		cout<<"Turn on the stove"<<endl;
	}
	void turnOff(){
		cout<<"Turn off the stove"<<endl;
	}
	void useOven(){
		cout<<"set the temperature of the oven and start preheat"<<endl;
	}
};

class Cook{
public:
	void getUtensil(){
		cout<<"Get the utensil"<<endl;
	}
	void putIngredients(){
		cout<<"Add the ingredients"<<endl;
	}
	void bringtoBoil(){
		cout<<"Bring the whole dish to a boil"<<endl;
	}
};

class FacadePasta{
	GroceryShopping shopping;
	Cullinary cutting;
	OperateStove stove;
	Cook cooking;
public:
	void makePasta(){
		shopping.pickVegetables();
		shopping.getPasta();
		cutting.cutVegetables();
		stove.turnOn();
		cooking.getUtensil();
		cooking.putIngredients();
		cooking.bringtoBoil();
		cutting.addCheese();
	}
};

int main(){
	FacadePasta pasta;
	pasta.makePasta();
}




