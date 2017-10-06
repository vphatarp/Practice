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
	Sum operator +(const Sum s);                       //Overload using a member function
	//friend Sum operator +(const Sum s1, const Sum s2); Overload using a friend function
	void operator =(const Sum s);                      //Overloading assignment operator
	void print(); //For checking the final values
};

Sum Sum::operator +(const Sum s){
	return Sum(n+s.n, m+s.m);
}

/*
 * The section of the code below is the implementation of
 * overloading using a friend function
 */
//Sum operator +(const Sum s1, const Sum s2){
//	return Sum(s1.n+s2.n, s1.m+s2.m);
//}

void Sum::operator =(const Sum s){
	n = s.n;
	m = s.m;
}

void Sum::print(){
	cout<<"Value of n is "<<n<<" and the value of m is "<<m<<endl;
}

int main(){
	Sum s1(90, 67), s2(81, 83), s3(0,0);
	s3 = s1 + s2;
	s3.print();
}
