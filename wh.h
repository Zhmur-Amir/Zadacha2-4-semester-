#include "ClntN1.h"


class CFactory
{

public:
    virtual ClntN* Create(bool s, int n, const vector<int> arr , const string FileName)=0;

};

class CFactory0 : public CFactory
{
public:
    ClntN* Create(bool s, int n, const vector<int> arr , const string FileName)
    {
        ClntN0*v=new ClntN0(s,n,arr,FileName);
        return   v;
    }

};

class CFactory1 : public CFactory
{
public:
    ClntN* Create(bool s, int n, const vector<int> arr , const string FileName)
    {
        ClntN1*v=new ClntN1(s,n,arr,FileName);
        return   v;
    }

};

void Autotest(void);
int Auto(void);
ostream &operator<<(ostream &cout,  ClntN &s);
ClntN* CCreate(string str, int r);
int PyatiletkyV4Goda(const string FileName);
