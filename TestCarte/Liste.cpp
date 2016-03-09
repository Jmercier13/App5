#include "../headers/liste.h"

Liste::Liste(){
	_first = NULL;
	_last = NULL;
	_len = 0;
}

Liste::~Liste(){
	//TODO
}

int Liste::length(){
	return _len;
}

ListeItem* Liste::begin(){
	return _first;
}

ListeItem* Liste::end(){
	return _last;
}

ListeItem* Liste::_getItem(int index){
	if(index < 0){
		index = _len  + index;
	}
	
	if(index < 0 || index >= _len){
		//TODO TROW ERR
		cout << "ERROR _getItem index out of range" << endl;
	}
	
	ListeItem *l;
	
	if(index == 0){
		l = _first;
	} else if(index == _len-1) {
		l = _last;
	} else {
		l = _first;
		for(int i=0; i<index; i++){
			l = l->_front;
		}
	}
	
	return l;
}

PlatChoisi* Liste::getObj(int index){	
	return (PlatChoisi *) _getItem(index)->getObj();
}

void Liste::add(void *obj, int index){
	if(index < 0){
		index = (_len + 1) + index;
	}
	
	if(index < 0 || index > _len){
		//TODO TROW ERR
		cout << "ERROR _getItem index out of range" << endl;
		return;
	}
	
	if(index == 0){
		//if its the first item
		pushFirst(obj);
	} else if(index == _len) {
		//if its the last item
		pushLast(obj);		
	} else {
		//if its not first or last
		ListeItem *f = _getItem(index);
		ListeItem *b = f->_back;
		
		ListeItem *newL = new ListeItem(b, f, obj);
		b->_front = newL;
		f->_back = newL;
		
		_len++;
	}
}


void Liste::pushFirst(void *obj){	
	if(_first == NULL){
		//if there is no first
		_first = new ListeItem(NULL, NULL, obj);
		_last = _first;
	} else {
		//if there is a first
		ListeItem *newL = new ListeItem(NULL, _first, obj);
		_first->_back = newL;
		_first = newL;
		
		// cout << "fi b f" << _first << " " << _first->_back << " " << _first->_front << endl;
		// cout << "la b f" << _last << " " << _last->_back << " " << _last->_front << endl;
	}
	
	_len++;
}

void Liste::pushLast(void *obj){
	if(_first == NULL){
		pushFirst(obj);
	} else {		
		ListeItem *newL = new ListeItem(_last, NULL, obj);
		_last->_front = newL;
		_last = newL;
		
		_len++;
	}
}

void Liste::empty(){
	while(_len){
		remove(0);
	}
}

void Liste::remove(int index){
	if(index < 0){
		index = _len + index;
	}
	
	if(index < 0 || index >= _len){
		//TODO TROW ERR
		cout << "ERROR remove index out of range" << endl;
		return;
	}
	
	if(index == 0){
		removeFirst();
	} else if(index == _len-1) {
		removeLast();
	} else {
		ListeItem *r = _getItem(index);
		ListeItem *b = r->_back;
		ListeItem *f = r->_front;
		
		b->_front = f;
		f->_back = b;
		
		delete r;
		_len--;	
	}
}

void Liste::removeLast(){
	if(_len == 0){
		return;
	} else if(_len == 1) {
		delete _first;
		
		_first = NULL;
		_last = NULL;
	} else {
		ListeItem *b = _last->_back;
		
		b->_front = NULL;
		delete _last;
		_last = b;
	}
	
	_len--;
}

void Liste::removeFirst(){
	if(_len == 0){
		return;
	} else if(_len == 1) {
		delete _first;
		
		_first = NULL;
		_last = NULL;
	} else {
		ListeItem *f = _first->_front;
		
		f->_back = NULL;
		delete _first;
		_first = f;		
	}
	
	_len--;
}

string Liste::toString(){
	int TAB_LEN = 3;
	stringstream ss;
	
	stringstream row_1;
	stringstream row_2;
	
	for(int i=0; i<_len; i++){
		PlatChoisi *p = getObj(i);
		row_1 << '|' << setw(TAB_LEN) << i;
		row_2 << '|' << setw(TAB_LEN) << p->getnb();
	}
	
	ss << row_1.str() << '|' << endl;
	ss << sep('-', ((TAB_LEN + 1) * _len) + 1) << endl;
	ss << row_2.str() << '|';
	
	return ss.str();
}


ListeItem::ListeItem(){
	_back = NULL;
	_front = NULL;
	_obj = NULL;
}

ListeItem::ListeItem(ListeItem *back, ListeItem *front, void *obj){
	_back = back;
	_front = front;
	_obj = obj;	
}

ListeItem::~ListeItem(){
	//maybe some memory leak
	
	_back = NULL;
	_front = NULL;
	_obj = NULL;
	// delete _obj;
}

void* ListeItem::getObj(){
	return _obj;
}