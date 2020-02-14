#include "application.h"

#include <QDebug>

TApplication::TApplication(int argc, char *argv[])
            : QApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);
    interface = new TInterface();
    interface->show();

    connect(interface,SIGNAL(send(TInterfaceMessage)),
            this,SLOT(fromInterface(TInterfaceMessage)));
    connect(this,SIGNAL(toCommunicator(QByteArray)),comm,SLOT(send(QByteArray)));
    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(fromCommunucator(QByteArray)));
    connect(this,SIGNAL(toInterface(TInterfaceMessage)),
            interface,SLOT(recieve(TInterfaceMessage)));
}

void TApplication::fromInterface(TInterfaceMessage msg)
{
    QByteArray data;
    data.append(QByteArray().setNum(msg.IntData.toInt()));
    data.append(";");
    data.append(msg.ChrData);
    emit toCommunicator(data);
}

void TApplication::fromCommunucator(QByteArray msg)
{
    int pos = msg.indexOf(";");
    if (pos > 0)
    {
        TInterfaceMessage data;
        data.IntData = QString(msg.left(pos));
        data.ChrData = QString(msg.right(msg.size()-pos-1));
        emit toInterface(data);
    }
}
