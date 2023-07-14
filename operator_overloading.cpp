#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

class Point
{
    int x,y;

    public:
        Point(int x=0, int y=0)
        {
            this->x=x, this->y=y;
        }

        void display()
        {
            cout<<'('<<x<<','<<y<<')'<<endl;
        }

        double operator-(Point &a)
        {
            return sqrt((this->x-a.x)*(this->x-a.x)+(this->y-a.y)*(this->y-a.y));
        }

        bool sign(int x)
        {
            if(x<0) return false;
            return true;
        }

        int quadrant()
        {
            if(this->x>=0 and this->y>=0) return 1;
            else if(this->x<0 and this->y>=0) return 2;
            else if(this->x<0 and this->y<0) return 3;
            return 4;
        }

        bool operator>(Point &a)
        {
            if(sign(this->x)==sign(a.x) and sign(this->y)==sign(a.y)) return (this->x==a.x)? this->y>a.y:this->x>a.x;
            return this->quadrant()<a.quadrant();
        }

        Point& operator*=(int a)
        {
            this->x*=a, this->y*=a;
            return *this;
        }
};

class Student
{
    string name;
    int roll;
    double mark;

    public:
        Student(string name="", int roll=0, double mark=-1)
        {
            this->name=name, this->roll=roll, this->mark=mark;
        }

        void display()
        {
            cout<<name<<" "<<roll<<" "<<mark<<endl;
        }

        Student operator++(int a)
        {
            Student temp=*this;
            for(int i=0;i<name.size();++i)
            {
                switch(name[i])
                {
                    case 'z': name[i]='a';
                    case 'Z': name[i]='A';
                    default: name[i]=++name[i];
                }
            }
            return temp;
        }

        char& operator[](int i)
        {
            return name[i];
        }

        friend Student& operator++(Student &a);
};

Student& operator++(Student &a)
{
    for(int i=0;i<a.name.size();++i)
    {
        switch(a.name[i])
        {
            case 'z': a.name[i]='a';
            case 'Z': a.name[i]='A';
            default: a.name[i]=++a.name[i];
        }
    }
    return a;
}

int main()
{

    Point a(1,2);
    a*=2;
    a.display();
    return 0;
}