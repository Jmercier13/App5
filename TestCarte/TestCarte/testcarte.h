#pragma once

#include <string>
#include <list.h>
#include "VisiTest.h"

using namespace std;

class TestCarte : public VisiTest{
	private:
		List<DonneesTest> _archive;
		int _index = 0;

	public:
		TestCarte(string title);
		~TestCarte();
		//Test section
		void testSuivant();
		
		//Archive Section
		void premier();
		void dernier();
		void precedent();
		void suivant();
		
};

