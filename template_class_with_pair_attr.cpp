// Declaring default parameter types, first int, second float

template <typename T1=int, typename T2=double>
class HoldsPair
{
    T1 Value1;
    T2 Value2;

public:
    // Constructor that initializes variables
    HoldsPair(const T1& value1, const T2& value2)
    {
        Value1 = value1;
        Value2 = value2;
    };

    // Accessor function
    const T1 & GetFirstValue() const
    {
        return Value1;
    };

    const T2& GetSecondValue() const
    {
        return Value2;
    };
};


#include <iostream>
using namespace std;

int main()
{
    // Two instantiation of template HoldsPair
    HoldsPair <> mIntFloatPair(300, 10.9);
    HoldsPair <short, char*>mshortStringPair (25, "Learn  Templates, love C++");

    //output values obtained in first object
    cout<<"The first object contains ."<<endl;
    cout <<"value1: "<<mIntFloatPair.GetFirstValue()<<endl;
    cout <<"value2: "<<mIntFloatPair.GetSecondValue()<<endl;

    // output values contained in the second object
    cout<<"The second object contains ."<<endl;
    cout<<"Valu1: "<<mshortStringPair.GetFirstValue()<<endl;
    cout<<"value2: "<<mshortStringPair.GetSecondValue()<<endl;

    return 0;
}
