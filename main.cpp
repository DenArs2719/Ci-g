#include "laba.h"
using namespace std;

int main()
{
    srand(time(NULL));

    Ciag T1;
    Ciag T2(6,1,5);

    {
        Ciag t = T2;
        cout<<t<<endl;
    }
    {
        Ciag t2;
        t2 = T2;
        cout<<t2<<endl;
    }
    cout<<T1<<endl;
    cout<<T2<<endl;
    ++T2;
    cout<<T2<<endl;







    return 0;
}
