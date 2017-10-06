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
	void operator -();
	friend ostream& operator << (ostream& out, const Sum& s);
};

void Sum::operator -(){
	n = -n;
	m = -m;
}

ostream& operator <<(ostream& out, const Sum& s){
	out<<"The value of n is "<<s.n<<" and the value of m is "<<s.m<<endl;
	return out;
}





int main(){
	Sum s(24,-54);
	cout<<s;
	-s;
	cout<<s;
}
