#include<iostream>
#include<string.h>
using namespace std;

class Mystring
{
    private:
        char* buffer;

    public:
        Mystring(const char* initString) //constructor
        {
            buffer = NULL;
            cout<<"Default constructor: creating new Mystring"<<endl;
            if(initString != NULL)
            {
                buffer = new char[strlen(initString) + 1];
                strcpy(buffer, initString);

                cout<<"buffer points to: "<<(unsigned int*)buffer<<endl;
            }
        }

        Mystring(const Mystring& copySource) // Copy constructor
        {
            buffer = NULL;
            cout<<"Copy constructor: copying from MyString"<<endl;
            if(copySource.buffer != NULL)
            {
                // allocate own buufer
                buffer = new char[strlen(copySource.buffer) + 1];

                // deep copy from the source into local  buffer
                strcpy(buffer, copySource.buffer);

                cout<<"buffer points to: "<<(unsigned int*)buffer<<endl;
            }
        }

        ~Mystring() //Destrucotr
        {
            cout<<"Invokine destructor, clearing up"<<endl;
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

    cout<<"buffer conatins: "<<str.GetString()<<endl;
    return;
}

int main()
{
    Mystring sayHello("Hello from String Class");
    UseMystring(sayHello);

    return 0;
}
