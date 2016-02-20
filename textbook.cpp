#include "textbook.h"

TextBook::TextBook(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
//	ui.setupUi(this);

	/*标题*/
	fileName = tr("notitle");	
	this->setWindowTitle(fileName + "-TextBook-");

	textEdit = new QTextEdit;
	setCentralWidget(textEdit);

	/*界面*/
	SetAction();
	SetMenu();

	/*窗口大小*/
	resize( 800, 600 );

	/*设置字体大小*/
	textEdit->setCurrentFont( QFont("Consolas", 11, QFont::Normal) );

}

void TextBook::SetAction()
{
	newFileAction = new QAction( tr("新建(N)"), this );	//新建
	openFileAction = new QAction( tr("打开(O)"), this ); //打开
	saveAction = new QAction( tr("保存(S)"), this );	//保存
	saveAsAction = new QAction( tr("另存为..."), this );
	closeAction = new QAction( tr("退出(X)"), this );

	/*信号槽*/
	connect(newFileAction, SIGNAL(triggered()), this, SLOT(slotNewFile()) );
	connect(saveAction, SIGNAL(triggered()), this, SLOT(slotSaveFile()) );
	connect(openFileAction, SIGNAL(triggered()), this, SLOT(slotOpenFile()) );
	connect(saveAsAction, SIGNAL(triggered()), this, SLOT(slotSaveAsFilee()) );
	connect(closeAction, SIGNAL(triggered()), this, SLOT(close()) );


	/*快捷键*/
	saveAction->setShortcut(QKeySequence::Save);
	openFileAction->setShortcut(QKeySequence::Open);
	newFileAction->setShortcut(QKeySequence::New);
	closeAction->setShortcut(QKeySequence::Close);
	
}

void TextBook::SetMenu()
{
	fileMenu = menuBar()->addMenu( tr("文件(F)") );
	editMenu = menuBar()->addMenu( tr("编辑(E)") );
	formatMenu = menuBar()->addMenu( tr("格式(O)") );
	viewMenu = menuBar()->addMenu( tr("查看(V)") );
	helpMenu = menuBar()->addMenu( tr("帮助(H)") );

	fileMenu->addAction(newFileAction);
	fileMenu->addAction(openFileAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(saveAsAction);
	fileMenu->addAction(closeAction);
	
}

/*新建文件*/
void TextBook::slotNewFile()
{

}
/*保存文件*/
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

/*打开文件*/
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
/*打开带参数文件*/
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

/*另存为文件*/
void TextBook::slotSaveAsFilee()
{

}

TextBook::~TextBook()
{

}
