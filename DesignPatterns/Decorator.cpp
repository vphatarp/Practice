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

class Superhuman{
public:
	virtual void powerup(){
		cout<<"I am developing super powers "<<endl;
	}
	virtual ~Superhuman(){}
};

class Superdecorator:public Superhuman{
public:
	Superdecorator(Superhuman* s):sh(s){}
	Superhuman* sh;
	virtual void powerup(){
		sh->powerup();
	}
	~Superdecorator(){
		delete sh;
		cout<<"Deleting all your powers "<<endl;
	}
};

class Superstrength:public Superdecorator{
public:
	Superstrength(Superhuman* s):Superdecorator(s){}
	virtual void powerup(){
		Superdecorator::powerup();
		cout<<"Gaining superhuman strength is awesome! "<<endl;
	}
	~Superstrength(){
		cout<<"Loosing super strength, time for code alert "<<endl;
	}
};

class Heatvision:public Superdecorator{
public:
	Heatvision(Superhuman* s):Superdecorator(s){}
	virtual void powerup(){
		Superdecorator::powerup();
		cout<<"I think I can fry the chicken using heat vision! "<<endl;
	}
	~Heatvision(){
		cout<<"Heatvision power is being compromised "<<endl;
	}
};

int main(){
	Superhuman* s = new Superhuman();
	Superdecorator* sd = new Superstrength(new Heatvision(s));
	sd->powerup();
	delete sd;
	delete s;
}
