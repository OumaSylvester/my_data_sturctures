#include <iostream>
using namespace std;

int main()
{
    int startValue = 101;
    cout <<"Start value of integer beingn operated: "<<startValue<<endl;

    int postfixIncrement = startValue++;
    cout<<"Results of Postfix Increment = "<<postfixIncrement<<endl;///xpected >>101
    cout<<"After Postfix Increment, startValue = " <<startValue<<endl; //expected>>102

    startValue = 101; //reset
    int postfixDecremet = startValue--; //In this case the postfixDecrement variable is assigned startValue then the startValue is decremented to 100
    cout <<"Result of Postfix Decrement = " <<postfixDecremet<<endl;//expect 101
    cout <<"After Postfix Decrement, startValue = "<<startValue<<endl; //expect 100

    startValue = 101; //Reset
    int prefixDecrement = --startValue; //In this case the startValue is decremented first then assigned to prefixDrement variable
    cout<<"Result of Prefix Decrement = "<<prefixDecrement<<endl; //result 100
    cout<<"After Prefix Decrement, startValue = "<<startValue<<endl; // expect 100

    /*
    NB>>startValue++; is same as ++startValue because there is no assignment of an initial value
    */
    return 0;

}
