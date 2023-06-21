#include <iostream>
using namespace std;

// define an iline function that doubles
inline long DoubleNum(int inputNum)
{
    /*Keyword inline is the programmers’ request that these functions be expanded inline where called.
    The overhead of performing an actual call like translating into a CALL instruction which results in stack operations
     and micropeocessor execution is avoided*/
    return inputNum * 2;
}

int main()
{
    cout<<"Enter an integer: ";
    int inputNum =0;
    cin >> inputNum;

    //Call  inline function
    cout <<"Double is: "<<DoubleNum(inputNum)<<endl;
    return 0;
}
