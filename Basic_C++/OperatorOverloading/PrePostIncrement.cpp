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

using namespace std;


class Sum{
	int n;
	int m;
public:
	Sum(int a, int b):n(a), m(b){}
	Sum operator ++(int);             //For the post increment overload, a dummy variable is used
	Sum& operator++();                //For pre increment overload
	friend ostream& operator << (ostream& out, const Sum& s);
};


Sum& Sum::operator ++(){
	n++;
	m++;
	return *this;
}

Sum Sum::operator ++(int){
	Sum temp(*this);  //Stores the state of the object before it is modified
	n++;
	m++;
	return temp;
}
ostream& operator <<(ostream& out, const Sum& s){
	out<<"The value of n is "<<s.n<<" and the value of m is "<<s.m<<endl;
	return out;
}

int main(){
	Sum s1(9, 10), s2(20, 30), s3(9, 10);
	cout<<s1++;
	cout<<s1;
	cout<<++s1;

}
