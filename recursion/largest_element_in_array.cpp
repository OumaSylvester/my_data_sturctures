#include <iostream>

using namespace std;

int largestElementByRecursion(const int listInt[], int lowerIndex, int upperIndex)
{
    int max;
    if(lowerIndex == upperIndex)
        return listInt[lowerIndex];
    else
    {
        max = largestElementByRecursion(listInt, lowerIndex +1, upperIndex);
        if(listInt[lowerIndex] >= max)
            return listInt[lowerIndex];
        else
            return max;
    }
}

int main()
{
    int test[5] = {81,263,94,65, 1};
    cout<<"Largest: "<<largestElementByRecursion(test, 0, 4)<<endl;
    return 0;
}
