#include <iostream>
using namespace std;


class Human
{
    private:
       /* Private member data: i.e can only e accessed within the class and not outside in
         other classes or functions.This is abstraction. It gives programmers the power to decide
         what attributes of a class need to remain known only to the  class and its members with nobody
         outside it haing access to it with the exception of those declared  as its "friends"*/
        int age;
    public:
        void SetAge(int inputAge)
        {
            age = inputAge;
        }

        // Human lies about his / her age (if over 30)
        int GetAge()
        {
            if(age > 30)
                return (age -2);
            else
                return age;
        }

};


int main()
{
    Human firstMan;
    firstMan.SetAge(22);

    Human firstWoman;
    firstWoman.SetAge(35);

    cout <<"Age of firstMan "<<firstMan.GetAge()<<endl;
    cout <<"Age of firstWoman "<<firstWoman.GetAge()<<endl;
    //cout<<firstWoman.age; //copile error

    return 0;
}
