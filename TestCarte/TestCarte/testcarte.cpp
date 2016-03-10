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

void TestCarte::write(ofstream &os, int i){
	os << "Type test: " << _archive.getObj(i).typeTest << endl;
	os << "Adresse switches: " << _archive.getObj(i).registreSW << endl;
	os << "Retour switches: " << hex << _archive.getObj(i).retourSW << "(" << dec << _archive.getObj(i).retourSW << ")" << endl;
	os << "Etat switches: " << hex << _archive.getObj(i).etatSW << "(" << dec << _archive.getObj(i).etatSW << ")" << endl;
	os << "Adresse leds: " << _archive.getObj(i).registreLD << endl;
	os << "Valeur leds: " << hex << _archive.getObj(i).valeurLD << "(" << dec << _archive.getObj(i).valeurLD << ")" << endl;
	os << "Etat leds: " << hex << _archive.getObj(i).etatLD << "(" << dec << _archive.getObj(i).etatLD << ")" << endl << endl;
}

void TestCarte::sauvegarder(char *file_name) {
	ofstream os;
	os.open(file_name,ios::trunc);
	
	if (_archive_mode == Queue){
		for (int i = 0; i < _archive.length(); i++){
			write(os, i);
		}
	}
	else{
		for (int i = _archive.length(); i > 0; i--){
			write(os, i);
		}
	}
	os.close();
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
	if (_archive_mode == Queue){
		if (_index != 0){
			_index--;
			setArchive(_archive.getObj(_index));
			setArchive(_index, _archive.length());
		}
	}
	else{
		if (_index != _archive.length()){
			_index++;
			setArchive(_archive.getObj(_index));
			setArchive(_index, _archive.length());
		}
	}
}

void TestCarte::suivant(){
	if (_archive_mode == Queue){
		if (_index != _archive.length()){
			_index++;
			setArchive(_archive.getObj(_index));
			setArchive(_index, _archive.length());
		}
	}
	else{
		if (_index != 0){
			_index--;
			setArchive(_archive.getObj(_index));
			setArchive(_index, _archive.length());
		}
	}
}