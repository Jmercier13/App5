/*
	beaj2031
	merj2607
	
	Class List used as a dynamic and generic 1D table (list)
*/
#pragma once

#include <cstddef>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <QDebug>

using namespace std;

template <class T>
class ListItem {
	public:
		ListItem<T> *_back;
		ListItem<T> *_front;
		
		T &_obj;

		ListItem();
		ListItem(ListItem<T> *back, ListItem<T> *front, T &obj);
		~ListItem();
		T& getObj();
};

template <class T>
class List {
	private:
	// public:
		ListItem<T> *_first;
		ListItem<T> *_last;
		
		int _len;
		
		ListItem<T>* _getItem(int index);
	
	public:
		List();
		~List();
		
		int length();
		
		ListItem<T>* begin();
		ListItem<T>* end();
		
		T& getObj(int index);
		
		void add(T &obj, int index=-1);
		void pushLast(T &obj);
		void pushFirst(T &obj);
		
		void empty();
		
		void remove(int index=-1);
		void removeLast();
		void removeFirst();

		List<T>& operator+=(T &elem);
		
		string toString();
};

template <class T>
ostream& operator<<(ostream &out, List<T> &l) {
	out << l.toString().c_str();
	return out;
}; 

template <class T>
QDebug& operator<<(QDebug &out, List<T> &l) {
	out << l.toString().c_str();
	return out;
};

template <class T>
List<T>& List<T>::operator+=(T &elem) {
	add(elem);
	return *this;
}

template <class T>
List<T>::List() {
	_first = NULL;
	_last = NULL;
	_len = 0;
}

template <class T>
List<T>::~List() {
	//TODO
}

template <class T>
int List<T>::length() {
	return _len;
}

template <class T>
ListItem<T>* List<T>::begin() {
	return _first;
}

template <class T>
ListItem<T>* List<T>::end() {
	return _last;
}

template <class T>
ListItem<T>* List<T>::_getItem(int index) {
	if (index < 0){
		index = _len + index;
	}

	if (index < 0 || index >= _len){
		//TODO TROW ERR
		cout << "ERROR _getItem index out of range" << endl;
	}

	ListItem<T> *l;

	if (index == 0){
		l = _first;
	}
	else if (index == _len - 1) {
		l = _last;
	}
	else {
		l = _first;
		for (int i = 0; i<index; i++){
			l = l->_front;
		}
	}

	return l;
}

template <class T>
T& List<T>::getObj(int index){
	return _getItem(index)->getObj();
}

template <class T>
void List<T>::add(T &obj, int index) {
	if (index < 0){
		index = (_len + 1) + index;
	}

	if (index == 0){
		//if its the first item
		pushFirst(obj);
	}
	else if (index == _len) {
		//if its the last item
		pushLast(obj);
	}
	else {
		//if its not first or last
		ListItem<T> *f = _getItem(index);
		ListItem<T> *b = f->_back;

		ListItem<T> *new_list = new ListItem<T>(b, f, obj);
		b->_front = new_list;
		f->_back = new_list;

		_len++;
	}
}

template <class T>
void List<T>::pushFirst(T &obj) {
	if (_first == NULL){
		//if there is no first
		_first = new ListItem<T>(NULL, NULL, obj);
		_last = _first;
	}
	else {
		//if there is a first
		ListItem<T> *new_list = new ListItem<T>(NULL, _first, obj);
		_first->_back = new_list;
		_first = new_list;

		// cout << "fi b f" << _first << " " << _first->_back << " " << _first->_front << endl;
		// cout << "la b f" << _last << " " << _last->_back << " " << _last->_front << endl;
	}

	_len++;
}

template <class T>
void List<T>::pushLast(T &obj) {
	if (_first == NULL){
		pushFirst(obj);
	}
	else {
		ListItem<T> *new_list = new ListItem<T>(_last, NULL, obj);
		_last->_front = new_list;
		_last = new_list;

		_len++;
	}
}

template <class T>
void List<T>::empty() {
	while (_len){
		remove(0);
	}
}

template <class T>
void List<T>::remove(int index) {
	if (index < 0){
		index = _len + index;
	}

	if (index < 0 || index >= _len){
		//TODO TROW ERR
		cout << "ERROR remove index out of range" << endl;
		return;
	}

	if (index == 0){
		removeFirst();
	}
	else if (index == _len - 1) {
		removeLast();
	}
	else {
		ListItem<T> *r = _getItem(index);
		ListItem<T> *b = r->_back;
		ListItem<T> *f = r->_front;

		b->_front = f;
		f->_back = b;

		delete r;
		_len--;
	}
}

template <class T>
void List<T>::removeLast() {
	if (_len == 0){
		return;
	}
	else if (_len == 1) {
		delete _first;

		_first = NULL;
		_last = NULL;
	}
	else {
		ListItem<T> *b = _last->_back;

		b->_front = NULL;
		delete _last;
		_last = b;
	}

	_len--;
}

template <class T>
void List<T>::removeFirst() {
	if (_len == 0){
		return;
	}
	else if (_len == 1) {
		delete _first;

		_first = NULL;
		_last = NULL;
	}
	else {
		ListItem<T> *f = _first->_front;

		f->_back = NULL;
		delete _first;
		_first = f;
	}

	_len--;
}

template <class T>
string List<T>::toString() {
	stringstream ss;

	for (int i = 0; i<_len; i++){
		T obj = getObj(i);
		ss << "| " << obj << " ";
	}

	ss << "|";

	return ss.str(); 
}

template <class T>
ListItem<T>::ListItem() {
	_back = NULL;
	_front = NULL;
	_obj = NULL;
}

template <class T>
ListItem<T>::ListItem(ListItem<T> *back, ListItem<T> *front, T &obj) : _obj(obj) {
	_back = back;
	_front = front;
}

template <class T>
ListItem<T>::~ListItem() {
	//maybe some memory leak

	_back = NULL;
	_front = NULL;
	_obj = NULL;
	// delete _obj;
}

template <class T>
T& ListItem<T>::getObj() {
	return _obj; 
}