/*A reference is an alias for a variable. Just another name for a variable.
When you  reference, you need to initalize  to a variable. Thus, the reference varible is just
a different way to acces the data stored in te varibale being referenced.

You would declare a reference using the reference operator(&) as seen below:

varType original = Value;
varType& ReferenceVarible = original;

References enables you to work with the memory location they are initatilized to.This makes
refernces particularly useful when programmig functions.


*/

#include <iostream>
using namespace std;

int main()
{
    int original = 30;
    cout<<"original = "<<original<<endl;
    cout <<"original is at address: "<<&original<<endl;

    int& ref1 = original;
    cout <<"ref1 is at address: "<<&ref1<<endl;

    int& ref2 = ref1;
    cout <<"ref2 is at address: "<<&ref2<<endl;
    cout<<"Therefore, ref2 = "<<ref2<<endl;


}



