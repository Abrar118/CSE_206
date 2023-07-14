#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

class Commerce_Student;

class Science_Student
{
    int roll, primary_subject[5], science_subject[5];
    
    public:
        Science_Student();
        Science_Student(int roll,int primary_marks[],int science_marks[]);
    
    friend int compare(Science_Student a, Commerce_Student b);
};

class Commerce_Student
{
    int roll, primary_subject[5], commerce_subject[5];

    public:
        Commerce_Student();
        Commerce_Student(int roll,int primary_marks[],int commerce_marks[]);

    friend int compare(Science_Student a, Commerce_Student b);
};

//////////////////////////////////////////////////////////////////////////////
Science_Student::Science_Student()
{
    this->roll=0;
    for(int i:primary_subject) i=0;
    for(int i:science_subject) i=0;
}

Science_Student::Science_Student(int roll,int primary_marks[],int science_marks[])
{
    this->roll=roll;
    for(int i=0;i<5;++i) this->primary_subject[i]=primary_marks[i];
    for(int i=0;i<5;++i) this->science_subject[i]=science_marks[i];
}

Commerce_Student::Commerce_Student()
{
    this->roll=0;
    for(int i:primary_subject) i=0;
    for(int i:commerce_subject) i=0;
}

Commerce_Student::Commerce_Student(int roll,int primary_marks[],int commerce_marks[])
{
    this->roll=roll;
    for(int i=0;i<5;++i) this->primary_subject[i]=primary_marks[i];
    for(int i=0;i<5;++i) this->commerce_subject[i]=commerce_marks[i];
}
/////////////////////////////////////////////////////////////////////////////////////

int compare(Science_Student a, Commerce_Student b)
{
    double av_a, av_b, sum=0;
    
    for(int i=0;i<5;++i) sum+=a.primary_subject[i];
    for(int i=0;i<5;++i) sum+=a.science_subject[i];
    av_a=sum/10;

    sum=0;
    for(int i=0;i<5;++i) sum+=b.primary_subject[i];
    for(int i=0;i<5;++i) sum+=b.commerce_subject[i];
    av_b=sum/10;

    if(av_a>av_b) return a.roll;
    else if(av_a<av_b) return b.roll;
    return -1;
}

int main()
{
    int primary_mark_science[]={100,90,95,91,98}, science_mark[]={99,100,98,97,95};
    Science_Student Abrar(202114003, primary_mark_science, science_mark);

    int primary_mark_commerce[]={100,100,100,96,92}, commerce_mark[]={91,88,98,99,100};
    Commerce_Student Mahir(202114001, primary_mark_commerce, commerce_mark);

    if(compare(Abrar,Mahir)==-1) cout<<"Equal average mark";
    else cout<<"ID "<<compare(Abrar, Mahir)<<" has higher average mark";
    return 0;
}