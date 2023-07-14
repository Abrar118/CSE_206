#include<iostream>
#include<ctime>
#include<windows.h>
#include<fstream>
#define endl "\n"
#define tab "\t"
using namespace std;

bool logged_in;
int total_user, total_transaction[100], total_log_in,money, current_user_id=-1;
string current_user="none", name, mail, pass, history[1000], user_history[1000];

class User
{
    string mail,password,name;
    int balance;

    public:
        string get_mail();
        string get_pass();
        string get_name();
        int get_balance();

        void set_mail(string mail);
        void set_pass(string password);
        void set_name(string name);
        void set_balance(int balance);

        void print()
        {
            cout<<"Name: "<<get_name()<<endl;
            cout<<"Mail: "<<get_mail()<<endl;
            cout<<"Password: "; for(int i=0;i<get_pass().size();++i) cout<<'*';
            cout<<endl<<"Balance: "<<get_balance()<<" Taka"<<endl;
            cout<<endl<<endl;
        }
};

class Transaction
{
    string sender, receiver;
    int previous_balance, amount;

    public:
        string get_sender();
        string get_receiver();
        int get_previous_balance();
        int get_amount();

        void set_sender(string sender);
        void set_receiver(string receiver);
        void set_prev_balance(int previous_balance);
        void set_amount(int amount);
};

User customer[100];
Transaction bussniness[100][5000];

inline void menu()
{
    cout<<"1. Create new account"<<endl;
    cout<<"2. Sign in"<<endl;
    cout<<"3. Sign out"<<endl;
    cout<<"4. Reset Password"<<endl;
    cout<<"5. Send Money"<<endl;
    cout<<"6. View Transactions"<<endl;
    cout<<"7. View Customer List"<<endl;
    cout<<"8. Exit"<<endl;
    cout<<"9. View Logg in History"<<endl<<endl;
}

void from_txt();
void to_txt();

void create_account();
void sign_in();
void sign_out();
void reset_pass();
void send_money();
void view_transactions();
void view_customer_list();
void view_log_in_history();
string suggest_pass();

