#include<bits/stdc++.h>
//#include "utility.h"
#define endl "\n"
#define tab "\t"
#define pq priority_queue
#define in long long
#define dub double
#define dubb long double
using namespace std;

void one()
{
    int n; cin>>n;
    char c; cin>>c;
    for(int i=0;i<n;++i)
    {
        for(int k=0;k<i;++k) cout<<c<<" ";
        cout<<endl;
    }
}

string string_add(string s,string ss)
{
    string sss;
    int n=s.size(), ns=ss.size();
    int p1=n-1,p2=ns-1,carry=0,x,y;
    while(p1>=0 or p2>=0)
    {
        x=(p1<0)? 0:s[p1]-48;
        y=(p2<0)? 0:ss[p2]-48;
        sss.push_back(48+(x+y+carry)%10);
        carry=((x+y+carry)>9)? 1:0;
        --p1, --p2;
    }
    if(carry>0) sss.push_back(48+carry);
    reverse(sss.begin(),sss.end());
    return sss;
}

string multi(string s,string ss)
{
    string sss;
    vector<string>a;
    int x,y,carry;
    for(int i=ss.size()-1;i>-1;--i)
    {
        x=ss[i]-48; carry=0;
        for(int k=s.size()-1;k>-1;--k)
        {
            y=s[k]-48;
            sss.push_back(48+(x*y+carry)%10);
            carry=(x*y+carry)/10;
        }
        if(carry>0) sss.push_back(48+carry);
        reverse(sss.begin(),sss.end());
        for(int x=0;x<ss.size()-i-1;++x) sss.push_back('0');
        a.push_back(sss);
        sss.clear();
    }
    sss=a[0];
    for(int i=1;i<a.size();++i) sss=string_add(sss,a[i]);
    return sss;
}

void two()
{
    string s,ss,sss; cin>>s>>ss;
    sss=string_add(s,ss);
    cout<<sss;
}

struct order
{
    string OrderId,CustomerName;
    double OrderPrice;

    void SetOrderId()
    {
        for(int i=0;i<8;++i)
        {
            char c=rand()%26+65;
            char c1=rand()%26+97;
            int x=rand()%2;
            if(x==0) OrderId.push_back(c);
            else OrderId.push_back(c1);
        }
    }

    void SetCustomerName(string s)
    {
        CustomerName=s;
    }

    void SetOrderPrice(double y)
    {
        OrderPrice=y;
    }

    void print()
    {
        cout<<"Order ID: "<<OrderId<<endl;
        cout<<"Ordered By: "<<CustomerName<<endl;
        cout<<"Price: "<<OrderPrice<<" TK"<<endl;
    }
};

void four()
{
    int n; cout<<"Number of orders: "; cin>>n;
    order rest[n];
    for(int i=0;i<n;++i)
    {
        string name; cin>>name;
        double price; cin>>price;
        rest[i].SetOrderId();
        rest[i].SetCustomerName(name);
        rest[i].SetOrderPrice(price);
    }

    bool state;
    for(int i=0;i<n-1;i++)
    {
        state=false;
        for(int k=0;k<n-i-1;k++)
        {
            if(rest[k].CustomerName<rest[k+1].CustomerName)
            {
                swap(rest[k],rest[k+1]), state = true;
            }
        }
        if(!state) break;
    }
    cout<<endl;
    for(int i=0;i<n;++i) rest[i].print(), cout<<endl;
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL);

    srand((unsigned int)time(NULL));
    
    string s,ss; cin>>s>>ss;
    cout<<multi(s,ss)<<endl<<string_add(s,ss);
    return 0;
}