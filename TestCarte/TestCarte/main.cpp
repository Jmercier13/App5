#include <QtWidgets/QApplication>
#include "testcarte.h"

//#include "list.h"

int main(int argc, char *argv[])
{
	//List<int> l = List<int>();
	//l.add(0);


	QApplication a(argc, argv);
	TestCarte w("TestCarte beaj2031 - merj2607 - lalm3207");
	w.show();
	return a.exec();
}
