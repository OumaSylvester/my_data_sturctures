#include <iostream>
using namespace std;

int main()
{
    unsigned short uShortValue = 65535;
    cout << "Incrementing usigned short " << uShortValue << " gives: ";
    cout << ++ uShortValue <<endl;

    short signedShort = 32767;
    cout << "Incrementing signed short " <<signedShort<<" gives: ";
    cout << ++signedShort << endl;


    int32_t moneyInBank = 7000'000;
    cout<< "Money in bank: " <<moneyInBank * 2 << endl;
    cout << "size of int: " << sizeof(int);
    return 0;
}
