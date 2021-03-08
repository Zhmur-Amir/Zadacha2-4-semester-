#include "ClntN.h"
#include "ClntN1.h"
#include "ClntN0.h"
#include "wh.h"

ostream &operator<<(ostream &cout,  ClntN &s){s.print(); return cout;}

int PyatiletkyV4Goda(const char* FileName)
{
        string line;
        int j=0;
        ifstream file(FileName),file2(FileName);
        if(!file)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        while (getline(file,line))
        {
            j++;
        }
        if(j==0)
        {
            cout<<"Input is empty..."<<endl;
            return 2;
        }
        file.close();
        if(!file2)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        int u=0;
        string *str=new string[j];
        while (getline(file2,line))
        {
           str[u]=line;
           u++;
        }
        file2.close();


        ClntN **arr=new ClntN*[j];
        CFactory stln;
        for (int i=0, r=1; i<j; i++)
        {
            arr[i]=CCreate(str[i], stln,r);
            r++;
        }

        for(int i=0;i<j;i++)
        {
            arr[i]->output();
        }
        delete[] arr;
        delete[] str;
        str=NULL;
        arr=NULL;
        return 0;

}

ClntN* CCreate(string str,CFactory stln, int r)
{
  bool b, znak;
  if(str[0]=='1')
  {
      b=true;
  }
  else
  {
     if(str[0]=='0')
     {
         b=false;
     }
     else
     {
         if(str[0]!='1' || str[1]!=' ' ||str[2]==' ' )
      {
          cout<<"Input Syntax Error!"<<endl;
           exit (-4);
      }
      else
      {
         cout<<"Input Syntax Error!"<<endl;
           exit (-4);
      }
     }

  }
   int j=2;
   while(str[j]!=' ')
   {
      j++;
   }

   char* filename=new char[j-2];
   for(int i=0;i<j-2;i++)
   {
       filename[i]=str[i+2];
   }
   if(str[j]!=' '||str[j+1]==' ')
      {
          cout<<"Input Syntax Error!2"<<endl;
           exit (-5);
      }
      filename[j-2]='\0';
    if(str[j+1]=='+')
    {
        znak=true;
    }
    else
    {
        if(str[j+1]=='-')
        {
            znak=false;
        }
        else
        {
           cout<<"Input Syntax Error3!"<<endl;
           exit (-6);
        }

    }
    if(znak==true)
        {
            cout<<r<<") "<<b<<" "<<filename<<" + ";
        }
        else
        {
            cout<<r<<") "<<b<<" "<<filename<<" - ";
        }

    int* num=new int[str.size()-j-2];
    for(int i=0; i<str.size()-j-2;i++)
    {
        num[i]=static_cast<char>(str[i+j+2])-48;
        cout<<num[i];
    }
    cout<<endl;
    if (b==false)
    {
        ClntN* d;
        d=stln.Create0(znak, str.size()-j-2,num, filename);
        delete[] num;
        return d;
    }
    else
    {
        ClntN* g;
        g=stln.Create1(znak,str.size()-j-2 ,num, filename);
        delete[] num;
        return g;
    }


}






