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
#include <initializer_list>
#include <memory>


/*
 * The code below is not exception free but has been written with raw pointers to practice memory management
 * Below is a snippet of the valgrind output for the addition of 50 nodes
 *
 *--5481-- REDIR: 0x57b2790 (libc.so.6:__memcmp_sse4_1) redirected to 0x4c2d610 (__memcmp_sse4_1)
--5481-- REDIR: 0x56dab10 (libc.so.6:strlen) redirected to 0x4a227b0 (_vgnU_ifunc_wrapper)
--5481-- REDIR: 0x57b7e60 (libc.so.6:__strlen_sse2_pminub) redirected to 0x4c2a9d0 (strlen)
--5481-- REDIR: 0x56dd870 (libc.so.6:__GI_mempcpy) redirected to 0x4c2e950 (__GI_mempcpy)
32 45 --5481-- REDIR: 0x56d4370 (libc.so.6:free) redirected to 0x4c28c56 (free)
==5481==
==5481== HEAP SUMMARY:
==5481==     in use at exit: 0 bytes in 0 blocks
==5481==   total heap usage: 16 allocs, 16 frees, 392 bytes allocated
==5481==
==5481== All heap blocks were freed -- no leaks are possible
==5481==
==5481== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
==5481== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 *

 *
 */

using namespace std;

class Node{
public:
	int value;
	int power;
	Node** next;
	Node(int a, int p):value(a), power(p), next(new Node*[power+1]()){}
	~Node(){
		delete [] next;
	}
};

class SkipList{
	int level;
	int head_level;
	Node** head;
public:
	SkipList(int l=4, int h=0):level(l), head_level(h), head(new Node* [level]()){};
	bool isEmpty();
	void push_element(int data);
	void delete_element(int data);
	int chooseLevel();
	void printList();
	~SkipList(){
			Node* trackerNode = head[0];
					while(trackerNode != nullptr){
						head[0] = trackerNode->next[0];
						delete trackerNode;
						trackerNode = head[0];
					}
					delete [] head;
	}
};

void SkipList::printList(){
	Node* trackerNode = head[0];
	if(trackerNode == nullptr){
		cout<<"Cannot delete Nodes from an empty list "<<endl;
	}
	while(trackerNode != nullptr){
		cout<< trackerNode->value<<" ";
		trackerNode = trackerNode->next[0];
	}
}

int SkipList::chooseLevel(){
	return rand() % level;
}


bool SkipList::isEmpty(){
	if(head[0] == nullptr){
		return true;
	}
	return false;
}

void SkipList::push_element(int data){
	//Pick a random number to set the existence of the Node at different levels
	int l = chooseLevel();

	//If the list is currently empty
	if(head[0] == nullptr){
		Node* newNode = new Node(data, l);
		for(int i=0;i<=l;i++){
			head[i] = newNode;
		}
		head_level = l;
		return;
	}

	//Since the end nodes at each level might be different
	//Using prevNode array to keep track of the last element at each node
	Node** prevNode = new Node* [level]();
	for(int i=0;i<level;i++){
		prevNode[i] = head[i];
	}
	Node* newNode = new Node(data, l);
	Node* trackerNode = head[head_level];   //Head Level keeps track of the max number of pointers that some node in the list currently holds
	int curr_level = head_level;

	//For every search it would be necessary to reach all the way to the 0th level
	//But since we start from the max level first, we reach the point faster
	while(trackerNode != nullptr){
		if(trackerNode->value <= data){
			prevNode[curr_level] = trackerNode;  //Keeps track of the last node on a particular level
			if(! trackerNode->next[curr_level]){
				if(curr_level > 0){
					curr_level--;
				}
				else{
					break;
				}
			}
			else{
				trackerNode = trackerNode->next[curr_level];
			}
		}
		else{
			if(curr_level == 0){
				if(trackerNode == head[0]){
					for(int i=l;i>=0;i--){
						newNode->next[i] = head[i];
						head[i] = newNode;
					}
					delete [] prevNode;
					return;
				}
				break;
			}
			curr_level--;
			trackerNode = prevNode[curr_level];
		}

	}

	//If the number of levels of the new Node is greater than the previous max number of pointers
	//The head pointers need to be modified to point to the new Node
	if(l <= head_level){
		for(int i=0;i<=l;i++){
			newNode->next[i] = prevNode[i]->next[i];
			prevNode[i]->next[i] = newNode;
		}
	}
	else{
		for(int i=head_level+1;i<=l;i++){
				head[i] = newNode;
			}
			for(int i=head_level;i>=0;i--){
				newNode->next[i] = prevNode[i]->next[i];
				prevNode[i]->next[i] = newNode;
			}
		head_level = l;
	}

	//Since prevNode was dynamically created in the program, it needs to be deleted
	delete [] prevNode;
}

void SkipList::delete_element(int data){
	if(head[0] == nullptr){
		cout<<"Cannot delete an empty list "<<endl;
		return;
	}
	if(head[0]->value == data){
		Node* toDeleteNode = head[0];
		for(int i=0;i<=toDeleteNode->power;i++){
			head[i] = head[i]->next[i];
			if(head[i] != nullptr){
				head_level = i;
			}
		}
		delete toDeleteNode;
		return;
	}
	Node** prevNode = new Node*[level]();
	Node* trackerNode = head[head_level];
	int curr_level = head_level;
	for(int i=0;i<level;i++){
		prevNode[i]  = head[i];
	}
	while(1){
		if(trackerNode->value == data){
			if(curr_level == 0){
				break;
			}
			else{
				trackerNode = prevNode[curr_level]->next[curr_level - 1];
				prevNode[curr_level - 1] = prevNode[curr_level];
				curr_level--;
			}
		}
		else if(trackerNode->value > data){
			if(curr_level == 0){
				delete [] prevNode;
				return;
			}
			curr_level--;
			trackerNode = prevNode[curr_level];
		}
		else if(trackerNode->value < data){
			prevNode[curr_level] = trackerNode;
			trackerNode = trackerNode->next[curr_level];
			if((trackerNode == nullptr) && (curr_level == 0)){
				delete [] prevNode;
				return;
			}
			else{
				while(trackerNode == nullptr){
					trackerNode = prevNode[curr_level]->next[curr_level - 1];
					curr_level--;
					if(curr_level == 0){
						delete [] prevNode;
						return;
					}
				}
			}
		}

	}
	if(trackerNode == head[0]){
		for(int i=0;i<=trackerNode->power;i++){
			head[i] = trackerNode->next[i];
		}
		delete trackerNode;
	}
	else{
		for(int i=0;i<=trackerNode->power;i++){
			prevNode[i]->next[i] = trackerNode->next[i];
		}
	}
	for(int i=0;i<level;i++){
		if (head[i] != nullptr){
			head_level = i;
		}
	}
	delete trackerNode;
	delete [] prevNode;
}




int main(){
	SkipList s(4);
	s.push_element(45);
	s.push_element(32);
	s.push_element(27);
	s.push_element(21);
	s.delete_element(21);
	s.delete_element(27);
	s.push_element(99);
	s.delete_element(99);
	s.printList();
}


