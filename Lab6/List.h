#pragma once
#include <iostream>
using namespace std;
struct Node {
	int key;
	string value;
	Node* next;
	Node(int _key, string _value) : key(_key), value(_value), next(nullptr) {}
};
int getLength(Node* head);
struct List {
	Node* head;
	List() : head(nullptr) {}
	~List();
	void pushBack(int key, string value);
	void pushUp(int key, string value);
	int deleteByKey(int key);
	void clearList();
	void print();
};