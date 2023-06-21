#include<iostream>
#include<string>
#include "arrayADT.h"

using namespace std;

int main()
{
    arrayListType<int> intList(100); // initialize with a maximum 100 items
    arrayListType<string> stringList(20); //uses the default constructor with 100 initial items

    /*
    int num;
    cout<<"Enter numbers ending with -999:"<<endl;
    cin >> num;
    while(num != -999)
    {
        intList.insert(num);
        cin>>num;
    }

    cout<<"The list before sorting:"<<endl;
    intList.print();
    cout<<endl;

    intList.selectionSort();
    cout<<"The list after sorting:"<<endl;
    intList.print();
    cout<<endl;

    */

    int number;
    cout<<"Enter 5 integers: "<<endl;
    for(int counter=0; counter<5; counter++)
    {
        cin>>number;
        int return_val = intList.insert(number);
        if(return_val == -1)
            counter --;

    }

    cout<<endl;
    cout<<"The list you entered is: "<<endl;
    intList.print();
    cout<<endl;

   // cout<<"Enter item to be deleted: "<<endl;
   // cin>>number;
   // intList.remove(number);
    //cout<<"After removing "<<number<<" the list is:"<<endl;
    //intList.print();
    //cout<<endl;
    intList.insertionSort();
    cout<<"After insertion sort:"<<endl;
    intList.print();

    /*
    string str;

    cout<<"Enter 5 strings: "<<endl;
    for(int counter=0; counter<5; counter++)
    {
        cin>>str;
        stringList.insertAt(counter, str);
    }

    cout<<endl;
    cout<<"The list you entered is: "<<endl;
    stringList.print();
    cout<<endl;

    cout<<"Enter the string to be deleted: "<<endl;
    cin>>str;
    stringList.remove(str);
    cout<<"After removing "<<str<<", the list is:"<<endl;

    stringList.print();
    cout<<endl;
    */

    return 0;
}

