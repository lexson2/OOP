#include "interface.h"

TInterface::TInterface(QWidget *parent)
          : QWidget(parent)
{
    t1 = new QLabel("Число:",this);
    t1->setGeometry(20,30,70,25);
    t2 = new QLabel("Символ:",this);
    t2->setGeometry(20,70,70,25);

    e1 = new QLineEdit("1",this);
    e1->setGeometry(90,30,40,25);
    e2 = new QLineEdit("a",this);
    e2->setGeometry(90,70,40,25);

    btn = new QPushButton("Передать",this);
    btn->setGeometry(25,110,100,30);

    connect(btn,SIGNAL(pressed()),this,SLOT(sendEvent()));

    setWindowTitle("Тест");
    setFixedSize(150,150);
}

TInterface::~TInterface()
{

}

void TInterface::sendEvent()
{
    TInterfaceMessage msg;
    msg.IntData = e1->text();
    msg.ChrData = e2->text();
    emit send(msg);
}

void TInterface::recieve(TInterfaceMessage msg)
{
    e1->setText(msg.IntData);
    e2->setText(msg.ChrData);
}

