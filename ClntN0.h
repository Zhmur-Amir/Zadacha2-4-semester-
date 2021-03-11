#include "ClntN.h"



class ClntN0 : public ClntN
{
protected:
      string FileName;
public:
    ClntN0(){SetZero();}
    ~ClntN0(){Clean();}
    void SetZero(){arr=NULL; s=NULL; n=0; FileName.empty();}
    ClntN0 &operator=(const ClntN&b){if(this!=&b){Clean(); CopyOnly(b);} return *this;}
    ClntN0(const bool r,const int m, const vector<int> brr, const string filename);
    ClntN0(const bool r,const int m, const vector<int> brr);
    void CopyOnly(const ClntN0 &b);
    void CopyOnly(const ClntN &b);
    friend ClntN0 operator+(const ClntN&a,const ClntN&b);
    friend ClntN0 operator-(const ClntN&a,const ClntN&b);
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
        file<<endl;
        file.close();
        return 0;
    }
};
