#include<iostream>
#include "stackArray.h"

using namespace std;

void testCopyConstructor(stackType<int> otherStack);

int main()
{
    stackType<int> mystack(50);
    stackType<int> copyStack(50);
    stackType<int> dummyStack(100);

    mystack.initializeStack();
    mystack.push(23);
    mystack.push(45);
    mystack.push(38);
    copyStack = mystack; // copy stack1 into copyStack

    cout<<"The elements of copyStack: ";
    while(!copyStack.isEmptyStack()) // print copyStack
    {
        cout<<copyStack.top()<<" ";
        copyStack.pop();
    }
    cout<<endl;

    copyStack = mystack;
    testCopyConstructor(mystack); // test the copy constructor

    if(!mystack.isEmptyStack())
        cout<<"The original stack is not empty"<<endl<<"The top element of the original stack: "
            <<copyStack.top()<<endl;
    dummyStack = mystack; // copy mystack into dummyStack
    cout<<"The elements of dummyStack: "<<endl;
    while(!dummyStack.isEmptyStack()) //print dummyStack
    {
        cout<<dummyStack.top()<<" ";
        dummyStack.pop();
    }
    cout<<endl;
    return 0;

}

void testCopyConstructor(stackType<int> otherStack)
{
    if(!otherStack.isEmptyStack())
        cout<<"otherStack is not empty."<<endl<<"Th top element otherStack: "
        << otherStack.top()<<endl;
}
