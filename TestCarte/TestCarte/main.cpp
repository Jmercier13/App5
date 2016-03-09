#include "testcarte.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestCarte w("TestCarte beaj2031 - merj2607 - lalm3207");
	w.show();
	return a.exec();
}
