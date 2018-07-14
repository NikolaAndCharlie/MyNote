#include "mainwidget.h"
#include "textedit.h"
#include <QPlainTextEdit>
#include <QCoreApplication>
#include <QVBoxLayout>
#include <iostream>
#include <QTextStream>
#include <QIODevice>

using namespace std;
QString widgetstyle = "QWidget {background: rgb(251,255,169)}";
QString plainTextEditStyle = "QPlainTextEdit {background: rgb(251,255,169); border:none}";


MainWidget::MainWidget()
{
    this->setFixedSize(320, 270);
    this->setStyleSheet(widgetstyle);
    setUi();
    getText();
    
}


MainWidget::~MainWidget()
{
    
}

void MainWidget::getText()
{
    QString s = QCoreApplication::applicationDirPath();
    QString filePath = s + "/Note.txt";
    QFile file(filePath);

    disconnect(m_mainPlainText, &QPlainTextEdit::textChanged, this, &MainWidget::refreshText);
    if(!file.exists())
    {
       if (!file.open(QIODevice::ReadWrite))
       {
           return;
       }
       file.close();
    }

    if(!file.open(QIODevice::ReadOnly))
    {
        return;
    }


    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        m_mainPlainText->appendPlainText(line);
    }
    file.close();

    connect(m_mainPlainText, &QPlainTextEdit::textChanged, this, &MainWidget::refreshText);
}

void MainWidget::refreshText()
{
    QString s = m_mainPlainText->toPlainText();
    QStringList sList = s.split('\n');
    QString filePath = QCoreApplication::applicationDirPath();
    QString recordFilePath = filePath + "/Note.txt";
    QFile file(recordFilePath);
    if(!file.open(QIODevice::WriteOnly| QIODevice::Truncate))
    {
        return ;
    }
    QTextStream ss(&file);

    for each(QString temps in sList)
    {
       // temps = temps + '\r\n';
        ss << temps;
        ss << '\n';
    }

    file.close();
}

void MainWidget::setUi()
{
    QVBoxLayout* mainlayout = new QVBoxLayout(this);

    m_mainPlainText = new TextEdit;
    m_mainPlainText->setStyleSheet(plainTextEditStyle);
    connect(m_mainPlainText, &TextEdit::textChanged, this, &MainWidget::refreshText);
    mainlayout->addWidget(m_mainPlainText);
    
}


