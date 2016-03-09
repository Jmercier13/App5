#include "testcarte.h"

TestCarte::TestCarte(string title) : VisiTest(title.c_str()) {

}

TestCarte::~TestCarte() {

}

void TestCarte::demarrer() {
	_archive_state = Start;
}

void TestCarte::aretter() {
	_archive_state = Stop;
}

void TestCarte::vider() {
	_archive.empty();
}

void TestCarte::sauvegarder(char *file_name) {
	
}

void TestCarte::modeFile() {
	_archive_mode = Queue;
}

void TestCarte::modePile() {
	_archive_mode = Stack;
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