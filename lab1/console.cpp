#include "console.h"
#include "polinom.h"
#include "number.h"
#include <iostream>
using namespace std;

int console::exec()
{
    int ch;
    number a=1,b=2,c=1;
    while (true)
    {
        menu();
        cin>>ch;
        if (ch==0) break;
        switch (ch)
        {
            case 1:
                cout<<"a=";
                cin>>a;
                cout<<"b=";
                cin>>b;
                cout<<"c=";
                cin>>c;
                break;
            case 2:
                {
                    number x[2];
                    polinom p(a,b,c);
                    int n = p.roots(x);
                    switch (n)
                    {
                    case 0:
                        break;
                    case 1:
                        break;
                    case 2:
                        cout<<"x1="<<x[0]<<" x2="<<x[1]<<endl;
                        break;
                    }
                }
                break;
            case 3:
                break;
            case 4:
                {
                    polinom p(a,b,c);
                    cout<<p<<endl;
                }
                break;
        }
    }
    cout<<"exit"<<endl;
    return 0;
}

void console::menu()
{
    cout<<"1. coeff"<<endl;
    cout<<"2. roots"<<endl;
    cout<<"3. value"<<endl;
    cout<<"4. p(x)"<<endl;
    cout<<"0. exit"<<endl;
}

