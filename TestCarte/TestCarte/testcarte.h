#pragma once

#include <string>
#include <iostream>

#include "VisiTest.h"
#include "list.h"

using namespace std;

enum ArchiveMode {Queue, Stack};
enum ArchiveState {Start, Stop};

class TestCarte : public VisiTest{
	private:
		ArchiveMode _archive_mode = Queue;
		List<DonneesTest> _archive;

		ArchiveState _archive_state = Stop;
	public:
		TestCarte(string title);
		~TestCarte();

		void demarrer();
		void aretter();
		void vider();

		void sauvegarder(char *file_name);
		void modeFile();
		void modePile();
};

