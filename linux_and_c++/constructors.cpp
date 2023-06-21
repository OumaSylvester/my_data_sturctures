/*Constructors: it is aspecial function or method invoked during the instantiation of
a class to construct an object. They can be overloaded just like functions.
Its a special function that takes the name of the class and returns no value.
It can be implemented inline within the class or externally outside the class declaration.*/


// When and how to use Constructors
// Since its invoked during object creation, its a perfect place for me  to initialize class members
// variables such as int, pointers and so on  to values i choose.

#include <iostream>
#include <string>
using namespace std;


class Human
{
    private:
        string name;
        int age;

    public:
        Human() //default  constructor>>A constructor that is invoked without an argument
        /*If you don't program a any constructor the compiler creates one for you that constructs
        member attributes but does not iniatilize Plain Old Data types such as int to any specific
        non-zero value.*/
        {
            age = 1; //initialization
            cout <<"Constructed an instance of class Human"<<endl;
        }

        void setName(string humansName)
        {
            name = humansName;
        }

        void SetAge(int humansAge)
        {
            age = humansAge;
        }

        void IntroduceSelf()
        {
            cout<<"I am "<< name<<" and am ";
            cout <<age <<" years old"<<endl;
        }
};

int main()
{
    Human firstWoman;
    firstWoman.setName("Eve");
    firstWoman.SetAge(28);

    firstWoman.IntroduceSelf();

    return 0;
}

