#include "wh.h"


ostream &operator<<(ostream &cout,  ClntN &s){s.print(); return cout;}

int PyatiletkyV4Goda(const string FileName)
{
        string line;
        int j=0;
        vector<string> temp;
        ifstream file(FileName);
        if(!file)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        while (getline(file,line))
        {
            j++;
            temp.push_back(line);
        }
        if(j==0)
        {
            cout<<"Input is empty..."<<endl;
            return 2;
        }
        file.close();
        string *str=new string[j];
        for (int u=0; u<j; u++)
        {
           str[u]=temp[u];
        }
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
            delete (*it);
            (*it)=NULL;
        }
        delete[] str;
        str=NULL;

        return 0;

}



ClntN* CCreate(string str, int r)
{
    bool znak;
    string zn;
    map<string, CFactory*>F;
    F["Hori"]=new CFactory0();
    F["Vert"]=new CFactory1();
    stringstream Stream;
    Stream<<str;
    string Type, filename, number;
    Stream>>Type;
    Stream>>filename;
    Stream>>number;
    if(number[0]=='+')
    {
        znak=true;
    }
    else
    {
        if(number[0]=='-')
        {
            znak=false;
        }
        else
        {
           cout<<"Input Syntax Error!"<<endl;
           exit (-6);
        }

    }
    if(znak==true)
        {
            zn="+";
        }
        else
        {
           zn="-" ;
        }

    cout<<r<<") "<<Type<<" "<<filename<<" "<<zn;

    vector<int> num;
    num.resize(number.size()-1);
    int i=0;
for(vector<int>::iterator it=num.begin(); it!=num.end(); ++it)
{
    *it=static_cast<char>(number[i+1])-48;
    i++;
    cout<<*it;
}
    cout<<endl;



    auto curfabric=F.find(Type);
    if (curfabric==F.end())
    {
        cout<<"Input Syntax Error!"<<endl;
        exit (-4);
    }
    else
    {
        ClntN* product;
        product=curfabric->second->Create(znak, number.size()-1 ,num, filename);
        return product;
    }

}















