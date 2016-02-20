/********************************************************************************
** Form generated from reading ui file 'textbook.ui'
**
** Created: Fri Feb 19 21:10:47 2016
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TEXTBOOK_H
#define UI_TEXTBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextBookClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TextBookClass)
    {
        if (TextBookClass->objectName().isEmpty())
            TextBookClass->setObjectName(QString::fromUtf8("TextBookClass"));
        TextBookClass->resize(600, 400);
        menuBar = new QMenuBar(TextBookClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        TextBookClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TextBookClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TextBookClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TextBookClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TextBookClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TextBookClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TextBookClass->setStatusBar(statusBar);

        retranslateUi(TextBookClass);

        QMetaObject::connectSlotsByName(TextBookClass);
    } // setupUi

    void retranslateUi(QMainWindow *TextBookClass)
    {
        TextBookClass->setWindowTitle(QApplication::translate("TextBookClass", "TextBook", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(TextBookClass);
    } // retranslateUi

};

namespace Ui {
    class TextBookClass: public Ui_TextBookClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTBOOK_H
