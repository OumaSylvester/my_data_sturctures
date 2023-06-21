/*A program that lets the compiler deduce the return type for the functions that i call
Justk like letting it deduce return types for the consts depending on the initializtion value*/

#include <iostream>
using namespace std;

const double Pi = 3.14159265;

/*Functions that rely on automatic return type deduction need to be defined
 (i.e., implemented) before they’re invoked*/
auto Area(double radius)
{
    return Pi * radius * radius;

}

int main()
{
    cout <<"Enter radius: ";
    double radius =0;
    cin >>radius;

    // Call function "Area"
    cout<<"Area is: "<<Area(radius);
    return 0;
}
