#include <iostream>
#include<string.h>

using namespace std;

class Mystring
{
    private:
        char* buffer;

    public:
        Mystring(const char* initString) // Constructor
        {
            buffer = NULL;
            if(initString != NULL)
            {
                buffer = new char(strlen(initString) + 1);
                strcpy(buffer, initString);
            }
        }

        ~Mystring() // Destructor
        {
            cout<<"Invoking destructor, clearing up"<<endl;
            delete [] buffer;
        }

        int GetLength()
        {return strlen(buffer);}

        const char* GetString()
        {return buffer;}
};


void UseMystring(Mystring str)
{
        cout<<"String buffer in Mystring is "<<str.GetLength();
        cout<<" characters long"<<endl;

        cout<<"buffer contains: "<<str.GetString()<<endl;
        return;
}
int main()
{
    Mystring sayHello("Hello from String Class");
    UseMystring(sayHello);
    return 0;
}
