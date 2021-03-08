#include "ClntN.h"
#include "ClntN1.h"
#include "ClntN0.h"
#include "wh.h"


int main(void)
{
cout<<endl<<"Starting program..."<<endl<<endl;
ofstream out1("Data1.txt"), out2("Data0.txt");
if(!out1 || !out2)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
out1.close();
out2.close();
PyatiletkyV4Goda("Data.txt");
cout<<endl<<"============================="<<endl<<endl;
Autotest();
Auto();
return 0;
}
