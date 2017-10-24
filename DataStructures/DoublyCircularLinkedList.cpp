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


class Node{
public:
	int data;
	Node* next;
	Node* prev;
	Node(int value=0,Node* n=nullptr,Node* p=nullptr):data(value), next(n), prev(p){}
};


class CircularDoubleLinked{
	Node* head;
	int size;
public:
	CircularDoubleLinked(Node* h=nullptr, int s=0):head(h), size(s){}
	bool isEmpty();
	void push(int value);
	int delete_last();
	friend ostream& operator <<(ostream& o, CircularDoubleLinked& c);
};

ostream& operator <<(ostream& o, CircularDoubleLinked& c){
	if(!c.isEmpty()){
		Node* trackerNode = c.head;
		do{
			o << trackerNode->data<< " ";
			trackerNode = trackerNode->next;
		}while(trackerNode != c.head);
	}
	else{
		cout<<"Cannot print out an empty list" <<endl;
	}

	return o;
}

bool CircularDoubleLinked::isEmpty(){
	if(head == nullptr){
		return true;
	}
	return false;
}

void CircularDoubleLinked::push(int value){
	if(head == nullptr){
		head = new Node(value);
		head->next = head;
		head->prev = head;
		size++;
		return;
	}
	Node* newNode = new Node(value);
	newNode->prev = head->prev;
	newNode->next = head;
	head->prev->next = newNode;
	head->prev = newNode;
	head = newNode;
	size++;
}

int CircularDoubleLinked::delete_last(){
	int tmp;
	if(head == nullptr){
		return 0;
	}
	if(head == head->next){
		tmp = head->data;
		delete head;
		head = nullptr;
		return tmp;

	}
	Node* toDelete = head->prev;
	toDelete->prev->next = head;
	head->prev = toDelete->prev;
	tmp = toDelete->data;
	delete toDelete;
	return tmp;
}

int main(){
	CircularDoubleLinked cl;
	cl.push(32);
	cl.push(45);
	cl.push(21);
	//cl.push(15);
	cout << cl<<endl;
	//cout << cl<<endl;

}
