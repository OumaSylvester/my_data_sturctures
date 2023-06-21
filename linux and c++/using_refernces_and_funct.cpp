//Refernces enables functions to work directly on the data in the calle's stack
/*
    A version of a function without a copy step loooks like this:

    ReturnType DoSomething(Type& parameter); //note the reference&

    This would be called as:

    ReturnType = DoSomething(argument);

    As the argument is being passed by refernce, Parament is not a copy of the argument rather
    an alias of the latter.
    A function that accepts a parameter as refernce can optionally return values using refernce
    parameters
*/

#include <iostream>
using namespace std;

void GetSquare(int& number) //using refernces, you ensure that this function is operating in the
//same address space where number in main() is defined.Thus the result is available in main even
// after the GetSquare has exited
{
    number *= number;
}

int main()
{
    cout <<"Enter a number you wish to square: ";
    int number =0;
    cin>>number;

    GetSquare(number);
    cout<<"Square is: "<<number<<endl;
    cout<<number;//the number has been changed directly
    return 0;
}
