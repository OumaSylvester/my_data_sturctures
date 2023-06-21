#include <iostream>
#include <string>
using namespace std;

int main()
{
    int inputNumber;
    cout <<"Enter an integer: ";
    // store integer given user input
    cin >>inputNumber;

    // The same with text i.e string data
    string inputName;
    cout <<"Enter your name: ";
    getline(inputName);

    cout << inputName <<" entered "<< inputNumber <<endl;
    return 0;
}

