#pragma once
#include "LinkedList.h"
#include <string>

class LinkedQueue
{
private:
	LinkedList callList;

public:
	LinkedQueue() {};
	void enqueue(int ID, int callT) { callList.insertBack(ID, callT); }
	void dequeue() { callList.removeFront(); }
	bool empty() const { return callList.empty(); }
	int frontCallTime() const { return callList.get_callTime(0); }
	int frontID() const { return callList.get_ID(0); }
	int size() const { return callList.size(); } 
};
