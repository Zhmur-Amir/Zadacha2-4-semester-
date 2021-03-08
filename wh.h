#include "ClntN1.h"


class CFactory
{

public:
    ClntN* Create0(bool s, int n, int *arr, const char* FileName)
    {
        ClntN0*v=new ClntN0(s,n,arr,FileName);
        return   v;
    }
    ClntN* Create1(bool s, int n, int *arr, const char* FileName)
    {
        ClntN1*v= new ClntN1(s,n,arr,FileName);
        return  v;
    }
};

void Autotest(void);
int Auto(void);
ostream &operator<<(ostream &cout,  ClntN &s);
ClntN* CCreate(string str,CFactory stln, int r);
int PyatiletkyV4Goda(const char* FileName);
