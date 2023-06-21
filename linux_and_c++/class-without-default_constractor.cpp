#include <iostream>
#include <string>

using namespace std;

class Human
{
    private:
        string name;
        int age;

    public:
        //Overloaded constructor....no default constructor
        // A default constructor is one that can be instantiated without argumants, and
        //not necessarily one that doesn;t take parameters
        Human(string humansName, int humansAge)
        {
            name = humansName;
            age = humansAge;
            cout <<"Overloaded constructor creates "<<name;
            cout<<" of age"<<age<<endl;
        }

        void IntroduceSelf()
        {
            cout<<"I am " + name <<" and am ";
            cout<<age<<" years old"<<endl;
        }
};

int main()
{
    Human firstMan("Adam", 25);
    Human firstWoman("Eve", 28);

    firstMan.IntroduceSelf();
    firstWoman.IntroduceSelf();
}
