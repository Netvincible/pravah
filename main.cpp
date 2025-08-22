#include "pravah.h"
using namespace std;
int main()
{
    pravah<int> a({3,1,3,5,2,6});
    pravah<int> b(4);
    pravah<int> c(5,1);

    int n=a.maap();
    for(int i=0;i<n;i++)
    {
        cout << a.pr[i] << " ";
    }
    cout << endl;

    a.nivesh(3,10);
    cout<< "insert" << endl;
    n=a.maap();
    for(int i=0;i<n;i++)
    {
        cout << a.pr[i] << " ";
    }
    cout << endl;

    a.vinivesh(1);
    cout<< "pop at 1" << endl;
    n=a.maap();
    for(int i=0;i<n;i++)
    {
        cout << a.pr[i] << " ";
    }
    cout << endl;

    cout << "index of 10: " << a.dhundho(10) << endl;

    a.kram();
    cout<< "sort" << endl;
    n=a.maap();
    for(int i=0;i<n;i++)
    {
        cout << a.pr[i] << " ";
    }
    cout << endl;

    a.viprit();
    cout <<"reverse" << endl;
    n=a.maap();
    for(int i=0;i<n;i++)
    {
        cout << a.pr[i] << " ";
    }
    cout << endl;

    pravah<int> d;
    d.nakal(a);
    cout <<"copy a in d" <<endl;
    n=d.maap();
    for(int i=0;i<n;i++)
    {
        cout << d.pr[i] << " ";
    }
    cout << endl;

    a.maap_parivartan(a.maap()-2);
    cout <<"reduced size by 2" << endl;
    n=a.maap();
    for(int i=0;i<n;i++)
    {
        cout << a.pr[i] << " ";
    }
    cout << endl;

    a.maap_parivartan(a.maap()+2);
    cout <<"increased size by 2" << endl;
    n=a.maap();
    for(int i=0;i<n;i++)
    {
        cout << a.pr[i] << " ";
    }
    cout << endl;
}

/*
New Things learned:
    1. Template
    2. Initializer_list
    3. When using templete its better to write driver.cpp in header file
    4. in functions use call by reference when your object has pointer in it, and destructor destroys the memory at pointer.
*/