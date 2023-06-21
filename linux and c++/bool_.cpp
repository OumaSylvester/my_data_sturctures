#include <iostream>
using namespace std;

int main()
{
    cout<< "Answer questions with 0 or 1"<<endl;
    cout<< "Is there a discount on your favorite car? ";
    bool onDisount = false;
    cin >> onDisount;

    cout << "Did you get a fantastic bonus? ";
    bool fantasticBonus = false;
    cin >> fantasticBonus;

    if (onDisount || fantasticBonus)
        cout <<"Congratulations,  you can buy the car!"<<endl;
    else
        cout<< "Sorry, waiting a while is a good idea"<<endl;
    if(!onDisount)
        cout << "Car not on discount" <<endl;
}
