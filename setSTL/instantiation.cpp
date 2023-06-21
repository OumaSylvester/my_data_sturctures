#include<set>
#include<iostream>

using namespace std;
//used as template parameter in set/multiset instantiation
template<typename T>
struct SortDescending
{
    bool operator()(const T& lhs, const T& rhs) const
    {
        return (lhs > rhs);
    }

};

template<typename T>
void DisplayContents(const T& Input)
{
    for(auto iElement = Input.cbegin(); iElement !=Input.cend(); ++iElement)
    {
        cout<<*iElement<<' ';

    }
    cout<<endl;
}
int main()
{
    // a simple set or multiset  of integers(using default sort predicate)
    set<int> setIntegers1; // a set of integers. Does not allow for duplicates
    multiset<int> msetIntegers1; //a multiset of integers >> allows for duplicates

    //set and multiset instantiated gieven a user defined sort predicate
    set<int, SortDescending<int>> setIntegers2;
    multiset<int, SortDescending<int>> msetIntegers2;

    //creating one set form another, or part of another container
   // set<int>setIntegers3(setIntegers1);
    //multiset<int>msetIntegers3(setIntegers1.cbegin(, setIntegers1.cend()));

    //inserting elements in a set/multiset
    setIntegers1.insert(60);
    setIntegers1.insert(-1);
    setIntegers1.insert(3000);
    setIntegers1.insert(43);
    setIntegers1.insert(124);
    setIntegers1.insert(78);

    cout<<"Writing the contents of the set to the screen"<<endl;
    DisplayContents(setIntegers1);

    msetIntegers1.insert(setIntegers1.begin(), setIntegers1.end());
    msetIntegers1.insert(3000);
    cout<<"Writing the contents of the multiset to the screen"<<endl;
    DisplayContents(msetIntegers1);

    cout<<"Number of instances of  '3000' in the multiset are: '";
    cout<<msetIntegers1.count(3000)<<"'"<<endl;

    //Try finding an element
    auto iElementFound = setIntegers1.find(-1);

    //Check if found
    if(iElementFound != setIntegers1.end())
        cout<<"Element "<<*iElementFound<<" found!"<<endl;
    else
        cout<<"Element not found in set!"<<endl;

    //Try finding another element
    auto iAnotherFind = setIntegers1.find(123434);

    //Check if found...
    if(iAnotherFind != setIntegers1.end())
        cout<<"Element "<<*iAnotherFind<<" found!"<<endl;
    else
        cout<<"Element 123434 not found in set!"<<endl;

    //Erasing elements in
    cout<<"Please a number to be erased from the set"<<endl;
    int nNumberToErase = 0;
    cin>>nNumberToErase;

    cout<<"Erasing "<<msetIntegers1.count(nNumberToErase);
    cout<< " instances of the "<<nNumberToErase<<endl;

    //Try finding an element
    msetIntegers1.erase(nNumberToErase);

    cout<<"multiset contains "<<msetIntegers1.size()<<" elements.";
    cout<<"These are: "<<endl;
    DisplayContents(msetIntegers1);
    return 0;
}
