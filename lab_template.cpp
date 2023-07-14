#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

template<typename type>bool comp(type a, type b)
{
    return a>b;
}

template<typename type, bool (func)(type a,type b)> type add(type a, type b)
{
    bool ans=func(a,b);
    if(ans) return a+b;
    return a+b+1;
}

class point
{
    int x,y;
    
    public:
        point(int x=0,int y=0)
        {
            this->x=x, this->y=y;
        }

        point* shift(int dx,int dy)
        {
            this->x+=dx, this->y+=dy;
            return this;
        }

        void print()
        {
            cout<<'{'<<x<<','<<y<<'}'<<endl;
        }

};

class complex
{
    int r, i;
    public:
        complex(int r=0, int i=0)
        {
            this->r=r, this->i=i;
        }

        complex operator+(complex &a)
        {
            complex ans; 
            ans.r=a.r+this->r;
            ans.i=this->i+a.i;
            return ans;
        }

        void print()
        {
            cout<<this->r<<"+"<<this->i<<"i"<<endl;
        }
};

int main()
{
    // complex a1(6,2), b1(3,4);
    // complex c=a1+b1;
    // c.print();

    // int a=add<int,comp>(2,1);
    // cout<<a;

    point a(1,2);
    point* b=a.shift(3,4);
    b->print();
    return 0;
}