/*A deconstrustor is automatically invoked when an object is destroyed(when it goes out of
scope or is deleted by delete).
This property makes the deconstrucotr the perfect place to reset variables and release dynamically
allocated memory and other resources.
The deconstructor looks like a function that takes the name of the class, yet has a tilde(~)
preceding it.*/


/*Analyze a sample class MyString  that allocates memory for a character string in
 the constructor and releases it in the destructor.*/

#include <iostream>
#include <string.h>
using namespace std;


// This class abstracts the user from the implementation of memory management from the user.It
// also ensure technical correcteness in realesing allocated memory.
class Mystring
{
    private:
        char* buffer;

    public:
        Mystring(const char* initString)    //constructor
        {
            if(initString != NULL)
            {
                buffer = new char [strlen(initString) + 1];
                strcpy(buffer, initString);
            }
            else
                buffer = NULL;
        }
        //The deconstructor is exceuted when main() ends
        // A deconstructor cannot be overloaded
        // if u forget to implement a deconstructor, the compiler invokes a dummy one(an empty one)
        ~Mystring()
        {
            cout<<"Invoking destructor, clearing up"<<endl;
            if(buffer != NULL)
                delete [] buffer;
        }

        int GetLength()
        {
            return strlen(buffer);
        }

        const char* GetString()
        {
            return buffer;
        }
};


int main()
{
    Mystring sayHello("Hello from String Class");
    cout<<"String buffer in sayHello is "<<sayHello.GetLength()<<" characters long"<<endl;

    cout<<"Buffer contains: "<<sayHello.GetString()<<endl;
}

