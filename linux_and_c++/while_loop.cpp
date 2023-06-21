#include <iostream>
using  namespace std;

int main()
{
    char userSelection = 'm'; //initialize to any value that is not x so that the while loop condition is true the first time
    while(userSelection != 'x'){
        cout <<"Enter the two integers: ";
        int num1 = 0, num2 =0;
        cin >>num1;
        cin >>num2;

        cout << num1 <<" x "<<num2 <<" = "<<num1 * num2<<endl;
        cout <<num1 <<" + "<< num2 << " = "<<num1 +  num2<<endl;

        cout <<"Press x to exit(x) or any other key to recalculate"<<endl;
        cin>>userSelection;
    }
    cout <<"Goodbye!"<<endl;
    return 0;

}
