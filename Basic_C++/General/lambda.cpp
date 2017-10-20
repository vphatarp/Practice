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

void filler(bool f(int i), vector<int>& v){
	for(auto i:v){
		if(f(i)){
			cout<<i<<" ";
		}
	}
}

int main(){
	vector<int> vec= {34, 21, 22, 24, 44, 61, 73};
	filler([](int x){return (x%2 == 0);}, vec);
}
