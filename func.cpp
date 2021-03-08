#include "wh.h"


ostream &operator<<(ostream &cout,  ClntN &s){s.print(); return cout;}

int PyatiletkyV4Goda(const string FileName)
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
        vector<ClntN*> arr;
        arr.resize(j);
        int r=1, i=0;
        for(vector<ClntN*>::iterator it=arr.begin(); it!=arr.end(); ++it)
        {
            *it=CCreate(str[i],r);
            r++;
            i++;
        }
        for(vector<ClntN*>::iterator it=arr.begin(); it!=arr.end(); ++it)
        {
            (*it)->output();
        }
        delete[] str;
        str=NULL;
        return 0;

}

ClntN* CCreate(string str, int r)
{
  bool b, znak;
  if(str[0]=='V' && str[1]=='e'&& str[2]=='r'&& str[3]=='t' )
  {
      b=true;
  }
  else
  {
     if(str[0]=='H'&& str[1]=='o'&&str[2]=='r'&& str[3]=='i')
     {
         b=false;
     }
     else
     {
         if(str[4]!=' ' || str[5]==' ' )
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
   int j=5;
   while(str[j]!=' ')
   {
      j++;
   }
   string filename;
   filename.resize(j-5);

   filename=str.substr(5,j-5);
   if(str[j]!=' '||str[j+1]==' ')
      {
          cout<<"Input Syntax Error!2"<<endl;
           exit (-5);
      }
    filename[j-5]='\0';
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
    string vid, zn;
    if(b==true)
        {
            vid="Vert";
        }
        else
        {
           vid="Hori" ;
        }
    if(znak==true)
        {
            zn="+";
        }
        else
        {
           zn="-" ;
        }
    cout<<r<<") "<<vid<<" "<<filename<<" "<<zn;
    vector<int> num;
    num.resize(str.size()-j-2);
    int i=0;
for(vector<int>::iterator it=num.begin(); it!=num.end(); ++it)
{
    *it=static_cast<char>(str[i+j+2])-48;
    i++;
    cout<<*it;
}
    cout<<endl;
    map<string, CFactory*>F;
    F["f0"]=new CFactory0();
    F["f1"]=new CFactory1();
    if (b==false)
    {
        ClntN* d;
        d=F["f0"]->Create(znak, str.size()-j-2,num, filename);
        return d;
    }
    else
    {
        ClntN* g;
        g=F["f1"]->Create(znak,str.size()-j-2 ,num, filename);
        return g;
    }


}



