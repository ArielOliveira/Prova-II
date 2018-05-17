#ifndef ARIELSLIB_LIST_H
#define ARIELSLIB_LIST_H

#include <iostream>
using std::cout;
using std::endl;

#include "Midia.h"
#include "CD.h"
#include "DVD.h"
#include "Livro.h"

template<typename T>
	class Node {
		public:
			Node(T data): data(data) {}
			Node() {}
			~Node() {}
			T data;
			Node *next;
			Node *previous;
};

template <typename T>
class List {
	private:
		int size;

		void connect(Node<T> *inserted, Node<T> *sentry);
		void findNode(int index, Node<T> *&sentry);

		Node<T> *head;
		Node<T> *tail;
	public:
		List();
		~List();

		void insertOrdered(T data);

		void insertAtHead(T data);
		void insertAtTail(T data);
		bool insertAt(int index, T data);

		bool removeAtHead();
		bool removeAtTail();
		bool removeAt(int index);

		int getSize();

		T getData(int index);

		void deleteList();
		void printList();
};

template <typename T>
List<T>::List() {
	size = 0;
	head = new Node<T>();
	tail = new Node<T>();

	head->next = tail;
	tail->previous = head;
}
	
template <typename T>		
List<T>::~List() {
	deleteList();
}

template <typename T>
void List<T>::insertOrdered(T data) {
	Node<T> *inserted = new Node<T>(data);

	Node<T> *j, *temp;
	Node<T> *runner = head;

	int i = 1;

	while(((runner = runner->next) && (runner != tail)) && runner->data > runner->next->data) {
		j = runner;
		if ((j->data > head->next->data) && (j->data < j->previous->data)) {
			temp = j;
			j = j->previous;
		}
		i++;
	}

}
	
template <typename T>
void List<T>::insertAtHead(T data) {
	Node<T> *inserted = new Node<T>(data);
	inserted->next = NULL;
	inserted->previous = NULL;
	Node<T> *h = this->head;

	h->next->previous = inserted;
	inserted->next = h->next;

	h->next = inserted;
	inserted->previous = h;

	this->size++;
}

template <typename T>
void List<T>::insertAtTail(T data) {
	Node<T> *inserted = new Node<T>(data);
	inserted->next = NULL;
	inserted->previous = NULL;
	Node<T> *t = this->tail;

	t->previous->next = inserted;
	inserted->previous = t->previous;

	t->previous = inserted;
	inserted->next = t;

	this->size++;
}

template <typename T>
bool List<T>::insertAt(int index, T data) {
	if (index > size || index < 0) return false;

	Node<T> *inserted = new Node<T>(data);
	inserted->next = NULL;
	inserted->previous = NULL;
	Node<T> *sentry;

	findNode(index, sentry);
	connect(inserted, sentry);
	size++;

	return true;
}
	
template <typename T>
bool List<T>::removeAtHead() {
	if (head->next == tail) return false;

	Node<T> *tmp = head->next;
	head->next = tmp->next;
	tmp->next->previous = head;
	delete tmp;

	return true;
}
	
template <typename T>
bool List<T>::removeAtTail() {
	if (tail->previous == head) return false;

	Node<T> *tmp = tail->previous;
	tail->previous = tmp->previous;
	tmp->previous->next = tail;
	delete tmp;

	return true;
}

template <typename T>
bool List<T>::removeAt(int index) {
	if (index > size || index < 0) return false;

	Node<T> *sentry;

	findNode(index, sentry);
	Node<T> *tmp = sentry->next;
	tmp->previous = sentry->previous;
	tmp->previous->next = tmp;
	delete sentry;

	return true;
}

template <typename T>
int List<T>::getSize() {return size;}

template <typename T>
T List<T>::getData(int index) {
	Node<T> *sentry;
	if (index <= size && index > 0) {
		findNode(index, sentry);
	} else {
		std::cout << "Impossível encontrar elemento. Posição fora da lista" << std::endl;
	}
		return sentry->data;
}

template <typename T>
void List<T>::printList() {
	Node<T> *runner = head;
	while((runner = runner->next) && (runner != tail)) {
		switch(runner->data->getRamo()) {
			case LIVRO: std::cout << (Livro*)runner->data << std::endl;
				break;
			case CD: std::cout << (Cd*)runner->data << std::endl;
				break;
			case DVD: std::cout << (Dvd*)runner->data << std::endl;
				break;
		}
	}
}
	
template <typename T>
void List<T>::deleteList() {
	Node<T> *sentry = head->next;
	while (sentry->next) {
		sentry = sentry->next;
		delete sentry->previous;
	}
	delete head;
	delete tail;
}
	
template <typename T>
void List<T>::connect(Node<T> *inserted, Node<T> *sentry) {
	inserted->previous = sentry->previous;
	sentry->previous->next = inserted;
	inserted->next = sentry;
	sentry->previous = inserted;
}

template <typename T>
void List<T>::findNode(int index, Node<T> *&sentry) {
	if (index > size/2) {
		sentry = tail->previous;
		for (int count = size; count > index; count--) {
		sentry = sentry->previous;
		}
	}
}

#endif
