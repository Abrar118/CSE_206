#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int current_user_id=-1, total_user;

class Holder
{
    string name, password;
    int balance;

    public:
        Holder();
        Holder(string name, string password, int balance);

        string get_name();
        string get_pass();
        int get_balance();

        void set_name(string name);
        void set_pass(string pass);
        void set_balance(int balance);
};

Holder user[100];

inline void menu_before_log_in()
{
    cout<<"Select and operation from the following: "<<endl;
    cout<<"1. Log in"<<endl;
    cout<<"2. Create An Account"<<endl;
    cout<<"3. Quit The Program"<<endl<<endl;
}

inline void menu_after_log_in()
{
    cout<<"Select and operation from the following: "<<endl;
    cout<<"1. Withdraw Money"<<endl;
    cout<<"2. Deposit Money"<<endl;
    cout<<"3. Request Balance"<<endl;
    cout<<"4. Quit the program"<<endl<<endl;
}

void log_in();
void sign_up();
void withdraw();
void deposit();
void req_balance();

int main()
{
    int choice;

    while(true)
    {
        if(current_user_id==-1) menu_before_log_in();
        else menu_after_log_in();

        cout<<">>> "; cin>>choice;

        if(current_user_id==-1)
        {
            if(choice==3) break;
            switch(choice)
            {
                case 1: log_in(); break;
                case 2: sign_up(); break;
            }
        }
        else
        {
            if(choice==4) break;
            switch(choice)
            {
                case 1: withdraw(); break;
                case 2: deposit(); break;
                case 3: req_balance(); break;
            }
        }
    }
    return 0;
}


////////////////////////////////////////////////////////////////////////
Holder::Holder()
{
    this->balance=0, this->name=this->password="none";
}

Holder::Holder(string name, string password, int balance)
{
    this->balance=balance, this->name=name, this->password=password;
}

string Holder::get_name()
{
    return this->name;
}

string Holder::get_pass()
{
    return this->password;
}

int Holder::get_balance()
{
    return this->balance;
}

void Holder::set_balance(int balance)
{
    this->balance=balance;
}

void Holder::set_name(string name)
{
    this->name=name;
}

void Holder::set_pass(string password)
{
    this->password=password;
}
////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////

void log_in()
{
    if(current_user_id!=-1) cout<<"Already Logged Into An Account"<<endl<<endl;
    else
    {
        string name, pass;
        cout<<"User Name: "; cin>>name;
        cout<<"Password: "; cin>>pass;

        bool permission=false;

        for(int i=0;i<total_user;++i)
        {
            if(user[i].get_name()==name and user[i].get_pass()==pass)
            {
                permission=true, current_user_id=i; break;
            }
        }

        if(permission) cout<<"******** ACCESS GRANTED ********"<<endl<<endl;
        else cout<<"******** ACCESS DENIED ********"<<endl<<endl;
    }
}

void sign_up()
{
    if(current_user_id!=-1) cout<<"Log Out First"<<endl<<endl;
    else
    {
        string name, pass;
        cout<<"User name: "; cin>>name;
        cout<<"Password: "; cin>>pass;

        user[total_user].set_name(name);
        user[total_user++].set_pass(pass);

        cout<<"Your Account Has Been Successfully Created"<<endl<<endl;
    }
}

void withdraw()
{
    int balance, amount;
    cout<<"Amount to be withdrawn: "; cin>>balance;
    if(balance<=user[current_user_id].get_balance())
    {
        amount=user[current_user_id].get_balance()-balance;
        user[current_user_id].set_balance(amount);
        cout<<"Withdraw Successful"<<endl<<endl;
    }
    else cout<<"Insufficient Balance"<<endl<<endl;
}

void deposit()
{
    int balance, amount;
    cout<<"Amount of deposit: "; cin>>balance;

    amount=user[current_user_id].get_balance()+balance;
    user[current_user_id].set_balance(amount);
    cout<<"Deposit Successful"<<endl<<endl;
}

void req_balance()
{
    cout<<"Your current balance is $"<<user[current_user_id].get_balance()<<endl<<endl;
}
///////////////////////////////////////////////////////////////////////////////