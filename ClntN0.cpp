#include "ClntN0.h"





    ClntN0 :: ClntN0(const bool r,const int m, const vector<int> brr, const string filename)
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

    ClntN0 :: ClntN0(const bool r,const int m, const vector<int> brr)
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

    void ClntN0 :: CopyOnly(const ClntN &b)
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

    void ClntN0 :: CopyOnly(const ClntN0 &b)
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



ClntN0 operator+(const ClntN&a,const ClntN&b)
{
   bool h,z=0, d=0;
    if(b.len()!=a.len())
    {
        cout<<"Error! Different length..."<<endl;
        throw 1;
    }
    else{}
    if(b.len()==0 || a.len()==0)
    {
        cout<<"Error! Zero length..."<<endl;
        throw 1;
    }
    ClntN0 f;
    f.s=a.sign();
    f.n=a.len();
    f.arr=new int[a.len()];
    if(b.sign()==a.sign())
    {
        for(int i=a.len()-1; i>=0; i--)
        {
            if(d==1)
                {
                    f.arr[i]=1;
                    d=0;
                }
                else f.arr[i]=0;
            f.arr[i]=f.arr[i]+(a[i]+b[i])%10;
            if ((a[i]+b[i])/10==1)
                {
                    d=1;
                }
        }
        if(d==1)
        {
            cout<<"Too big number"<<endl;
            throw 5;
        }
    }

    else
    {

        for(int i=0; i<a.len(); i++)
        {
            if(a[i]!=b[i])
            {
                if(a[i]>b[i])
                    {h=true;}
                else
                {h=false;}
                break;
            }

        }

        if(h==true)
        {
           for(int i=a.len()-1; i>=0; i--)
           {
               if(z==1)
               {
                   a[i]=a[i]-1;
                   z=0;
               }
               if(a[i]<b[i])
               {
                   f.arr[i]=a[i]+10-b[i];
                   z=1;
               }
               else
               {
                   f.arr[i]=a[i]-b[i];
               }
           }

        }
        if(h==false)
        {
           f.s=b.sign();
           for(int i=a.len()-1; i>=0; i--)
           {
               if(z==1)
               {
                   z=0;
                   b[i]=b[i]-1;
               }
               if(b[i]<a[i])
               {
                   f.arr[i]=-a[i]+10+b[i];
                   z=1;
               }
               else
               {
                   f.arr[i]=-a[i]+b[i];
               }
           }



        }

    }

return f;
}


ClntN0 operator-(const ClntN&a,const ClntN&b)
{
   bool s,h,z=0, d=0;
   int n;
   n=a.len();
   s=a.sign();
    if(b.len()!=n)
    {
        cout<<"Error! Different length..."<<endl;
        throw 1;
    }
    else{}
    if(b.len()==0 || n==0)
    {
        cout<<"Error! Zero length..."<<endl;
        throw 1;
    }
    ClntN0 f;
    f.s=s;
    f.n=n;
    f.arr=new int[n];
    if(!b.sign()==s)
    {
        for(int i=n-1; i>=0; i--)
        {
            if(d==1)
                {
                    f.arr[i]=1;
                    d=0;
                }
                else f.arr[i]=0;
            f.arr[i]=f.arr[i]+(a[i]+b[i])%10;
            if ((a[i]+b[i])/10==1)
                {
                    d=1;
                }



        }
        if(d==1)
        {
            cout<<"Too big number"<<endl;
            throw 5;
        }
    }

    else
    {

        for(int i=0; i<n; i++)
        {
            if(a[i]!=b[i])
            {
                if(a[i]>b[i])
                    {h=true;}
                else
                {h=false;}
                break;
            }

        }

        if(h==true)
        {
           for(int i=n-1; i>=0; i--)
           {
               if(z==1)
               {
                   a[i]=a[i]-1;
                   z=0;
               }
               if(a[i]<b[i])
               {
                   f.arr[i]=a[i]+10-b[i];
                   z=1;
               }
               else
               {
                   f.arr[i]=a[i]-b[i];
               }
           }

        }
        if(h==false)
        {
           f.s=!b.sign();
           for(int i=n-1; i>=0; i--)
           {
               if(z==1)
               {
                   z=0;
                   b[i]=b[i]-1;
               }
               if(b[i]<a[i])
               {
                   f.arr[i]=-a[i]+10+b[i];
                   z=1;
               }
               else
               {
                   f.arr[i]=-a[i]+b[i];
               }
           }



        }

    }

return f;
}
