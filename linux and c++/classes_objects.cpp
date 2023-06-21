#include <iostream>
#include <string>

using namespace std;

class Human
{
    public:
        string name;
        int age;

        void IntroduceSelf()
        {
            cout <<"I am " + name <<" and am ";
            cout<<age <<" years old"<<endl;
        }
};

int main()
{
    // An object of class Human  with attributes name as "Adam"
    Human firstMan;
    firstMan.name = "Adam";
    firstMan.age = 30;

    // An object of class Human with name as "Eve"
    Human firstWoMan;
    firstWoMan.name = "Eve";
    firstWoMan.age = 28;

    firstMan.IntroduceSelf();
    firstWoMan.IntroduceSelf();
}

