#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

class Complex_Number
{
    int real, imaginary;

    public:
        Complex_Number()
        {
            this->real=this->imaginary=0;
        }

        Complex_Number(int real,int imaginary)
        {
            this->real=real, this->imaginary=imaginary;
        }

    friend double abs(Complex_Number a);
    friend class Calculator;
};

class Calculator
{
    public:
        void add(Complex_Number a, Complex_Number b)
        {
            if(a.real+b.real) cout<<a.real+b.real;
            cout<<((a.real+b.real and a.imaginary+b.imaginary>0)? "+":(a.real+b.real and (a.imaginary+b.imaginary))? "-":"");
            if(a.imaginary+b.imaginary)
            {
                if(abs(a.imaginary+b.imaginary)==1) cout<<'i'<<endl<<endl;
                else cout<<abs(a.imaginary+b.imaginary)<<'i'<<endl<<endl;
            }
        }

        void subt(Complex_Number a, Complex_Number b)
        {
            if(a.real-b.real) cout<<a.real-b.real;
            cout<<((a.real-b.real and a.imaginary-b.imaginary>0)? "+":(a.real-b.real and (a.imaginary-b.imaginary))? "-":"");
            if(a.imaginary-b.imaginary)
            {
                if(abs(a.imaginary-b.imaginary)==1) cout<<'i'<<endl<<endl;
                else cout<<abs(a.imaginary-b.imaginary)<<'i'<<endl<<endl;
            }
        }

        void mult(Complex_Number a, Complex_Number b)
        {
            int part1=(a.real*b.real)-(a.imaginary*b.imaginary);
            int part2=(a.imaginary*b.real)+(a.real*b.imaginary);

            if(part1) cout<<part1;
            cout<<((part2>0)? "+":(part2)? "-":"");
            if(part2)
            {
                if(abs(part2)==1) cout<<'i'<<endl<<endl;
                else cout<<abs(part2)<<'i'<<endl<<endl;
            }
        }
};

double abs(Complex_Number a)
{
    return sqrt(a.real*a.real+a.imaginary*a.imaginary);
}

int main()
{

    Complex_Number A(1,2), B(-1,3);
    cout<<"Modulus of A: "<<abs(A)<<endl;
    cout<<"Modulus of B: "<<abs(B)<<endl<<endl;

    Calculator casio;

    cout<<"A+B: "; casio.add(A,B);
    cout<<"A-B: "; casio.subt(A,B);
    cout<<"B-A: "; casio.subt(B,A);
    cout<<"A x B: "; casio.mult(A,B);

    return 0;
}