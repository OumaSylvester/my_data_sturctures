// lvalue >> a value that can be treated as an address or storage location

#include <iostream>
using namespace std;

void GetSquare(const int& number, int& result) //number cannot be modified
// const references indicates that a parameter is an input parameter
{
    result = number * number;
}

int main()
{
    cout<<"Enter a number you wish to square: ";
    int number =0;
    cin>>number;

    int square =0;
    GetSquare(number, square);
    cout <<number <<"^2 = "<<square<<endl;

    return 0;
}
