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

//Adapter pattern is used to make 2 classes which otherwise are incompatible to work
//The class Addition mentioned below is being adapted to Subtraction
//As can be seen from the code, the interfaces are very different
//Hence can also be used for making Legacy and New code work

class Addition{
	int number1;
	int number2;
public:
	Addition(int a, int b):number1(a), number2(b){}
	virtual int carryOperation(){
		return number1+number2;
	}
	virtual ~Addition(){}
};

class Subtraction{
	int a;
	int b;
public:
	Subtraction(int number1, int number2):a(number1), b(number2){}
	int subtract(){
		return a-b;
	}
};


//As per GOF book, the target would be inherited privately
//And the class whose interface is expected by the client will be inherited publicly
class Adapter: public Addition, private Subtraction{
public:
	Adapter(int number1, int number2):Addition(number1, number2), Subtraction(number1, number2){}
	int carryOperation(){
		return Subtraction::subtract();
	}
};

int main(){
	Addition* add = new Adapter(66 , 34);
	//Using the interface as expected by the client(main function) but still getting the results based on Subtraction
	cout << add->carryOperation();
}


