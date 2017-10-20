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

//The code below has been tested for memory leaks using Valgrind
//No memory leaks for the addition, deletion scenarios were found
class SingleLinkedList;

//Each Node contains data and a pointer to the next node in the Linked List
class Node{
public:
	int data;
	shared_ptr<Node> next;
	Node(int info, shared_ptr<Node> n=nullptr, int s=0):data(info),next(n){}
	friend ostream& operator << (ostream& o, SingleLinkedList& s);
};

//Below is the actual implementation of Linked List
class SingleLinkedList{
	int size;
	shared_ptr<Node> head;
	shared_ptr<Node> tail;
public:
	SingleLinkedList(shared_ptr<Node> h=nullptr, shared_ptr<Node> t=nullptr, int s=0):head(h),tail(t), size(s){}
	bool isEmpty();
	void push_front(int info);
	void push_back(int info);
	void delete_front();
	void delete_back();
	void delete_node(int value);
	void reverseList();
	friend ostream& operator << (ostream& o, SingleLinkedList& s);
};

ostream& operator << (ostream& o, SingleLinkedList& s){
	shared_ptr<Node> tmp  = s.head;
	while(tmp != nullptr){
		o << tmp->data<<" ";
		tmp = tmp->next;
	}
	return o;
}

bool SingleLinkedList::isEmpty(){
	if(head == nullptr){
		return true;
	}
	return false;
}

void SingleLinkedList::push_front(int info){
	shared_ptr<Node> newNode(new Node(info, head));
	if(head == nullptr){
		tail = newNode;
	}
	head = newNode;
	size++;
}

void SingleLinkedList::push_back(int info){
	shared_ptr<Node> newNode(new Node(info));
	if(head == nullptr){
		head = newNode;
		tail = newNode;
		size++;
		return;
	}
	tail->next = newNode;
	tail = newNode;
	size++;
}

void SingleLinkedList::delete_front(){
	if(head != nullptr){
		if(head == tail){
			head.reset();
			tail.reset();
		}
		else{
			shared_ptr<Node> currentHead = head;
			head = head->next;
			currentHead.reset();
		}
		size--;
	}
}

void SingleLinkedList::delete_back(){
	if(head != nullptr){
		if(head == tail){
			head.reset();
			tail.reset();
		}
		else{
			shared_ptr<Node> newTail = head;
			while(newTail->next != tail){
				newTail = newTail->next;
			}
			tail = newTail;
			newTail->next.reset();
		}
		size--;
	}
}

void SingleLinkedList::delete_node(int value){
	if(head == 0){
		return;
	}
	else if(head == tail){
		if(head->data == value){
			size=0;
			delete_front();
		}
	}
	else{
		shared_ptr<Node> node1 = head;
		shared_ptr<Node> node2 = head->next;
		while(node2 != nullptr){
			if(node2->data == value){
				break;
			}
			node1 = node2;
			node2 = node2->next;
		}
		if(node1 == tail){
			delete_back();
		}
		else{
			node1->next = node2->next;
			node2.reset();
		}
		size--;
	}
}

void SingleLinkedList::reverseList(){
	 shared_ptr<Node> index1,index2, index3;
	 if(size == 2){
		 index1 = head;
	     index2 = head->next;
	     head = index2;
	     head->next = index1;
	     index1->next.reset();
	  }
	  else if(size >= 3){
	      index1 = head;
	      index2 = head->next;
	      index3 = head->next->next;
	      index1->next.reset();
	      while(index3 != nullptr){
	          index2->next = index1;
	          if(index3->next){
	              index1 = index2;
	              index2 = index3;
	              index3 = index3->next;
	          }
	          else{
	              index3->next = index2;
	              head = index3;
	              break;
	          }
	      }
	  }
}

int main(){
	SingleLinkedList sng;
	sng.push_front(23);
	sng.push_front(13);
	sng.push_front(15);
	sng.push_back(56);
	sng.push_back(96);
	sng.push_back(66);
	sng.delete_node(13);
	cout<<sng;
	sng.reverseList();
	cout<<sng;
}
