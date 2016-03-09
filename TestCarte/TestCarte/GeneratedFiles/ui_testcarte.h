/********************************************************************************
** Form generated from reading UI file 'testcarte.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTCARTE_H
#define UI_TESTCARTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestCarteClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestCarteClass)
    {
        if (TestCarteClass->objectName().isEmpty())
            TestCarteClass->setObjectName(QStringLiteral("TestCarteClass"));
        TestCarteClass->resize(600, 400);
        menuBar = new QMenuBar(TestCarteClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TestCarteClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestCarteClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TestCarteClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TestCarteClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TestCarteClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TestCarteClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestCarteClass->setStatusBar(statusBar);

        retranslateUi(TestCarteClass);

        QMetaObject::connectSlotsByName(TestCarteClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestCarteClass)
    {
        TestCarteClass->setWindowTitle(QApplication::translate("TestCarteClass", "TestCarte", 0));
    } // retranslateUi

};

namespace Ui {
    class TestCarteClass: public Ui_TestCarteClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTCARTE_H
