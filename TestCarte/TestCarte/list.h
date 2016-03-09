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

using namespace std;

class ListItem {
	friend class List;
	private:
	// public:
		ListItem *_back;
		ListItem *_front;
		
		void *_obj;
	public:
		ListItem();
		ListItem(ListItem *back, ListItem *front, void *obj);
		~ListItem();
		void* getObj();
};

template <class T>
class List {
	private:
	// public:
		ListItem *_first;
		ListItem *_last;
		
		int _len;
		
		ListItem* _getItem(int index);
	
	public:
		List();
		~List();
		
		int length();
		
		ListItem* begin();
		ListItem* end();
		
		T* getObj(int index);
		
		void add(T *obj, int index=-1);
		void pushLast(void *obj);
		void pushFirst(void *obj);
		
		void empty();
		
		void remove(int index=-1);
		void removeLast();
		void removeFirst();
		
		string toString();
};

template <class T>
List<T>::List(){
	_first = NULL;
	_last = NULL;
	_len = 0;
}

template <class T>
List<T>::~List(){
	//TODO
}

template <class T>
int List<T>::length(){
	return _len;
}

template <class T>
ListItem* List<T>::begin(){
	return _first;
}

template <class T>
ListItem* List<T>::end(){
	return _last;
}

template <class T>
ListItem* List<T>::_getItem(int index){
	if (index < 0){
		index = _len + index;
	}

	if (index < 0 || index >= _len){
		//TODO TROW ERR
		cout << "ERROR _getItem index out of range" << endl;
	}

	ListItem *l;

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
T* List<T>::getObj(int index){
	return (T *)_getItem(index)->getObj();
}

template <class T>
void List<T>::add(void *obj, int index){
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
		ListItem *f = _getItem(index);
		ListItem *b = f->_back;

		ListItem *newL = new ListItem(b, f, obj);
		b->_front = newL;
		f->_back = newL;

		_len++;
	}
}

template <class T>
void List<T>::pushFirst(void *obj){
	if (_first == NULL){
		//if there is no first
		_first = new ListItem(NULL, NULL, obj);
		_last = _first;
	}
	else {
		//if there is a first
		ListItem *newL = new ListItem(NULL, _first, obj);
		_first->_back = newL;
		_first = newL;

		// cout << "fi b f" << _first << " " << _first->_back << " " << _first->_front << endl;
		// cout << "la b f" << _last << " " << _last->_back << " " << _last->_front << endl;
	}

	_len++;
}

template <class T>
void List<T>::pushLast(void *obj){
	if (_first == NULL){
		pushFirst(obj);
	}
	else {
		ListItem *newL = new ListItem(_last, NULL, obj);
		_last->_front = newL;
		_last = newL;

		_len++;
	}
}

template <class T>
void List<T>::empty(){
	while (_len){
		remove(0);
	}
}

template <class T>
void List<T>::remove(int index){
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
		ListItem *r = _getItem(index);
		ListItem *b = r->_back;
		ListItem *f = r->_front;

		b->_front = f;
		f->_back = b;

		delete r;
		_len--;
	}
}

template <class T>
void List<T>::removeLast(){
	if (_len == 0){
		return;
	}
	else if (_len == 1) {
		delete _first;

		_first = NULL;
		_last = NULL;
	}
	else {
		ListItem *b = _last->_back;

		b->_front = NULL;
		delete _last;
		_last = b;
	}

	_len--;
}

template <class T>
void List<T>::removeFirst(){
	if (_len == 0){
		return;
	}
	else if (_len == 1) {
		delete _first;

		_first = NULL;
		_last = NULL;
	}
	else {
		ListItem *f = _first->_front;

		f->_back = NULL;
		delete _first;
		_first = f;
	}

	_len--;
}

template <class T>
string List<T>::toString(){
	int TAB_LEN = 3;
	stringstream ss;

	stringstream row_1;
	stringstream row_2;

	for (int i = 0; i<_len; i++){
		PlatChoisi *p = getObj(i);
		row_1 << '|' << setw(TAB_LEN) << i;
		row_2 << '|' << setw(TAB_LEN) << p->getnb();
	}

	ss << row_1.str() << '|' << endl;
	ss << sep('-', ((TAB_LEN + 1) * _len) + 1) << endl;
	ss << row_2.str() << '|';

	return ss.str();
}


ListItem::ListItem(){
	_back = NULL;
	_front = NULL;
	_obj = NULL;
}

ListItem::ListItem(ListItem *back, ListItem *front, void *obj){
	_back = back;
	_front = front;
	_obj = obj;
}

ListItem::~ListItem(){
	//maybe some memory leak

	_back = NULL;
	_front = NULL;
	_obj = NULL;
	// delete _obj;
}

void* ListItem::getObj(){
	return _obj;
}