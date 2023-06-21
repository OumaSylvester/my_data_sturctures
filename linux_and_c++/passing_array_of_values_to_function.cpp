#include <iostream>
using namespace std;

void DisplayArray(int numbers[], int length)
{
    for(int index =0; index < length; ++index)
        cout<<numbers[index]<<" ";
    cout <<endl;
    return;
}
void DisplayArray(char characters[], int leghth)
{
    for(int index =0; index<leghth; ++index)
        cout<<characters[index]<<" ";
    cout<<endl;
}

int main()
{
    int myNums[4] = {24, 58, -1, 245};
    DisplayArray(myNums, 4);

    char myStatement[7] =  {'H', 'e', 'l','l','o', '!', '\0'};
    DisplayArray(myStatement, 7);
    cout<<myStatement;
    return 0;
}
