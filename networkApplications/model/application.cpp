#include "application.h"

TApplication::TApplication(int argc, char *argv[])
            : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10001,
                         QHostAddress("127.0.0.1"), 10000};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(fromCommunicator(QByteArray)));
    connect(this,SIGNAL(toCommunicator(QByteArray)),comm,SLOT(send(QByteArray)));

}

void TApplication::fromCommunicator(QByteArray msg)
{
    int pos = msg.indexOf(";");
    if (pos > 0)
    {
        QByteArray arr;
        TInterfaceMessage data;
        //decode
        data.IntData = QString(msg.left(pos));
        data.ChrData = QString(msg.right(msg.size()-pos-1));
        //modify
        int i = data.IntData.toInt() + 1;
        data.ChrData.append(data.ChrData);
        data.ChrData = data.ChrData.left(1+i%3);
        //code
        arr.append(QByteArray().setNum(i));
        arr.append(";");
        arr.append(data.ChrData);
        //transmit
        emit toCommunicator(arr);
    }
}
