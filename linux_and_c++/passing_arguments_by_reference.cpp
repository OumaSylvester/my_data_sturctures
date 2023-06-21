#include <iostream>
using namespace std;

const double Pi = 3.1416;

// output parameter result by reference
void Area(double radius, double& result)
{
    result = Pi * radius * radius; // A function can return only one value using the return statement.
    // So, if your function needs to perform operations that affect many values required at the caller,
    // passing arguments by reference is one way to get a function to supply those many modifications back
    //to the  calling module
}

int main()
{
    cout<<"Enter radius: ";
    double radius =0;
    cin>>radius;

    double areaFetched =0;
    Area(radius, areaFetched);
    cout <<"The area is: "<<areaFetched<<endl;
    return 0;
}
