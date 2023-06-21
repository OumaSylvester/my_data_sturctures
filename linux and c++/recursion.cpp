#include <iostream>
using namespace std;

int getFibNumber(int fibIndex)
{
    /* A  recursive function that computes a Fibanocci sequence*/
    if(fibIndex < 2)
        return fibIndex;
    else  //recursive if fibIndex >=2
        return getFibNumber(fibIndex - 1) + getFibNumber(fibIndex - 2);
}

int main()
{
    cout << "Enter 0-based index of desired Fiboncci Number: ";
    int index =0;
    cin >>index;

    cout <<"Fibonacci number is: "<<getFibNumber(index)<<endl;
    return 0;
}
