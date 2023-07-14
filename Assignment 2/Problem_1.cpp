#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

class Toyota
{
    string model_name, mode_color;
    int model_year;

    public:
        Toyota();
        Toyota(string model_name,string mode_color, int model_year);

        string get_name();
        string get_color();
        int get_year();
        
        void set_name(string name);
        void set_color(string color);
        void set_year(int year);

        bool same_car(Toyota car);
};


//////////////////////////////////////////////////////////////////////////////////////
Toyota::Toyota()
{
    this->mode_color=this->model_name="not_set";
    this->model_year=-1;
}

Toyota::Toyota(string model_name,string mode_color, int model_year)
{
    this->mode_color=mode_color;
    this->model_name=model_name;
    this->model_year=model_year;
}

string Toyota::get_name()
{
    return this->model_name;
}

string Toyota::get_color()
{
    return this->mode_color;
}

int Toyota::get_year()
{
    return this->model_year;
}

void Toyota::set_name(string name)
{
    this->model_name=name;
}

void Toyota::set_color(string color)
{
    this->mode_color=color;
}

void Toyota::set_year(int year)
{
    this->model_year=year;
}

bool Toyota::same_car(Toyota car)
{
    return this->mode_color==car.mode_color and this->model_name==car.model_name and this->model_year==car.model_year;
}
//////////////////////////////////////////////////////////////////////////////////////

int main()
{
    cout<<"Number of Cars: ";
    int n, year=-1; cin>>n;
    string temp="not_set";
    Toyota car[n];

    for(int i=0;i<n;++i)
    {
        cout<<"Car "<<i+1<<endl;
        cout<<"Car Model: "; cin>>temp, car[i].set_name(temp);
        cout<<"Car Color: "; cin>>temp, car[i].set_color(temp);
        cout<<"Manufacture Year: "; cin>>year, car[i].set_year(year);
        cout<<endl;
    }

    cout<<"Number of inquiries: ";
    int query, id1, id2; cin>>query;

    for(int i=0;i<query;++i)
    {
        cout<<"Enter the indices of the Cars in consideration: "; cin>>id1>>id2;
        cout<<((car[id1].same_car(car[id2]))? "Same Car":"Diffent Car")<<endl;
    }
    return 0;
}