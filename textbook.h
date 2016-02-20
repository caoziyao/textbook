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
	Q_OBJECT	//��

public:
	TextBook(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TextBook();

	void OpenFile();	//���ļ�
	void OpenFile(int argc, char *argv[]);
	void SaveFile();	//�����ļ�
	void SetMenu();		//���ý���
	void SetAction();	//����Action
	
private slots:
	//void	SlotOpen();
	void slotNewFile();
	void slotSaveFile();
	void slotOpenFile();
	void slotSaveAsFilee();

private:
//	Ui::TextBookClass ui;
	QString curfile;
	QString fileName;	//�ļ���
	QString fileOpenName;  //���ļ���
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
