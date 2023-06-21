// Preprocessor directive that includes header iostream
#include <iostream>
using namespace std;

//Declare a function
int DemoConsoleOutput();
// Start of your program: function block main()
int main()
{
    /* Write to the screen */
    cout << "Hello World" <<endl;
    // Return a value to the os
    // Call ie. invoke the function
    DemoConsoleOutput();

    return 0;
}

// Define i.e implement the previously declred function
int DemoConsoleOutput()
{
    cout <<"This is a simple string literal\n";
    cout <<"Writing my year of birth " <<1999 <<endl;
    cout <<"pi is " <<22.0/7 <<endl;
}
