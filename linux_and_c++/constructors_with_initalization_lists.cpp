/*class Human that features a default constructor with  parameters,
default values, and an initialization lis*/

#include <iostream>
#include <string>
using namespace std;


class Human
{
    private:
        int age;
        string name;

    public:
        // Default parameter with default values
        // You can also define a constructor using constexpr
        Human(string humansName="Adam", int humansAge=22)
            :name(humansName), age(humansAge)
        {
            cout<<"Contructed a human called "<<name;
            cout<<", "<<age<<" years old"<<endl;
        }
};


int main()
{
    Human adam;
    Human sta("Stacy", 19);
    return 0;
}
