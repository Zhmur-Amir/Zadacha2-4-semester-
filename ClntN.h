#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;



class ClntN
{
protected:
    bool s; int n; int *arr;
public:
    ClntN(){SetZero();}
    ClntN(const ClntN &b){CopyOnly(b);}
    ~ClntN(){Clean();}
    ClntN &operator=(const ClntN&b){if(this!=&b){Clean(); CopyOnly(b);} return *this;}
    void Clean(){delete[] arr; SetZero();}
    virtual void SetZero(){arr=NULL; s=NULL; n=0;}
    virtual void CopyOnly(const ClntN &b);
    ClntN operator+(const ClntN&b);
    ClntN operator-(const ClntN&b);
    void CopyOnly(const bool r,const int m, const int* brr);
    ClntN(const bool r,const int m, const int* brr){CopyOnly(r,m,brr);}
    int &operator[](int i){if(i<0 || i>=n) throw 3; return arr[i];}
    bool sign(){return s;}
    void print();
    virtual int output(){return -2;}

};




class ClntN0 : public ClntN
{
protected:
      string FileName;
public:
    ClntN0(){SetZero();}
    ~ClntN0(){Clean();}
    void SetZero(){arr=NULL; s=NULL; n=0; FileName.empty();}
    ClntN0(const bool r,const int m, const vector<int> brr, const string filename)
    {
      n=m;
      s=r;
      FileName=filename;
      arr=new int[n];
      for(int i=0; i<n; i++)
        {
            if(brr[i]>=0 && brr[i]<10)
            arr[i]=brr[i];

      else  throw 2;
      }

    }


    int output() override
    {
        ofstream file(FileName, ios::app);
        if(!file)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        if(s==true)
        {
            file<<"+";
        }
        else
        {
            file<<"-";
        }
        for(int i=0; i<n; i++)
        {
            file<<arr[i];
        }
        file<<" ";
        file.close();
        return 0;
    }
    void CopyOnly(const ClntN0 &b)
 {
     n=b.n;
      s=b.s;
      FileName=b.FileName;
      arr=new int[n];
      for(int i=0; i<n; i++)
        {
            if(b.arr[i]>=0 && b.arr[i]<10)
            arr[i]=b.arr[i];
      else throw 2;
      }
}


};

class ClntN1 : public ClntN
{
protected:
     string FileName;
public:
     ClntN1(){SetZero();}
    ~ClntN1(){Clean();}
     void SetZero(){arr=NULL; s=NULL; n=0; FileName.empty();}
     ClntN1(const bool r,const int m, const vector<int> brr ,const string filename)
    {
      n=m;
      s=r;
      FileName=filename;
      arr=new int[n];
      for(int i=0; i<n; i++)
        {
            if(brr[i]>=0 && brr[i]<10)
            arr[i]=brr[i];
      else throw 2;
      }

    }

       int output() override
    {
        ofstream file(FileName, ios::app);
        if(!file)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        if(s==true)
        {
            file<<"+"<<endl;
        }
        else
        {
            file<<"-"<<endl;
        }
        for(int i=0; i<n; i++)
        {
            file<<arr[i]<<endl;
        }
        file<<"======="<<endl;
        file.close();
        return 0;
    }
    void CopyOnly(const ClntN1 &b)
 {
     n=b.n;
      s=b.s;
      FileName=b.FileName;
      arr=new int[n];
      for(int i=0; i<n; i++)
        {
            if(b.arr[i]>=0 && b.arr[i]<10)
            arr[i]=b.arr[i];
      else throw 2;
      }
}


};

class CFactory
{

public:
    virtual ClntN* Create(bool s, int n, const vector<int> arr , const string FileName){}

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
int PyatiletkyV4Goda(string FileName);


