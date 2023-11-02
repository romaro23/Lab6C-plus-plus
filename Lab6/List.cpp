#include <string>
#include <iostream>
#include "List.h"
using namespace std;


int getLength(Node* head) {
	int length = 0;
	Node* p = head;
	while (p) {
		length++;
		p = p->next;
	}
	return length;
}
Node* head;
List::~List() {
	clearList();
}
void List::pushBack(int key, string value) {
	Node* node = new Node(key, value);
	if (head == nullptr) {
		head = node;
	}
	else {
		Node* current = head;
		while (current->next) {
			current = current->next;
		}
		current->next = node;
	}

}
void List::pushUp(int key, string value) {
	Node* node = new Node(key, value);
	if (head == nullptr) {
		head = node;
	}
	else {
		node->next = head;
		head = node;
	}
}
int List::deleteByKey(int key) {
	Node* current = head;
	Node* prev = nullptr;
	if (head->key == key) {
		if (head->next == nullptr) {
			head = nullptr;
			return 1;
		}
		else {
			Node* temp = head->next;
			delete head;
			head = temp;
		}	
	}
	else {
		while (current->next) {	
			prev = current;
			current = current->next;
			if (current->key == key) {
				prev->next = current->next;
				delete current;
				break;
			}			
			
		}
		return 0;
	}
}
void List::clearList() {
	while (head) {
		Node* node = head;
		head = head->next;
		delete node;

	}
}
void List::print() {
	Node* node = head;
	while (node) {
		cout << node->value << " ";
		node = node->next;
	}
	cout << endl;
}



