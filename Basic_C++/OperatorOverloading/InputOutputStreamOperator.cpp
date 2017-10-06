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
	friend ostream& operator << (ostream& out, const Sum& s); //Overloading output operator
	friend istream& operator >> (istream& in, Sum& s);        //Overoading input operator
};

ostream& operator <<(ostream& out,const Sum& s){
	out<<"The value of n is "<< s.n <<" and the value of m is "<< s.m;
	out<<endl;
	return out;
}

istream& operator >>(istream& in, Sum& s2){
	in>> s2.n >> s2.m;
	return in;
}


int main(){
	Sum s(0,0);
	cout<<s;
	cin>>s;
	cout<<s;
}
