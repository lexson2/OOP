#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QApplication>

#include "interface.h"
#include "communicator.h"

class TApplication : public QApplication
{
    Q_OBJECT

    TCommunicator *comm;
    TInterface    *interface;

public:

    TApplication(int, char**);

signals:

    void toInterface(TInterfaceMessage);
    void toCommunicator(QByteArray);

public slots:

    void fromInterface(TInterfaceMessage);
    void fromCommunucator(QByteArray);

};

#endif // APPLICATION_H
