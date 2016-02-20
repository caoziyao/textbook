#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include <QtGui/QMainWindow>
#include "ui_textbook.h"
#include <QAction>
#include <QMenu>
#include <QtGui>
#include <QTextEdit>
#include <QMessageBox>
#include <QFont>

class TextBook : public QMainWindow
{
	Q_OBJECT	//宏

public:
	TextBook(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TextBook();

	void OpenFile();	//打开文件
	void OpenFile(int argc, char *argv[]);
	void SaveFile();	//保存文件
	void SetMenu();		//设置界面
	void SetAction();	//设置Action
	
private slots:
	//void	SlotOpen();
	void slotNewFile();
	void slotSaveFile();
	void slotOpenFile();
	void slotSaveAsFilee();

private:
//	Ui::TextBookClass ui;
	QString curfile;
	QString fileName;	//文件名
	QString fileOpenName;  //打开文件名
	QTextEdit *textEdit;

	QMenu *fileMenu;
	QMenu *editMenu;
	QMenu *formatMenu;
	QMenu *viewMenu;
	QMenu *helpMenu;
	QAction *newFileAction;
	QAction *saveAction;
	QAction *openFileAction;
	QAction *saveAsAction;
	QAction *closeAction;



};

#endif // TEXTBOOK_H
