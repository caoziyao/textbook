#include "textbook.h"

TextBook::TextBook(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
//	ui.setupUi(this);

	/*����*/
	fileName = tr("notitle");	
	this->setWindowTitle(fileName + "-TextBook-");

	textEdit = new QTextEdit;
	setCentralWidget(textEdit);

	/*����*/
	SetAction();
	SetMenu();

	/*���ڴ�С*/
	resize( 800, 600 );

	/*���������С*/
	textEdit->setCurrentFont( QFont("Consolas", 11, QFont::Normal) );

}

void TextBook::SetAction()
{
	newFileAction = new QAction( tr("�½�(N)"), this );	//�½�
	openFileAction = new QAction( tr("��(O)"), this ); //��
	saveAction = new QAction( tr("����(S)"), this );	//����
	saveAsAction = new QAction( tr("���Ϊ..."), this );
	closeAction = new QAction( tr("�˳�(X)"), this );

	/*�źŲ�*/
	connect(newFileAction, SIGNAL(triggered()), this, SLOT(slotNewFile()) );
	connect(saveAction, SIGNAL(triggered()), this, SLOT(slotSaveFile()) );
	connect(openFileAction, SIGNAL(triggered()), this, SLOT(slotOpenFile()) );
	connect(saveAsAction, SIGNAL(triggered()), this, SLOT(slotSaveAsFilee()) );
	connect(closeAction, SIGNAL(triggered()), this, SLOT(close()) );


	/*��ݼ�*/
	saveAction->setShortcut(QKeySequence::Save);
	openFileAction->setShortcut(QKeySequence::Open);
	newFileAction->setShortcut(QKeySequence::New);
	closeAction->setShortcut(QKeySequence::Close);
	
}

void TextBook::SetMenu()
{
	fileMenu = menuBar()->addMenu( tr("�ļ�(F)") );
	editMenu = menuBar()->addMenu( tr("�༭(E)") );
	formatMenu = menuBar()->addMenu( tr("��ʽ(O)") );
	viewMenu = menuBar()->addMenu( tr("�鿴(V)") );
	helpMenu = menuBar()->addMenu( tr("����(H)") );

	fileMenu->addAction(newFileAction);
	fileMenu->addAction(openFileAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(saveAsAction);
	fileMenu->addAction(closeAction);
	
}

/*�½��ļ�*/
void TextBook::slotNewFile()
{

}
/*�����ļ�*/
void TextBook::slotSaveFile()
{
	if(fileName == tr("notitle") )
	{
		fileName = QFileDialog::getSaveFileName(this, tr("save"),  
			"untitled.txt",  
			tr("textbook (*.txt)"));  
		QString content= textEdit->toPlainText();  
		QFile file(fileName);  
		if(file.open(QFile::WriteOnly|QFile::Text))  
		{  
			QTextStream save(&file);  
			save<<content;  
			this->setWindowTitle(fileName+"-Notepad+");  
			//changed=0;  
		}  
	}
	else
	{
		QString content=textEdit->toPlainText();  
		QFile file(fileName);  
		if(file.open(QFile::WriteOnly|QFile::Text))  
		{  
			QTextStream save(&file);  
			save<<content;  
			this->setWindowTitle(fileName+"-Notepad+");  
		//	changed=0;  
		}  
	}
	
}

/*���ļ�*/
void TextBook::slotOpenFile()
{
	fileName = QFileDialog::getOpenFileName(this, tr("SS"), 
		"/home", 
		tr("*.txt") ); 
	QFile file(fileName);

//	QMessageBox *mb = new QMessageBox;
//mb->setText(fileName);
//mb->exec(); 

	if (file.open(QFile::ReadOnly | QFile::Text))  
	{
		QTextStream in(&file);
		QString s = in.readAll();
		textEdit->setPlainText(s);
//		textEdit->setText(s);
	}
 
	setWindowTitle(fileName+"-Notepad-");  
}
/*�򿪴������ļ�*/
void TextBook::OpenFile(int argc, char *argv[])
{
	fileOpenName = QString(*(argv+1));
	if(!fileOpenName.isEmpty())
	{
		fileName = fileOpenName;
		QFile file(fileOpenName);
		if(file.open(QFile::ReadOnly | QFile::Text))
		{
			QTextStream in(&file);
			QString s = in.readAll();
			textEdit->setPlainText(s);
		}
		setWindowTitle(fileName+"-Notepad-");  
	}
	

}

/*���Ϊ�ļ�*/
void TextBook::slotSaveAsFilee()
{

}

TextBook::~TextBook()
{

}
