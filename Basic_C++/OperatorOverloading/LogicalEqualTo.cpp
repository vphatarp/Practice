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
	bool operator ==(Sum& s);
	friend ostream& operator << (ostream& out, const Sum& s);
};

bool Sum::operator ==(Sum& s){
	return ((n == s.n)&&(m == s.m));
}

ostream& operator <<(ostream& out, const Sum& s){
	out<<"The value of n is "<<s.n<<" and the value of m is "<<s.m<<endl;
	return out;
}





int main(){
	Sum s1(9, 10), s2(20, 30), s3(9, 10);
	if(s1 == s2){
		cout<<"S1 and S2 hold similar values for the integers "<<endl;
	}
	else{
		cout<<"S1 and S2 are not similar "<<endl;
	}
	if(s1 == s3){
		cout<<"S1 and S3 hold similar values for the integers "<<endl;
	}
	else{
		cout<<"S1 and S3 are not similar "<<endl;
	}
}
