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

//The example below does not have a complete implementation of the business logic which otherwise would exist
//For example, it assumes that a mediator will always have other routers registered.


//For demonstrating the mediator pattern
//We can think of a group of routers that talk to a pseudo router which is supposed to be at the center of communications
//It is through this pseudorouter that the routes are exchanged
//The messages can be either be multicasted or unicasted based on different mediators

class Mediator;


class Router{
public:
	string routerName;
	std::unordered_map<string, shared_ptr<Mediator> > medList;
	Router(string _routerName):routerName(_routerName){}
	void mediatorRegister( shared_ptr <Mediator> med);
	void sendMessage(string vlanName, string message_to_send);
	void receiveMessage(string fromRouter, string recv_message);
};

class Mediator{
	vector<shared_ptr<Router> > routerList;
public:
	string name;
	Mediator(string _name):name(_name){}
	void registerRouter(shared_ptr<Router> router);
	void sendMessage(string fromRouter, string message);
};

void Mediator::registerRouter(shared_ptr<Router> router){
	routerList.push_back(router);
}

void Mediator::sendMessage(string fromRouter, string message){
	cout<<"Received message from Router "<<fromRouter<<endl;
	cout<<"The message is: "<<message<<endl;
	for(auto i:routerList){
		if(i->routerName != fromRouter){
			cout<<"Sending the message to Router "<<i->routerName<<" which is a part of "<<name<<endl;
			i->receiveMessage(name, message);
		}
	}
	cout<<"\n\n";
;}

void Router::mediatorRegister(shared_ptr<Mediator> med){
	medList[med->name]= med;
	med->registerRouter(shared_ptr<Router>(this, [](Router* r){;}));
}
void Router::sendMessage(string vlanName, string message){
	medList[vlanName]->sendMessage(routerName, message);
}
void Router::receiveMessage(string fromRouter, string recv_message){
	cout<<"Received the message "<<recv_message<<"from Router "<<fromRouter<<endl;
}

int main(){
	shared_ptr<Router> A = std::make_shared<Router>("A");
	shared_ptr<Router> B = std::make_shared<Router>("B");
	shared_ptr<Router> C = std::make_shared<Router>("C");
	shared_ptr<Mediator> VLAN1 = make_shared<Mediator>("VLAN1");
	shared_ptr<Mediator> VLAN2 = make_shared<Mediator>("VLAN2");
	shared_ptr<Mediator> VLAN3 = make_shared<Mediator>("VLAN3");

	//MAKE ROUTER A PART OF ALL THE VLANS
	A->mediatorRegister(VLAN1);
	A->mediatorRegister(VLAN2);
	A->mediatorRegister(VLAN3);

	//MAKE ROUTER B A PART OF VLAN1 AND VLAN 2
	B->mediatorRegister(VLAN1);
	B->mediatorRegister(VLAN2);

	//MAKE ROUTER C A PART OF VLAN2 AND VLAN 3
	C->mediatorRegister(VLAN2);
	C->mediatorRegister(VLAN3);

	A->sendMessage("VLAN1", "Received routes from the adjacent autonomous system");
	B->sendMessage("VLAN2", "Sending to all the routers");
}

