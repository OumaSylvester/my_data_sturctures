#include<list>
#include<vector>
#include<iostream>

using namespace std;

template<typename T>
void DisplayContents(const T& Input)
{
    for(auto iElement = Input.cbegin(); iElement != Input.cend(); ++iElement) //use an iterator cbegin() and cend()
        cout<<*iElement<<' ';
    cout<<endl;
}

// my binary predicate sort algorithm
bool SortPredicate_Descending(const int& lsh, const int& rsh)
{
    //define criteria for list::sort,  return true for desired order
    return(lsh > rsh);
}

int main()
{

    //Instantiate and empty list
    list<int> listIntegers;

    //instantiate a list with 10 integers
    list<int> listWith10Integers(10);

    //instantiate a list with 4 integers, each initialized to 99
    list<int> listWith4IntegerEach99(4, 99);

    //create an exact copy of existing list
    list<int> listCopyAnother(listWith4IntegerEach99);

    //a vector with 10 integers, each 2011
    vector<int> vecIntegers(10, 2011);

    //instantiate a list using values from another container
    list<int> listContainsCopyofAnother(vecIntegers.cbegin(), vecIntegers.cend());

    listIntegers.push_front(10);
    listIntegers.push_front(2021);
    listIntegers.push_back(-1);
    listIntegers.push_back(9999);

    DisplayContents(listIntegers);

    //Inserting element to a list using insert

    //inserting an element at the beginning...
    listIntegers.insert(listIntegers.begin(), 2);
    listIntegers.insert(listIntegers.begin(), 1);

    //Inserting an element at the end...
    listIntegers.insert(listIntegers.end(), 3);

    cout<<"The contents of list 1 after inserting elements:"<<endl;
    DisplayContents(listIntegers);

    list<int> listIntegers2;

    //inserting 4 elements of the same value 0 ...
    listIntegers2.insert(listIntegers2.begin(), 4, 0);

    cout<<"The contents of list 2 after inserting ";
    cout<<listIntegers2.size()<<" elements of a value:"<<endl;
    DisplayContents(listIntegers2);

    list<int> listIntegers3;

    //Inserting elements from another list at the beginning..
    listIntegers3.insert(listIntegers3.begin(), listIntegers.begin(), listIntegers.end());

    cout<<"The contents of list 3 after inserting the contents of ";
    cout<< " list 1 at the beginning:"<<endl;
    DisplayContents(listIntegers3);


    //Inserting elements from another list at the end..
    listIntegers3.insert(listIntegers3.end(), listIntegers2.begin(), listIntegers2.end());
    cout<<"The contents of list 3 after inserting contents of list 2 at the end:";
    DisplayContents(listIntegers3);

    //Erasing elements from a list
    //Store an iterator obtained in suing the 'insert' function
    //auto iValue2 = listIntegers.insert(listIntegers.begin(), 2);
    //cout<<endl<<endl<<endl;
    //cout<<"Initial contents of the list:"<<endl;
    //DisplayContents(listIntegers);
    //listIntegers.erase(listIntegers.begin(), iValue2);
    //cout<<"Contents after erasing a range of elements:"<<endl;
    //DisplayContents(listIntegers);

    //cout<<"After erasing element"<<*iValue2<<":"<<endl;
    //listIntegers.erase(iValue2);
    //DisplayContents(listIntegers);

    //listIntegers.erase(listIntegers.begin(), listIntegers.end());
    //cout<<"Number of elements after erasing range: ";
    //cout<<listIntegers.size()<<endl;

    //Reversing and sorting Elements in a List

    cout<<endl<<endl<<endl;
    cout<<"Initial contents of the list:"<<endl;
    DisplayContents(listIntegers);

    listIntegers.reverse(); // ensures that iterators pointing to elements
    // in the list, if kept by the programmer, remain valid even after reversal

    cout<<"Contents of the list after using reverse():"<<endl;
    DisplayContents(listIntegers);

    cout<<endl<<endl<<endl;
    //Sorting Elements
    cout<<"Initial contents of the list are - "<<endl;
    DisplayContents(listIntegers);

    listIntegers.sort();

    cout<<"Order of elements after sort():"<<endl;
    DisplayContents(listIntegers);

    listIntegers.sort(SortPredicate_Descending);
    cout<<"Order of elements after sort() with a predicate(Descending): "<<endl;
    DisplayContents(listIntegers);
    //using my own binary predicate function as a parameter

    return 0;
}
