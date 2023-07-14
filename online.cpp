#include<bits/stdc++.h>
#define endl "\n"
#define in long long
#define dub double
#define tab "\t"
#define pq priority_queue
const in modv=998244353;
using namespace std;

class Account;

class User
{
    char* id;
    char* name;

    public:
        User(char* id, char* name)
        {
            this->id=new char[strlen(id)+1];
            strcpy(this->id,id);

            this->name=new char[strlen(name)+1];
            strcpy(this->name,name);
        }

        ~User()
        {
            delete[] id;
            delete[] name;
        }

        friend class Account;
};


class Account
{
    User* user;
    char* phone;
    int* balance;

    public:
        Account(char* id, char* name, char* phone)
        {
            this->user=new User(id,name);

            this->phone=new char[strlen(phone)+1];
            strcpy(this->phone,phone);

            this->balance=new int(500);
        }

        Account(const Account &x)
        {
            this->user=new User(x.user->id,x.user->name);

            this->phone=new char[strlen(x.phone)+1];
            strcpy(this->phone,x.phone);

            this->balance=new int(*x.balance);
        }

        void set_id(char* x)
        {
            char* n_id=this->user->id;
            this->user->id=new char[strlen(x)+1];
            strcpy(this->user->id,x);

            delete[] n_id;
        }

        void set_name(char* x)
        {
            char* n_name=this->user->name;
            this->user->name=new char[strlen(x)+1];
            strcpy(this->user->name,x);

            delete[] n_name;
        }

        void set_phone(char* x)
        {
            char* n_phone=this->phone;
            this->phone=new char[strlen(x)+1];
            strcpy(this->phone,x);

            delete[] n_phone;
        }

        void print()
        {
            cout<<"ID: "<<this->user->id<<", Name: "<<this->user->name<<", Phone: "<<this->phone<<", Balance: "<<*this->balance<<endl;
        }

        ~Account()
        {
            delete this->user;
            delete[] this->phone;
            delete this->balance;
        }

        friend void transfer_monet(int i,int j,int amount);
};

Account acc[4]={Account("10", "Rafi", "010"), Account("15", "Binita", "015"), Account("29", "Nabil", "029"), Account("36", "Maisha", "036")};

void transfer_monet(int i,int j,int amount)
{
    string a=acc[i].phone, b=acc[j].phone;
    if(a!=b)
    {
        if(*acc[i].balance>=amount)
        {
            *acc[i].balance-=amount, *acc[j].balance+=amount;
            cout<<"Transaction Successful"<<endl;
        }
        else cout<<"Insufficient balance"<<endl;
    }
    else cout<<"Invalid transaction"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    Account admin=acc[0];
    admin.set_id("A-11");
    admin.set_name("Admin");
    admin.set_phone("01511");

    transfer_monet(2, 0, 100);
    transfer_monet(1, 0, 150);
    transfer_monet(1, 1, 100);
    transfer_monet(2, 3, 800);

    for(int i=0;i<4;++i) acc[i].print();
    admin.print();
    return 0;
}