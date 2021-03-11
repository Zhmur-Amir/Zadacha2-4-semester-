#include "wh.h"

void Autotest(void)
{
     cout<<"Starting Autotest 1:"<<endl;
     vector<int> m={9,0,0};
     vector<int> k={0,0,1};
     ClntN0 a(true,3,m),b(false,3,k),d,c,u(true,3,m),h(false,3,k);
     c=a+b;
     d=u-h;
     if (c.sign()==true && c[0]==8 && c[1]==9 && c[2]==9 && d[0]==9 && d[1]==0 && d[2]==1 && d.sign()==true )
     {
         cout<<"Autotest passed! respect+"<<endl;
     }
     else
     {
         cout<<"Autotest failed! Wasted..."<<endl;
     }
     cout<<endl<<"============================="<<endl;


}


int Auto(void)
{
    cout<<endl<<"Starting Autotest 2:"<<endl<<endl;
    ofstream out1("Auto1.txt"), out2("Auto0.txt");
    if(!out1 || !out2)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
    out1.close();
    out2.close();
    PyatiletkyV4Goda("Auto.txt");
    string line,line4;
        int j=0;
        ifstream file("Auto1.txt"),file2("Auto1.txt");
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




        ifstream file3("Auto0.txt"),file4("Auto0.txt");
        if(!file4)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        j=0;
        while (getline(file4,line4))
        {
            j++;
        }
        if(j==0)
        {
            cout<<"Input is empty..."<<endl;
            return 2;
        }
        file4.close();
        if(!file3)
        {
            cout<<"Error! Cannot open file..."<<endl;
            return -1;
        }
        u=0;
        string *line1=new string[j];
        while (getline(file3,line))
        {
           line1[u]=line;
           u++;
        }
        file3.close();





     if (str[0]=="+" && str[1]=="1" && str[2]=="2" &&str[3]=="3"&&
         str[5]=="-" && str[6]=="8" && str[7]=="9" &&str[8]=="4" && line1[0]=="-234" && line1[1]=="+976" )
     {
         cout<<endl<<"Autotest passed! respect+"<<endl;
     }
     else
     {
         cout<<endl<<"Autotest failed! Wasted..."<<endl;
     }
     cout<<endl<<"============================="<<endl;
return 0;
}

