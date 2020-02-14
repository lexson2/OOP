#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QCoreApplication>

#include "communicator.h"

struct TInterfaceMessage
{
    QString IntData;
    QString ChrData;
};

class TApplication : public QCoreApplication
{
    Q_OBJECT

    TCommunicator *comm;

public:

    TApplication(int, char**);

signals:

    void toCommunicator(QByteArray);

public slots:

    void fromCommunicator(QByteArray);

};

#endif // APPLICATION_H
