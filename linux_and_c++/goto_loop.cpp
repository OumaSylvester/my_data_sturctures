#include <iostream>
using namespace std;

int main()
{
    Rerun1:
        int num1 = 0, num2 = 0;
        cout <<"Enter two integers: ";
        cin >> num1;
        cin >>num2;

        cout << num1 <<" x " <<num2 <<" = "<<num1 * num2<<endl;
        cout <<num1 << " + " <<num2<<" = "<< num1 + num2<<endl;

        cout <<"Do you wish to perform another operation(y/n)? ";
        char repeat = 'y';
        cin>>repeat;

        if(repeat == 'y')
            goto Rerun1;

        cout << "Goodbye!"<<endl;
        return 0;
}
