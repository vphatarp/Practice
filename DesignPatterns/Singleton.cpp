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

class Singleton{
	static unique_ptr<Singleton> single;
	Singleton(){}
	Singleton(const Singleton& s)=delete;
	Singleton(const Singleton&& s)=delete;
	Singleton& operator=(const Singleton& s)= delete;
	Singleton& operator=(Singleton&& s)= delete;
public:
	~Singleton()=default;
	static unique_ptr<Singleton>& getInstance(){
		if(!single){
			cout<<"Initializing the class for the first time "<<endl;
			single.reset(new Singleton());
			return single;
		}
		else{
			cout<<"The instance had been initialized earlier. Just returning the already created instance "<<endl;
			return single;
		}
	}
	void printInfo(){
		cout<<"SINGLETON CLASS "<<endl;
	}
};

unique_ptr<Singleton> Singleton::single = nullptr;

int main(){
	Singleton::getInstance()->printInfo();
	Singleton::getInstance()->printInfo();
}
