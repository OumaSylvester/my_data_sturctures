#include <iostream>
using namespace std;

int MultiplyNumbers()
{
    cout << "Enter the first number: ";
    short firstNumber =0;
    cin >>firstNumber;

    cout << "Enter the second number: ";
    int secondNumber =0;
    cin >> secondNumber;

    // Multiply two numbers, store results in a variable
    int multiplicationResult = firstNumber * secondNumber;




    // Display result
    cout << firstNumber << " x " << secondNumber;
    cout << " = " << multiplicationResult <<endl;

    return multiplicationResult;
}

int main()
{
    cout <<"This program will help you multiply two numbers"<<endl;
    // Call the funtion that does all the work

    /*
    cout <<"Enter the first number: ";
    int firstNumber = 0;
    cin >> firstNumber;

    cout <<"Enter the second number: ";
    int secondNumber = 0;
    cin >> secondNumber;

    // Multiply two  numbers, store results in avaribale
    int multiplicationResult  = firstNumber * secondNumber;


    // Display result
    cout << firstNumber <<" X " << secondNumber;
    cout << " = " << multiplicationResult<<endl;
    */
    //int(16 bit) bit16_int= 40000;
    //cout << bit16_int;
    //cout << "From main: " <<endl;
    MultiplyNumbers();

    int largeNum = 5000000;
    float largeFloat = 5000000.75;
    int narrow_to_int = largeFloat;
    short anotherNum {largeNum}; // error! Amend types
    int anotherNum_with_int = {largeNum}; // OK!
    float someFloat{largeNum}; //error! An int may be narrowed
    float someFloat_done_right {5000000}; // OK! 5000000 can be accomodated
    cout << largeNum <<" expected to narrow to short int: " <<anotherNum <<endl;
    cout << largeNum <<" expected to narrow to  int: " <<anotherNum_with_int <<endl;
    cout << largeNum <<" expected to narrow to float: " <<someFloat <<endl;
    cout << largeNum <<" expected not to narrow to float: " <<someFloat_done_right <<endl;
    cout <<"Original float X 2 = " <<largeFloat * 2;
    cout << largeFloat <<" expected to narrow to: "<< narrow_to_int * 2;


    return 0;
}
