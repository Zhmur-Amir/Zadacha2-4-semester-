#include "ClntN.h"

void ClntN :: print()
{
    bool d=true;
    if(n==0)
        cout<<"Zero ClntN";
    else{
        for(int i=0; i<n; i++)
        {
            if(arr[i]!=0)
            d=false;
        }
        if (d==true){
        for(int i=0; i<n; i++)
        {
            cout<<arr[i];
            }

        }

        else
        {
            if(s==true)
            {cout<<"+";
            }
    else
        {
            if(s==false)
                  {
                      cout<<"-";
                  }
        }
         for(int i=0; i<n; i++)
        {
            cout<<arr[i];
        }
        }
}

}


ClntN ClntN :: operator+(const ClntN&b)
{
   ClntN r;
   bool h,z=0, d=0;
    if(b.n!=n)
    {
        cout<<"Error! Different length..."<<endl;
        throw 1;
    }
    else{}
    if(b.n==0 || n==0)
    {
        cout<<"Error! Zero length..."<<endl;
        throw 1;
    }
    ClntN f;
    f.s=s;
    f.n=n;
    f.arr=new int[n];
    if(b.s==s)
    {
        for(int i=n-1; i>=0; i--)
        {
            if(d==1)
                {
                    f.arr[i]=1;
                    d=0;
                }
                else f.arr[i]=0;
            f.arr[i]=f.arr[i]+(arr[i]+b.arr[i])%10;
            if ((arr[i]+b.arr[i])/10==1)
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
            if(arr[i]!=b.arr[i])
            {
                if(arr[i]>b.arr[i])
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
                   arr[i]=arr[i]-1;
                   z=0;
               }
               if(arr[i]<b.arr[i])
               {
                   f.arr[i]=arr[i]+10-b.arr[i];
                   z=1;
               }
               else
               {
                   f.arr[i]=arr[i]-b.arr[i];
               }
           }

        }
        if(h==false)
        {
           f.s=b.s;
           for(int i=n-1; i>=0; i--)
           {
               if(z==1)
               {
                   z=0;
                   b.arr[i]=b.arr[i]-1;
               }
               if(b.arr[i]<arr[i])
               {
                   f.arr[i]=-arr[i]+10+b.arr[i];
                   z=1;
               }
               else
               {
                   f.arr[i]=-arr[i]+b.arr[i];
               }
           }



        }

    }

return f;
}


ClntN ClntN :: operator-(const ClntN&b)
{
   ClntN r;
   bool h,z=0, d=0;
    if(b.n!=n)
    {
        cout<<"Error! Different length..."<<endl;
        throw 1;
    }
    else{}
    if(b.n==0 || n==0)
    {
        cout<<"Error! Zero length..."<<endl;
        throw 1;
    }
    ClntN f;
    f.s=s;
    f.n=n;
    f.arr=new int[n];
    if(!b.s==s)
    {
        for(int i=n-1; i>=0; i--)
        {
            if(d==1)
                {
                    f.arr[i]=1;
                    d=0;
                }
                else f.arr[i]=0;
            f.arr[i]=f.arr[i]+(arr[i]+b.arr[i])%10;
            if ((arr[i]+b.arr[i])/10==1)
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
            if(arr[i]!=b.arr[i])
            {
                if(arr[i]>b.arr[i])
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
                   arr[i]=arr[i]-1;
                   z=0;
               }
               if(arr[i]<b.arr[i])
               {
                   f.arr[i]=arr[i]+10-b.arr[i];
                   z=1;
               }
               else
               {
                   f.arr[i]=arr[i]-b.arr[i];
               }
           }

        }
        if(h==false)
        {
           f.s=!b.s;
           for(int i=n-1; i>=0; i--)
           {
               if(z==1)
               {
                   z=0;
                   b.arr[i]=b.arr[i]-1;
               }
               if(b.arr[i]<arr[i])
               {
                   f.arr[i]=-arr[i]+10+b.arr[i];
                   z=1;
               }
               else
               {
                   f.arr[i]=-arr[i]+b.arr[i];
               }
           }



        }

    }

return f;
}



void ClntN :: CopyOnly(const bool r,const int m, const int* brr)
{
    n=m;
    s=r;
    arr=new int[n];
    for(int i=0; i<n; i++)
    {
        if(brr[i]>=0 && brr[i]<10)
            arr[i]=brr[i];
        else throw 4;
  }
}



 void ClntN :: CopyOnly(const ClntN &b)
 {
     n=b.n;
      s=b.s;
      arr=new int[n];
      for(int i=0; i<n; i++)
        {
            if(b.arr[i]>=0 && b.arr[i]<10)
            arr[i]=b.arr[i];
      else throw 2;
      }
}





