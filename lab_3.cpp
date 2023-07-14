#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<string.h>
using namespace std;


class Copy
{
    int a, b;
    char* c;

    public:
        Copy(int a, char* c)
        {
            this->a=a;
            this->c=new char[strlen(c)+1];
            strcpy(this->c,c);
        }

        int get_a()
        {
            return this->a;
        }

        Copy(const Copy &ob)
        {
            this->c=new char[strlen(ob.c)+1];
            this->a=ob.a;
            strcpy(this->c,ob.c);
        }

        char* get_c()
        {
            return this->c;
        }

        ~Copy()
        {
            delete[] c;
        }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    Copy a(1,"Hello");
    Copy b=a;
    return 0;
}