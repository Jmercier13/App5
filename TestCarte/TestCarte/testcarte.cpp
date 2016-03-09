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