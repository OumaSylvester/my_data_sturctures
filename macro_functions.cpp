#include<iostream>
#include<string>
using namespace std;

#define SQUARE(x)((x) * (x))
#define PI 3.1416
#define AREA(r) (PI * (r)* (r))
#define MAX(a, b) (((a) > (b)) ? (a):(b))
#define MIN(a, b) (((a) < (b)) ? (a):(b))


int main()
{
    cout<<"Enter an integer: ";
    int Input1=0;
    cin>>Input1;

    cout<<"SQUARE("<<Input1<<") ="<<SQUARE(Input1)<<endl;
    cout<<"An area with a circle of radius "<<Input1<<" is: "<<AREA(Input1)<<endl;

    cout<<"Enter another integer: ";
    int Input2 = 0;
    cin>>Input2;

    cout<<"MIN("<<Input1<<", "<<Input2<<") = "<<MIN(Input1,Input2)<<endl;

    cout<<"MAX("<<Input1<<", "<<Input2<<") = "<<MAX(Input1, Input2)<<endl;

    return 0;


}
