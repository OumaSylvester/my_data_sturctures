#include <iostream>
using namespace std;

int main()
{
    int age = 30;
    int dogsAge = 35;

    cout <<"integer age = "<<age<<endl;
    cout<<"integer dogsAge = "<<dogsAge<<endl;

    int* pointsToInt = &age;
    cout <<"pointsToInt points to age"<<endl;

    //Displaying the value of the pointer
    cout<<"pointsToInt = "<<pointsToInt<<endl;

    //Dislaying the value at the pointed location
    cout<<"*pointsToInt = "<<*pointsToInt<<endl;

    pointsToInt = &dogsAge;
    cout<<"pointsToInt points to dogsAge now"<<endl;

    cout <<"pointsToInt = "<<pointsToInt<<endl;
    cout<<"*pointsToInt = "<<*pointsToInt<<endl;

    return 0;
}
