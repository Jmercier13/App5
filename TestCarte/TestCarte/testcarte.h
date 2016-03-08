#ifndef TESTCARTE_H
#define TESTCARTE_H

#include <QtWidgets/QMainWindow>
#include "ui_testcarte.h"

class TestCarte : public QMainWindow
{
	Q_OBJECT

public:
	TestCarte(QWidget *parent = 0);
	~TestCarte();

private:
	Ui::TestCarteClass ui;
};

#endif // TESTCARTE_H
