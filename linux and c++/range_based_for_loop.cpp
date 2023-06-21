#include <iostream>
#include <string>
using namespace std;

int main()
{
    int someNums[] = {1, 202,34, 89, 90};

    for(const int& aNum: someNums)
        cout << aNum<<" ";
    cout<<endl;

    char charArray[] = {'h', 'e', 'l', 'l',  'o'};
    for (auto aChar: charArray)
        cout<<aChar<<" ";
    cout<<endl;

    string sayHello{"Hello World!"};
    for (auto anElemnet: sayHello)
        cout <<anElemnet<<" ";
    cout <<endl;

    double moreNums [] = {23,90.23, 21.44, 567.66};
    for (auto anElemnet : moreNums)
        cout<<anElemnet<<" ";
    cout<<endl;
    return 0;
}
