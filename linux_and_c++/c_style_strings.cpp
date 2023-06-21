#include<iostream>
using namespace std;

int main()
{
    //normal way

    cout << "Hello" <<endl; // When u embed a s tring literal into your code, the compiler does the job adding a '\0' after it
    // c-style stirng
    char sayHello [] = {'H', 'e','l', 'l', 'o' ,'\0'}; // The \0 represent the null character. It tells the compiler the string has ended
    cout << sayHello <<endl;
    // c-style string functions >>>strlen, strcat,strcpy
    return 0;
}
