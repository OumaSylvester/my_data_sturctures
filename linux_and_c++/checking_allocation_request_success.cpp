#include <iostream>
using namespace std;

// remove te try-catch block to see this application crash

int main()
{
    try
    {
        //Request a LOT of memory!
        int* pointsToManyNums = new int [0x1fffffffff];
        // Use the allocated memory
        cout<<"Memory allocation was succesfull"<<endl;
        delete [] pointsToManyNums;
    }
    catch(bad_alloc)
    {
        cout<<"Memory allocation failed. Ending program"<<endl;
    }

    return 0;
}
