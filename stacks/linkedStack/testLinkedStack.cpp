/*This program tests various operations of a linked stack*/

#include<iostream>
#include "linkedStack.h"

using namespace std;

void testCopy(linkedStackType<int> otherStack);

int main()
{
    linkedStackType<int> myStack;
    linkedStackType<int> otherStack;
    linkedStackType<int> newStack;

    // add elements into stack
    myStack.push(34);
    myStack.push(43);
    myStack.push(27);

    // USe the assignment operator to copy myStack
    newStack = myStack;
    cout<<"After the assignment operator,newStack: "<<endl;

    //output the elements of newStack
    while(!newStack.isEmptyStack())
    {
        cout<<newStack.top()<<endl;
        newStack.pop(); // you must pop in order to get the next element
    }

    // use the assignment operator to copy the elements of myStack into otherStack
    otherStack = myStack; // copy constructor used
    testCopy(otherStack);
    cout<<"After the copy constructor, otherStack: "<<endl;
    while(!otherStack.isEmptyStack())
    {
        cout<<otherStack.top()<<endl;
        otherStack.pop();

    }
    return 0;

}

// Function to test the copy constructor
void testCopy(linkedStackType<int> otherStack)
{
    cout<< "Stack in the function testCopy:"<<endl;
    while(!otherStack.isEmptyStack())
    {
        cout<<otherStack.top()<<endl;
        otherStack.pop();
    }
}
