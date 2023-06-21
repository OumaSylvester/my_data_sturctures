#include <iostream>
using namespace std;

int main()
{
    int age = 30;
    const double Pi = 3.1416;
    int* pointsToInt = &age; //pointer initalized to &age

    // Use & to find the address  in memory
    //cout<<"Integer age is located at: "<<&age<<endl;
    //cout<< "Double Pi is located at: "<<&Pi<<endl;

    cout<< "pointsToInt points  to: "<<pointsToInt<<endl;
    int dogAge = 9;
    pointsToInt = &dogAge;
    cout<<"pointsToInt points to dogAge now"<<endl;
    cout<<"pointsToInt = "<<pointsToInt<<endl;

    return 0;
}
