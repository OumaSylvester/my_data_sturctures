#include <iostream>
using namespace std;

int main()
{
    cout << "Enter two integers: "<<endl;
    int num1 =0, num2 =0;
    cin >> num1;
    cin >> num2;

    cout <<  num1 << " + " <<num2 <<" = " << num1 + num2 <<endl;
    cout << num1 << " - " << num2 <<" = " <<num1 - num2<<endl;
    cout << num1 << " * " <<num2 <<" = " << num1 * num2<<endl;
    cout << num1 << " / " <<num2 <<" = " <<num1 / num2<<endl;
    cout <<num1 << " % " << num2 << " = " <<num1 % num2<<endl;

    // Operators to Increment(++) and Decrement (--)
    int num3 = 10;
    int num4 = num3++; //Postfix incremnt opearator
    int num5 = ++num3; // Prefix incremant operator;
    cout <<num3 <<" post incremented  by 1 to: "<<num4<<endl;
    cout <<num3 <<" pre incremented  by 1 to: "<<num5<<endl;


    return 0;
}
