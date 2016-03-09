#include <QtWidgets/QApplication>
#include <QDebug>


#include "testcarte.h"

#include "list.h"

int main(int argc, char *argv[])
{
	string aa = "0";
	string b = "1";
	string c = "2";

	List<string> l = List<string>();
	l.add(aa);
	l.add(b);
	l.add(c);

	qDebug() << l << " asdf" << endl;


	//cout << l;


	QApplication a(argc, argv);
	TestCarte w("TestCarte beaj2031 - merj2607 - lalm3207");
	w.show();
	return a.exec();
}
