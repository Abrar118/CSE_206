#include<bits/stdc++.h>
//#include "utility.h"
#define endl "\n"
#define tab "\t"
#define pq priority_queue
#define in long long
#define dub double
#define dubb long double
const in modv=998244353;
using namespace std;


class Person
{
    string contact;
 
    protected:
        string designation;
    public:
        Person(string full_name="", string id="", string contact="", string designation="")
        {
            this->full_name=full_name, this->id=id, this->contact=contact, this->designation=designation;
        }
 
        string full_name, id;
 
        virtual int get_sal()=0;
};
 
class Employee: public Person
{
    int basic_sal;
    
    protected:
        int bonus;

    public:
        Employee(int basic_sal=0, int bonus=0, string name="", string id="", string contact="", string desig=""): Person(name, id, contact, desig)
        {
            this->basic_sal=basic_sal, this->bonus=bonus;
        }
 
        int get_sal()
        {
            return basic_sal+bonus;
        }
 
};
 
class Operator: public Employee
{
    int overtime_rate, overtime_hour;
 
    public:
        Operator(int overtime_rate=0, int overtime_hour=0, int basic_sal=0, int bonus=0, string name="", string id="", string contact="", string desig=""): Employee(basic_sal, bonus, name, id, contact, desig)
        {
            this->overtime_hour=overtime_hour;
            this->overtime_rate=overtime_rate;
        }
 
        int get_sal()
        {
            return Employee::get_sal()+(overtime_hour*overtime_rate);
        }
};
 
void print_sal(Person* p)
{
    cout<<"Salary of "<<p->full_name<<", Id: "<<p->id<<", is "<<p->get_sal()<<endl;
}
 
int main()
{
    Operator* ami;
    ami=new Operator(1000, 50, 40000, 12000, "Abrar", "202114003", "01553456456", "General Manager");
    print_sal(ami);
    return 0;
}