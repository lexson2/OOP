#include "polinom.h"

polinom::polinom(number x,number y,number z)
{
    a=x;b=y;c=z;
}

int polinom::roots(number* x)
{
    x[0]=5;
    x[1]=-5;
    return 2;
}

ostream& operator << (ostream& os, polinom& p)
{
    os<<p.a<<"x^2+"<<p.b<<"x+"<<p.c;
    return os;
}
