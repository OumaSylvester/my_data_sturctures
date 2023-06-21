#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vecIntegers;

    //insert
    vecIntegers.push_back(50);
    vecIntegers.push_back(1);
    vecIntegers.push_back(987);
    vecIntegers.push_back(1000);

    //Access objects in a vector using iterators:
    vector<int>::iterator iElementLocator = vecIntegers.begin();

    while(iElementLocator != vecIntegers.end())
    {
        size_t index = distance(vecIntegers.begin(), iElementLocator);
        cout<<"Element at position "<<index<<" is: "<<*iElementLocator<<endl;

        //move to the next element
        ++iElementLocator;
    }

    //Access elements using at()
    for(size_t index =0; index<vecIntegers.size(); index++)
    {
        cout<<"Element at["<<index<<"] = ";
        cout<<vecIntegers.at(index)<<endl; //at() checks at runtime to confirm if index is > the vector size
    }
    return 0;
}
