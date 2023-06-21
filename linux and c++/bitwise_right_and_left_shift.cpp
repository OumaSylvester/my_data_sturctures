#include<iostream>
using namespace std;

int main()
{
    /*
        Shift operators move the entire bit sequence to the right or left  and thus can help
        with multiplication or divison by  multiples of two.
        They also have other uses in an application
    */
    cout << "Enter a number: ";
    int inputNum = 0;
    cin >>inputNum;

    int halfNum = inputNum >> 1; // Right shift operator divides by a multiple of 2
    int quarterNum = inputNum >> 2;
    int doubleNum = inputNum << 1; //Left shift operator multiplies by a multiple of 2
    int quadrupleNum = inputNum << 2;

    cout <<"Quarter: " << quarterNum <<endl;
    cout << "Half: " << halfNum<<endl;
    cout <<"Double: "<< doubleNum<<endl;
    cout<< "Quadruple: "<<quadrupleNum<<endl;

    // sizeof is an operator
    return 0;


}
