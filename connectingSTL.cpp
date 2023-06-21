#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
    // A dynamic array of integers
    vector<int> vecIntegerArray;

    //Insert sample integers into the array
    vecIntegerArray.push_back(50);
    vecIntegerArray.push_back(299);
    vecIntegerArray.push_back(23);
    vecIntegerArray.push_back(999);

    cout<<"The contents of the vector are: "<<endl;

    //Walk the vector and read values using an iterator
    vector<int>::iterator iArrayWalker = vecIntegerArray.begin();
    //auto iArrayWalker = vecIntegerArray.begin(); // compiler detects type

    while(iArrayWalker != vecIntegerArray.end())
    {
        // Write the value to the screen
        cout<<*iArrayWalker <<endl;

        //Increment the iterator to access the next element
        ++ iArrayWalker;
    }
    //Find an element(say 299) in the array using the'find' algorithm
    vector<int>::iterator iElement = find(vecIntegerArray.begin(), vecIntegerArray.end(), 299);
    //Check if the value was found
    if(iElement != vecIntegerArray.end())
    {
        //Value was found... Determine position in the array:
        int Position = distance(vecIntegerArray.begin(),iElement);
        cout<<"Value "<<*iElement;
        cout<<" found in the vector at position: "<<Position<<endl;
    }


    return 0;
}
