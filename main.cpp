#include "textbook.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());  //֧��������ʾ
	TextBook w;
	w.show();
/*
	QMessageBox *mb = new QMessageBox;
	mb->setText( QString(*(argv+1)) );
	mb->exec(); 
*/

	w.OpenFile(argc, argv);

	return a.exec();
}
