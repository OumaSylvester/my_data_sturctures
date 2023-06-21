#ifndef H_StackType
#define H_StackType

#include<iostream>
#include<cassert>
#include "stackADT.h"

using namespace std;
template<class Type>
class stackType: public stackADT<Type>
{
public:
    const stackType<Type>& operator=(const stackType<Type>& otherStack)
    {
        //overload the assignment operator. This has to been as long as your object
        // has  a pointer member variable to ensure deep copy in case of any copying operation
        if(this != &otherStack) // avoid self copy to save cpu time
            copyStack(otherStack);
        return *this;
    }

    void initializeStack()
    {
        //Function to initialize the stack to an empty state.
        //Postcondition: stackTop = 0;
        // Because the member variable stackTop indicates whether the stack is empty
        // we can simply set stackTop to 0 initialize the stack
        stackTop = 0;

    }

    bool isEmptyStack() const
    {
        return(stackTop == 0);
    }

    bool isFullstack() const
    {
        return (stackTop == maxStackSize);
    }

    void push(const Type& newItem)
    {
        if(!isFullstack())
        {
            list[stackTop] = newItem; // add new item at the top
            stackTop++; // increment stackTop
        }
        else
            cout<<"Cannot add to a full stack";
    }

    Type top() const
    {
        assert(stackTop != 0); // is the stack is empty, the program terminates
        return list[stackTop -1]; // return the element of the stack indicated by
                                    // stackTop -1
    }

    void pop()
    {
        if(!isEmptyStack())
            stackTop--;
        else
            cout<<"Cannot remove from an empty stack";
    }

    stackType(int stackSize)
    {
        //Constructor
        //Create an array of the size stackSize to hold the stack elements.
        // The default stack size is 100.
        //Postcondition: The variable list contains the base address of the array,
        // stackTop=0, and maxStackSize=stackSize
        if(stackSize <= 0)
        {
            cout<<"Size of the array to hold the stack be positive."<<endl;
            cout<<"Creating an array of size 100.";
            maxStackSize = 100;
        }
        else
            maxStackSize = stackSize; // set the stack size to the  value specified
                                        // by the parameter stackSize
        stackTop = 0; // set stackTop to 0
        list = new Type[maxStackSize]; // create array to hold stack members

    }
    stackType(const stackType<Type>& otherStack)
    {
        //Copy constructor
        list = NULL;
        copyStack(otherStack);
    }

    ~stackType()
    {
        //Destructor
        //Remove all the elements from the stack.
        //Postcondition: The array(list) holding the stack is deleted
        delete[] list;// deallocate memory occupied by the array
    }

private:
    int maxStackSize;  //variable to store maximum stack size
    int stackTop; // variable to point to the top of the stack
    Type *list; //pointer to the array that holds the stack elements

    void copyStack(const stackType<Type>& otherStack)
    {
        // Function to make a copy of otherStack
        //Postcondition: A copy of otherStack is created and is assigned to this stack
        delete [] list;
        maxStackSize = otherStack.maxStackSize;
        stackTop = otherStack.stackTop;

        list = new Type[maxStackSize];
        // copy other stack into this stack
        for(int i=0; i<stackTop; i++)
            list[i] = otherStack.list[i];
    }
};

#endif
