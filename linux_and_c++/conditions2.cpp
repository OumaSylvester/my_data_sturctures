#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    cout <<"Enter a line of text: "<<endl;
    string userInput;
    getline(cin, userInput);

    string copy_to_string="";
    copy_to_string = userInput;
    cout<<"Copied to string>>> "<<copy_to_string<<endl;
    char copyInput[20] = {'\0'};
    if(userInput.length() <20) //check bounds
    {
        strcpy(copyInput,userInput.c_str()); // check what strcpy and userInput.c_str() do
        cout<<"copyInput contains: "<<copyInput<<endl;
    }
    else
        cout<<"Bounds exceeded: won't copy!"<<endl;
    return 0;

}