int main()
{
    srand((unsigned int)time(NULL));

    from_txt();

    int choice;

    while(true)
    {
        menu();

        if(logged_in) cout<<"Current User: "<<customer[current_user_id].get_name()<<endl<<endl;

        cout<<"Option: "; cin>>choice;
        if(choice==8) break;
        switch(choice)
        {
            case 1: create_account(); break;

            case 2: sign_in(); break;

            case 3: sign_out(); break;

            case 4: reset_pass(); break;

            case 5: send_money(); break;

            case 6: view_transactions(); break;

            case 7: view_customer_list(); break;
            
            case 9: view_log_in_history(); break;
        }
        Sleep(500);
    }

    to_txt();

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
///////User class functions' definitions
string User::get_mail()
{
    return mail;
}
string User::get_pass()
{
    return password;
}
string User::get_name()
{
    return name;
}
int User::get_balance()
{
    return balance;
}
void User::set_mail(string mail)
{
    this->mail=mail;
}
void User::set_pass(string password)
{
    this->password=password;
}
void User::set_name(string name)
{
    this->name=name;
}
void User::set_balance(int balance)
{
    this->balance=balance;
}
/////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////
//////transaction class' functions' defintions
string Transaction::get_sender()
{
    return sender;
}
string Transaction::get_receiver()
{
    return receiver;
}
int Transaction::get_previous_balance()
{
    return previous_balance;
}
int Transaction::get_amount()
{
    return amount;
}
void Transaction::set_sender(string sender)
{
    this->sender=sender;
}
void Transaction::set_receiver(string receiver)
{
    this->receiver=receiver;
}
void Transaction::set_prev_balance(int previous_balance)
{
    this->previous_balance=previous_balance;
}
void Transaction::set_amount(int amount)
{
    this->amount=amount;
}
//////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////
//////menu functions' definitions
void create_account()
{
    if(logged_in)
    {
        cout<<"Please sign out of "<<current_user<<" first"<<endl<<endl;
        return;
    }
    cout<<"Enter mail: "; cin>>mail;

    if(mail=="back")
    {
        cout<<endl; return;
    }

    cout<<"Enter password (suggested: "<<suggest_pass()<<" ): "; cin>>pass;

    if(pass=="back")
    {
        cout<<endl; return;
    }

    cout<<"Enter Name: "; cin>>name;

    if(name=="back")
    {
        cout<<endl; return;
    }

    customer[total_user].set_mail(mail);
    customer[total_user].set_pass(pass);
    customer[total_user].set_balance(500);
    bussniness[total_user][0].set_prev_balance(500);
    customer[total_user++].set_name(name);

    cout<<"Account created successfully"<<endl<<endl;
}

void sign_in()
{
    if(logged_in) cout<<"Already logged in, sign out first"<<endl<<endl;
    else
    {
        cout<<"Enter mail: "; cin>>mail;

        if(mail=="back")
        {
            cout<<endl; return;
        }

        cout<<"Enter password: "; cin>>pass;

        if(pass=="back")
        {
            cout<<endl; return;
        }

        bool permission=false;
        for(int i=0;i<total_user;++i)
        {
            if(customer[i].get_mail()==mail and customer[i].get_pass()==pass)
            {
                permission=true, current_user_id=i; break;
            }
        }
        if(permission)
        {
            logged_in=true, current_user=mail, cout<<"Logged in";

            time_t log_in_time=time(NULL);
            string log_in_format=ctime(&log_in_time);
            history[total_log_in]=log_in_format;
            user_history[total_log_in]=customer[current_user_id].get_name();
            ++total_log_in;
            
            cout<<endl<<endl;
        }
        else cout<<"Email not found or Invalid password."<<endl<<endl;
    }
}

void sign_out()
{
    if(!logged_in) cout<<"Not signed in"<<endl<<endl;
    else logged_in=false, current_user_id=-1, cout<<"Logged out"<<endl<<endl;
}

void reset_pass()
{
    if(logged_in)
    {
        cout<<"Enter new password: "; cin>>pass;

        if(pass=="back")
        {
            cout<<endl; return;
        }

        if(pass==customer[current_user_id].get_pass()) cout<<"Current password cannot be the new password"<<endl<<endl;
        else
        {
            customer[current_user_id].set_pass(pass);
            cout<<"Password Reset Successfully"<<endl<<endl;
        }
    }
    else
    {
        cout<<"Not logged in"<<endl<<endl;
        return;
    }
}

void send_money()
{
    if(logged_in)
    {
        cout<<"Enter Recipient mail: "; cin>>mail;

        if(mail=="back")
        {
            cout<<endl; return;
        }

        cout<<"Amount to be sent: "; cin>>money;
        int id_receiver=-1;

        for(int i=0;i<total_user;++i)
        {
            if(customer[i].get_mail()==mail)
            {
                id_receiver=i; break;
            }
        }

        if(id_receiver==-1)
        {
            cout<<"Email not found"<<endl<<endl; return;
        }
        else if(mail==current_user)
        {
            cout<<"Cannot send to own account"<<endl<<endl; return;
        }
        else
        {
            if(customer[current_user_id].get_balance()>=money)
            {
                bussniness[current_user_id][total_transaction[current_user_id]].set_amount(money);
                bussniness[current_user_id][total_transaction[current_user_id]].set_sender("none");
                bussniness[current_user_id][total_transaction[current_user_id]].set_receiver(customer[id_receiver].get_name());

                int bal;
                bal=customer[current_user_id].get_balance();
                bal-=money;
                customer[current_user_id].set_balance(bal);

                bussniness[current_user_id][total_transaction[current_user_id]].set_prev_balance(bal);
                ++total_transaction[current_user_id];

                bussniness[id_receiver][total_transaction[id_receiver]].set_amount(money);
                bussniness[id_receiver][total_transaction[id_receiver]].set_sender(customer[current_user_id].get_name());
                bussniness[id_receiver][total_transaction[id_receiver]].set_receiver("none");

                bal=customer[id_receiver].get_balance();
                bal+=money;
                customer[id_receiver].set_balance(bal);

                bussniness[id_receiver][total_transaction[id_receiver]].set_prev_balance(bal);
                ++total_transaction[id_receiver];

                cout<<"Transaction Successful"<<endl<<endl;
            }
            else cout<<"Insufficient Balance"<<endl<<endl;
        }
    }
    else cout<<"Not logged in."<<endl<<endl;
}

void view_transactions()
{
    if(logged_in)
    {
        cout<<"****************************************************************"<<endl;
        cout<<"Account Holder: "<<customer[current_user_id].get_name()<<endl<<endl;
        if(total_transaction[current_user_id]==0) cout<<"No transactions have been made"<<endl;
        else
        {
            for(int i=0;i<total_transaction[current_user_id];++i)
            {
                cout<<"Transaction-"<<i+1<<endl;
                if(bussniness[current_user_id][i].get_sender()!="none")
                {
                    cout<<"Sender: "<<bussniness[current_user_id][i].get_sender()<<endl;
                }
                if(bussniness[current_user_id][i].get_receiver()!="none")
                {
                    cout<<"Receiver: "<<bussniness[current_user_id][i].get_receiver()<<endl;
                }
                cout<<"Amount: "<<bussniness[current_user_id][i].get_amount()<<" Taka"<<endl;
                cout<<"Current Balance: "<<bussniness[current_user_id][i].get_previous_balance()<<" Taka"<<endl<<endl;
            }
        }
        cout<<"****************************************************************"<<endl<<endl;
    }
    else cout<<"Not logged in"<<endl<<endl;
}

void view_customer_list()
{
    cout<<"*****************************************"<<endl<<endl;
    if(total_user)
    {
        for(int i=0;i<total_user;++i)
        {
            customer[i].print();
        }
    }
    else cout<<"No account created"<<endl<<endl;
    cout<<"*****************************************"<<endl<<endl;
}

void view_log_in_history()
{
    cout<<"*****************************************"<<endl<<endl;
    for(int i=0;i<total_log_in;++i)
    {
        cout<<"User: "<<user_history[i]<<endl;
        cout<<"Logg in time: "<<history[i]<<endl<<endl;
    }
    cout<<"*****************************************"<<endl<<endl;
}
string suggest_pass()
{
    string s;
    char a,b,x;
    int i=10,y;
    while(i--)
    {
        a=rand()%25+65;
        b=rand()%25+97;
        x=rand()%10+48, y=rand()%3;
        s.push_back((y==0)? a:(y==1)? b:x);
    }
    return s;
}
//////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/////text file reading and writing

void from_txt()
{
    ///taking inputs from txt file
    ifstream logg("current logged in and total user number.txt");//log in info

    logg>>current_user>>current_user_id>>total_user;

    if(current_user!="none") logged_in=true;

    logg.close();

    ifstream inp("Users.txt");//user info

    for(int i=0;i<total_user;++i)
    {
        inp>>mail>>name>>pass>>money;
        customer[i].set_mail(mail);
        customer[i].set_name(name);
        customer[i].set_pass(pass);
        customer[i].set_balance(money);
    }
    inp.close();

    ifstream inp1("Transactions.txt");//transaction info

    char sender_or_receiver;
    int no_of_transaction;
    for(int i=0;i<total_user;++i)
    {
        inp1>>no_of_transaction;
        for(int k=0;k<no_of_transaction;++k)
        {
            inp1>>sender_or_receiver>>name;
            if(sender_or_receiver=='s')
            {
                bussniness[i][k].set_sender(name);
                bussniness[i][k].set_receiver("none");
            }
            else if(sender_or_receiver=='r')
            {
                bussniness[i][k].set_receiver(name);
                bussniness[i][k].set_sender("none");
            }
            inp1>>money; bussniness[i][k].set_amount(money);
            inp1>>money; bussniness[i][k].set_prev_balance(money);
        }
        total_transaction[i]=no_of_transaction;
    }

    inp1.close();

    ifstream inp2("Log In History.txt");//log in history

    inp2>>total_log_in;
    for(int i=0;i<total_log_in;++i)
    {
        inp2>>name, user_history[i]=name;
        inp2.ignore();
        getline(inp2,name), history[i]=name;
    }

    inp2.close();
}

void to_txt()
{
    /////storing data into txt file
    ofstream logg("current logged in and total user number.txt");

    if(logged_in) logg<<current_user<<endl<<current_user_id<<endl;
    else logg<<"none"<<endl<<-1<<endl;

    logg<<total_user<<endl;
    logg.close();

    ofstream out("Users.txt");

    for(int i=0;i<total_user;++i)
    {
        out<<customer[i].get_mail()<<endl;
        out<<customer[i].get_name()<<endl;
        out<<customer[i].get_pass()<<endl;
        out<<customer[i].get_balance()<<endl;
    }
    out.close();

    ofstream out1("Transactions.txt");

    for(int i=0;i<total_user;++i)
    {
        out1<<total_transaction[i]<<endl;
        for(int k=0;k<total_transaction[i];++k)
        {
            if(bussniness[i][k].get_sender()!="none") out1<<'s'<<endl<<bussniness[i][k].get_sender()<<endl;
            if(bussniness[i][k].get_receiver()!="none") out1<<'r'<<endl<<bussniness[i][k].get_receiver()<<endl;
            out1<<bussniness[i][k].get_amount()<<endl;
            out1<<bussniness[i][k].get_previous_balance()<<endl;
        }
    }

    out1.close();

    ofstream out2("Log In History.txt");

    out2<<total_log_in<<endl;
    for(int i=0;i<total_log_in;++i)
    {
        out2<<user_history[i]<<endl;
        out2<<history[i]<<endl;
    }

    out2.close();
}