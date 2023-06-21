#include<string>
#include<iostream>

int main()
{
    using namespace std;

    //The sample string
    string strSTLString("Hello String");

    //Access the contents of the string using array syntax
    cout<<"Displaying the elements in the string using array-syntax: "<<endl;
    for(size_t nCharCounter = 0; nCharCounter<strSTLString.length(); ++nCharCounter)
    {
        cout<<"Character["<<nCharCounter<<"] is: "<<strSTLString[nCharCounter]<<endl;
    }

    // Access the contents of a string using iterators
    cout<<"Displaying the contents of the string using iterators: "<<endl;
    int charOffset = 0;
    string::const_iterator iCharacterLocator; //overloaded version of the iterator for characters
    for(iCharacterLocator =strSTLString.begin(); iCharacterLocator != strSTLString.end(); ++iCharacterLocator)
    {
        cout<<"Character ["<<charOffset++<<"] is: ";
        cout<<*iCharacterLocator<<endl;
    }
    cout<<endl;

    //Access the ontents of sting as a C-style string
    cout<<"The char* representation of the string is: "<<strSTLString.c_str()<<endl;
    return 0;
}
