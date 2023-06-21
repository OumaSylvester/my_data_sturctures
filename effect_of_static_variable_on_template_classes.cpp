#include<iostream>
using namespace std;

template<typename T>
class TestStatic
{
public:
    static int StaticValue;
};


//static member initialization
template<typename T>int TestStatic<T>::StaticValue;

int main()
{
    TestStatic <int> Int_Year;
    cout<<"Setting static value for int_Year to 2021"<<endl;
    Int_Year.StaticValue = 2021;
    TestStatic <int> Int_Year2;

    TestStatic <double> double1;
    TestStatic <double> double2;
    cout<<"Setting StaticValue for double2 to 1011"<<endl;
    double2.StaticValue = 1011;

    cout<<"Int2.StaticValue = "<<Int_Year2.StaticValue<<endl;
    cout<<"Double1.StaticValue = "<<double1.StaticValue<<endl;

    return 0;
}
