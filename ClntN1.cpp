#include "ClntN1.h"



    ClntN1 :: ClntN1(const bool r,const int m, const vector<int> brr ,const string filename)
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

    ClntN1 :: ClntN1(const bool r,const int m, const vector<int> brr)
    {
      n=m;
      s=r;
      arr=new int[n];
      for(int i=0; i<n; i++)
        {
            if(brr[i]>=0 && brr[i]<10)
            arr[i]=brr[i];

      else  throw 2;
      }

    }

    void ClntN1 :: CopyOnly(const ClntN &b)
    {
      n=b.len();
      s=b.sign();
      arr=new int[n];
      for(int i=0; i<n; i++)
        {
            if(b[i]>=0 && b[i]<10)
            arr[i]=b[i];
      else throw 2;
      }
    }

    void ClntN1 :: CopyOnly(const ClntN1 &b)
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
