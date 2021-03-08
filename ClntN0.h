#pragma once
#include "ClntN.h"



class ClntN0 : public ClntN
{
protected:
    const char* FileName;
public:
    ClntN0(){SetZero();}
    ~ClntN0(){Clean();}
    ClntN0 &operator=(const ClntN&b){if(this!=&b){Clean(); CopyOnly(b);} return *this;}
    void SetZero(){arr=NULL; s=NULL; n=0; FileName=NULL;}
    ClntN0(const bool r,const int m, const int* brr, const char* filename);
    void CopyOnly(const ClntN0 &b);
    void CopyOnly(const ClntN &b);
    friend ClntN0 operator+(const ClntN&a, const ClntN&b);
    friend ClntN0 operator-(const ClntN&a, const ClntN&b);
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

};

ClntN0 operator+(const ClntN&a, const ClntN&b);
ClntN0 operator-(const ClntN&a, const ClntN&b);



