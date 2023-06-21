#include<iostream>
#include "ordered_linked_list.h"

using namespace std;

int main()
{
    orderedLinkedList<int> list1, list2;
    int num;

    cout<<"Line 7: Enter numbers ending with -999."<<endl;
    cin>>num;

    while(num != -999)
    {
        list1.insert(num);
        cin>>num;
    }
    cout<<endl;

    cout<<"Line 1: ";
    list1.print();
    cout<<endl;

    list2 = list1; //test the assignment operator
    cout<<"Enter the number to be deleted: "<<endl;
    cin>>num;
    cout<<endl;

    list2.deleteNode(num);

    cout<<"After deleting "<<num<<", list2: "<<endl;
    list2.print();
    cout<<endl;

    return 0;
}
