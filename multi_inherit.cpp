#include<bits/stdc++.h>
using namespace std;

class Person
{
    string id;

    protected:
        string email;

    public:
        string name;

        Person(string id="", string email="", string name="")
        {
            this->id=id, this->name=name, this->email=email;
        }

        string get_id()
        {
            return id;
        }

        void display()
        {
            cout<<"Name: "<<name<<endl<<"ID: "<<id<<endl<<"Email: "<<email<<endl;
        }
};

class Student : protected Person
{
    double gpa;

    protected:
        int fees;
    
    public:
        Student(double gpa, int fees, string id, string email, string name): Person(id,email,name)
        {
            this->gpa=gpa, this->fees=fees;
        }

        int get_fees()
        {
            return fees;
        }

        void display1()
        {
            cout<<"GPA: "<<gpa<<endl<<"Fees: "<<fees<<endl;
        }

        void display()
        {
            Person::display();
            cout<<"GPA: "<<gpa<<endl<<"Fees: "<<fees<<endl;
        }
};

class Employee: public Person
{
    int basic_salary;

    protected:  
        int bonus;
    
    public:
        Employee(int bs, int bonus, string id, string email, string name): Person(id,email,name)
        {
            this->basic_salary=bs, this->bonus=bonus;
        }

        int get_sal()
        {
            return basic_salary+bonus;
        }

        void display()
        {
            Person::display();
            cout<<"Basic Salary: "<<basic_salary<<endl<<"Bonus: "<<bonus<<endl;
        }
};


class Staff_offcier : public Student, public Employee
{
    protected:
        string designation;

    public:
        Staff_offcier(string designation, double gpa, int fees, string id, string email, string name, int bs, int bonus): Student(gpa,fees,id,email,name), Employee(bs,bonus,id,email,name)
        {
            this->designation=designation;
        }

        int get_sal()
        {
            return Employee::get_sal()-fees;
        }

        void display()
        {
            Employee::display();
            Student::display1();
            cout<<"Designation: "<<designation<<endl<<"Salary: "<<get_sal()<<endl;
            //cout<<this->email<<endl;
        }
};

class PG_Student : private Student
{
    int thesis_mark;

    public:
        PG_Student(int tm, double gpa, int fees, string id, string email, string name): Student(gpa,fees,id,email,name)
        {
            this->thesis_mark=tm;
        }

        void display()
        {
            Student::display();
            cout<<"Thesis Marks: "<<thesis_mark<<endl;
        }
};

int main()
{
    Person p1("202114003","Magic.com","Abrar");
    p1.display();

    Staff_offcier s1("Hawker",3.95,8000,"202114003","murgi@gmail.com","Shahensha",10,5);
    s1.display();
    cout<<endl;

    PG_Student p(99,3.98,95000,"202114003","gmail.com","Abrar");
    p.display();
    return 0;
}