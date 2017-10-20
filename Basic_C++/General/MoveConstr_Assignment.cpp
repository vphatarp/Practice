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

class Constructors{
	int size;
	int* arr;
public:
	Constructors(std::initializer_list<int> ilist);
	Constructors(int s=10);
	Constructors(const Constructors& c);
	Constructors(Constructors&& c);
	Constructors& operator=(const Constructors& c);
	Constructors& operator=(Constructors&& c);
	void assign();
	void printInfo();
};

Constructors::Constructors(int s):size(s), arr(new int[size]){
	cout<<"INITIALIZING VIA DEFAULT CONSTRUCTOR "<<endl;
}

Constructors::Constructors(std::initializer_list<int> ilist){
	cout<<"INITIALIZING VIA INITIALIZER LIST "<<endl;
	size = ilist.size();
	arr = new int[size];
	int elementcount =0;
	for(std::initializer_list<int>::iterator it = ilist.begin(); it != ilist.end(); it++){
		arr[elementcount] = *it;
		elementcount++;
	}
}

Constructors::Constructors(Constructors&& c){
	cout<<"INITIALIZING VIA MOVE CONSTRUCTOR "<<endl;
	size = c.size;
	arr = c.arr;
	c.arr = nullptr;
}


Constructors::Constructors(const Constructors& c){
	cout<<"INITIALIZING VIA COPY CONSTRUCTOR "<<endl;
	size = c.size;
	arr = new int[size];
	for(int i=0;i<size;i++){
		arr[i] = c.arr[i];
	}
}

Constructors& Constructors::operator=(const Constructors& c){
	cout<<"USING THE COPY ASSIGNMENT OPERATOR "<<endl;
	if(this == &c){
		cout<<"Cannot assign an object to itself "<<endl;
		return *this;
	}
	delete arr;
	size = c.size;
	arr = new int[size];
	for(int i=0;i<size;i++){
		arr[i] = c.arr[i];
	}
	return *this;
}

Constructors& Constructors::operator=(Constructors&& c){
	cout<<"USING THE MOVE ASSIGNMENT OPERATOR "<<endl;
	if(this == &c){
		cout<<"Cannot assign an object to itself "<<endl;
		return *this;
	}
	delete arr;
	size = c.size;
	arr = new int[size];
	arr = c.arr;
	c.arr = nullptr;
	return *this;
}

void Constructors::assign(){
	if (size > 0){
		for(int i=0;i<size;i++){
			arr[i] = i+21;
		}
	}
}

void Constructors::printInfo(){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

Constructors create(){
	Constructors d = {12, 13, 99, 56, 31, 21};
	return d;
}

int main(){
	Constructors c = {23, 45, 54, 32, 1};
	c.printInfo();
	cout<<"\n\n";
	Constructors c_copy(c);
	c_copy.printInfo();
	cout<<"\n\n";
	Constructors c_def;
	cout<<"Before Move Assigning"<<endl;
	c_def.printInfo();
	c_def = create();
	cout<<"After Move Assigning"<<endl;
	c_def.printInfo();
	cout<<"\n\n";
	Constructors c_cassignment;
	cout<<"Before Copy Assignment"<<endl;
	c_cassignment = c;
	cout<<"After Copy Assigning"<<endl;
	c_cassignment.printInfo();

}
