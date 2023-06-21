#include<vector>
#include<iostream>

using namespace std;

void DisplayVector(const vector<int>& vecInput)
{
    for(auto iElement = vecInput.cbegin(); iElement != vecInput.cend(); ++iElement)
    {
        cout<<*iElement<<' ';
    }
    cout<<endl;

}

int main()
{
    //Instantiate a vector with 4 elements, each initialized to 90
    vector<int> vecIntegers(4, 90);
    cout<<"The initial contents of the vector: ";
    DisplayVector(vecIntegers);

    //Insert 25 at the beginning
    vecIntegers.insert(vecIntegers.begin(), 25);

    //Insert 2 numbers of value 45 at the end
    vecIntegers.insert(vecIntegers.end(), 2, 45); // overloaded to accept number  of elements to add

    cout<<"Vector after inserting values at beginning and the end: "<<endl;
    DisplayVector(vecIntegers);

    //Another vector containing 2 elements of value 30
    vector<int> anotherVec(2, 30);

    //Insert two elements from another container in position
    vecIntegers.insert(vecIntegers.begin() + 1, anotherVec.begin(), anotherVec.end());

    cout<<"vector after inserting contents from another vector in the middle: "<<endl;
    DisplayVector(vecIntegers);

    return 0;
}
