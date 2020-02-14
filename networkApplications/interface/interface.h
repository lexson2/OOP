#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

struct TInterfaceMessage
{
    QString IntData;
    QString ChrData;
};

class TInterface : public QWidget
{
    Q_OBJECT

    QLabel    *t1;
    QLabel    *t2;
    QLineEdit *e1;
    QLineEdit *e2;
    QPushButton *btn;

public:
    TInterface(QWidget *parent = 0);
    ~TInterface();

signals:

    void send(TInterfaceMessage);

private slots:

    void sendEvent();

public slots:

    void recieve(TInterfaceMessage);

};

#endif // TINTERFACE_H
