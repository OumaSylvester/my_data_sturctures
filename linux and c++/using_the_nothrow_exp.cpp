#include <iostream>
using namespace std;

int main()
{
    //Request LOTS of memory space, use nothrow
    int* pointsToManyNums = new(nothrow) int [0x1ffffffff];// returns NULL if allocation fails

    if(pointsToManyNums) //check pointsToManyNums != NULL
    {
        // Use te allocated memory
        cout<<"Momory has been consumed"<<endl;
        delete[] pointsToManyNums;
    }
    else
        cout<<"Memory allocation failed. Ending program"<<endl;
    return 0;
}
