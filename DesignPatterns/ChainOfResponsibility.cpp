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


class Withdrawal{
	Withdrawal* next = nullptr;
public:
	void add(Withdrawal* nextPointer){
		if(next){
			next->add(nextPointer);
		}
		else{
			next = nextPointer;
		}

	}
	virtual void calculateDenom(int amount){
		next->calculateDenom(amount);
	}
	virtual ~Withdrawal(){}
};


class Denom100:public Withdrawal{
public:
	virtual void calculateDenom(int amount){
		int balanceAmount = amount;
		if(amount > 100){
			cout<<"Withdrawing "<<(amount/100)<<" number of 100 unit notes "<<endl;
			balanceAmount = amount % 100;
		}
		Withdrawal::calculateDenom(balanceAmount);
	}
};

class Denom50:public Withdrawal{
public:
	virtual void calculateDenom(int amount){
		int balanceAmount = amount;
		if(amount > 50){
			cout<<"Withdrawing "<<(amount/50)<<" number of 50 unit notes "<<endl;
			balanceAmount = amount % 50;
		}
		Withdrawal::calculateDenom(balanceAmount);
	}
};

class Denom10:public Withdrawal{
public:
	virtual void calculateDenom(int amount){
		int balanceAmount = amount;
		if(amount > 10){
			cout<<"Withdrawing "<<(amount/10)<<" number of 10 unit notes "<<endl;
			balanceAmount = amount % 10;
		}
		cout<<"Withdrawing "<<balanceAmount<<" number of 1 unit notes"<<endl;
	}
};

class DescendingWithdrawal{
	Denom100 d100;
	Denom50 d50;
	Denom10 d10;
public:
	DescendingWithdrawal(){
		d100.add(&d50);
		d50.add(&d10);
	}
	void withdraw(int amount){
		d100.calculateDenom(amount);
	}
};

int main(){
	DescendingWithdrawal dh;
	dh.withdraw(5634);
}
















