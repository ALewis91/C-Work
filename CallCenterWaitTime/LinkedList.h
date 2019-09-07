#pragma once
class LinkedList
{
private:
	struct Node
	{
		int callTime;
		int customerID;
		Node* next;
		Node* prev;
	};

	Node* header;
	Node* trailer;
	int n;

public:
	LinkedList();
	LinkedList(const LinkedList& LL);
	LinkedList& operator=(const LinkedList& LL);
	~LinkedList();
	int size() const;
	bool empty() const;
	void insertFront(const int ID, const int callT);
	void insertBack(const int ID, const int callT);
	void removeFront();
	void removeBack();
	void insert(int i, const int ID, const int callT);
	void remove(int i);
	int get_callTime(int index) const;
	int get_ID (int index) const;
};
