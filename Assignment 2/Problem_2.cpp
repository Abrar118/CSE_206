#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

class Clock_time
{
    int hr, min, sec;

    public:
        Clock_time();
        Clock_time(int hr, int min, int sec);

        int get_hour();
        int get_min();
        int get_sec();

        void set_hour(int hr);
        void set_min(int min);
        void set_sec(int sec);

        void time_difference(Clock_time t);
};

///////////////////////////////////////////////////////////////////////////////////////////
Clock_time::Clock_time()
{
    this->hr=this->min=this->sec=0;
}

Clock_time::Clock_time(int hr, int min, int sec)
{
    this->hr=hr, this->min=min, this->sec=sec;
}

int Clock_time::get_hour()
{
    return this->hr;
}

int Clock_time::get_min()
{
    return this->min;
}

int Clock_time::get_sec()
{
    return this->sec;
}

void Clock_time::set_hour(int hr)
{
    this->hr=hr;
}

void Clock_time::set_min(int min)
{
    this->min=min;
}

void Clock_time::set_sec(int sec)
{
    this->sec=sec;
}

void Clock_time::time_difference(Clock_time t)
{
    int h1, m1, s1;
    int h2, m2, s2;

    if(this->hr>t.hr) h1=this->hr, m1=this->min, s1=this->sec, h2=t.hr, m2=t.min, s2=t.sec;
    else h2=this->hr, m2=this->min, s2=this->sec, h1=t.hr, m1=t.min, s1=t.sec;

    int carry_sec=0, carry_min=0, carry_hr=0;
    int new_hr, new_min, new_sec;

    if(s1>=s2) new_sec=s1-s2;
    else new_sec=(s1+60)-s2, carry_sec=1;

    if(m1>=m2+carry_sec) new_min=m1-(m2+carry_sec);
    else new_min=(m1+60)-(m2+carry_sec), carry_min=1;

    if(h1>=h2+carry_min) new_hr=h1-(h2+carry_min);
    else new_hr=0, new_min=60-new_min, new_sec=60-new_sec;

    if(!new_hr and !new_min and !new_sec) cout<<"Clocks are in Sync"<<endl;
    else
    {
        if(new_hr) cout<<new_hr<<" Hours ";
        if(new_min) cout<<new_min<<" Minutes ";
        if(new_sec) cout<<new_sec<<" Seconds"<<endl;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int n,hr,min,sec;
    char colon;
    cout<<"Number of Cities: "; cin>>n;
    Clock_time cities[n];

    cout<<endl<<"Enter Local time in HH:MM:SS format: "<<endl;

    for(int i=0;i<n;++i)
    {
        cout<<"City "<<i+1<<" Local Time: "; cin>>hr>>colon>>min>>colon>>sec;
        cities[i].set_hour(hr), cities[i].set_min(min), cities[i].set_sec(sec);
    }

    cout<<endl<<"Number of queries: ";
    int q,city1, city2; cin>>q;

    while(q--)
    {
        cout<<endl<<"Enter indices of cities(2): "; cin>>city1>>city2;
        cities[city1].time_difference(cities[city2]);
        cout<<endl;
    }
    return 0;
}