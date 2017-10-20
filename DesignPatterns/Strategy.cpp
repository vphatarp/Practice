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

class Sorting{
public:
	virtual void sort(std::vector<int>& arr)=0;
	virtual ~Sorting(){}
};

class Ascending:public Sorting{
public:
	virtual void sort(std::vector<int>& arr);
};
void Ascending::sort(std::vector<int>& arr){
	std::sort(arr.begin(), arr.end(), std::greater<int>());
}

class Descending:public Sorting{
public:
	virtual void sort(std::vector<int>& arr);
};
void Descending::sort(std::vector<int>& arr){
	std::sort(arr.begin(), arr.end(), std::less<int>());
}

class Constructors{
	int size;
	std::vector<int> arr;
	Sorting* sortMethod;

public:
	Constructors(std::initializer_list<int> ilist);
	void printInfo();
	void setSort(Sorting* s);
	void arraySort();
};

Constructors::Constructors(std::initializer_list<int> ilist):size(ilist.size()),arr(ilist.begin(), ilist.end()){}

void Constructors::setSort(Sorting* s){
	sortMethod = s;
}

void Constructors::arraySort(){
	sortMethod->sort(arr);
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
	Ascending a;
	Descending d;
	c.setSort(&d);
	c.arraySort();
	c.printInfo();
}
