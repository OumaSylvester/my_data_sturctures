#include <iostream>
using namespace std;

int main()
{
    //Request for memory space for an tint
    int* pointsToAnAge = new int; //new returns a pointer

    //Use the allocated memory to store a number
    cout<<"Enter your dog's age: ";
    cin>> *pointsToAnAge;

    //use indirection operator* to access value
     cout<< "Age "<<*pointsToAnAge<<" is stored at "<<pointsToAnAge<<endl;
     delete pointsToAnAge; //release memory

     cout <<"How many integers shall I reserve memory for?"<<endl;
     int numEntries =0;
     cin >>numEntries;

     int* myNumbers = new int[numEntries];
     cout <<"Memory allocated at: "<<myNumbers<<endl;
     //de-allocate before exiting
     delete[] myNumbers;

     return 0;
}
