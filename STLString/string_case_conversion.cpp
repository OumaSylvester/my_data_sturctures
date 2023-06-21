/*The algorithm std::transform, applies a user-specified function to every element of a
collection. This advantage could be used to do string case conversion*/

#include<string>
#include<iostream>
#include<algorithm>

int main()
{
    using namespace std;

    cout<<"Please enter a string for case-conversion: "<<endl;
    cout<< "> ";

    string strInput;
    getline(cin, strInput);
    cout<<endl;

    transform(strInput.begin(), strInput.end(),strInput.begin(), toupper);
    cout<<"The string converted to upper case is: "<<endl;
    cout<<strInput<<endl<<endl;

    transform(strInput.begin(), strInput.end(), strInput.begin(), tolower);
    cout<<"The string converted  to lower case is: "<<endl;
    cout<<strInput<<endl<<endl;

    return 0;
}
