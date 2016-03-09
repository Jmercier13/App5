#include "testcarte.h"

TestCarte::TestCarte(string title) : VisiTest(title.c_str()) {

}

TestCarte::~TestCarte()
{

}


void TestCarte::testSuivant(){

}


void TestCarte::premier(){
	_index = 0;
	setArchive(_archive.getObj(_index));
	setArchive(_index, _archive.length());
}

void TestCarte::dernier(){
	_index = _archive.length();
	setArchive(_archive.getObj(_index));
	setArchive(_index, _archive.length());
}

void TestCarte::precedent(){
	_index--;
	setArchive(_archive.getObj(_index));
	setArchive(_index, _archive.length());
}

void TestCarte::suivant(){
	_index++;
	setArchive(_archive.getObj(_index));
	setArchive(_index, _archive.length());
}