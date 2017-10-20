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

using namespace std;


class InListexample{
	vector<int> vec;
public:
	InListexample(const initializer_list<int> &v):vec(v.begin(), v.end()){}
	friend ostream& operator <<(ostream& o, InListexample& inList);
};

ostream& operator <<(ostream& o, InListexample& inList){
	for(auto i:inList.vec){
		o << i << " ";
	}
	return o;
}

int main(){
	InListexample inlist = {61, 2, 3, 4, 5};
	cout<<inlist;
}
