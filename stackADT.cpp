#include<iostream>
using namespace std;

// This class species  the basic operations on a stsck
template <class Type>
class stackADT
{
public:
    virtual void initializeStack() = 0;
        // Method to initialize the stack to an empty state
        // Postcondition: Stack is empty

    virtual bool isEmptyState() const = 0;
        // Function to determine wether the stack is empty
        //Postcondition: Return true if the stck is empty
        //  otherwise return false.
    virtual bool isFullStack() const = 0; // find out abt this syntax
        //Function to determine wether stack if full
        //Postcondition:Return true if  the stack is full
        // otherwise return false.
    virtual void push(const Type&, newItem) = 0;
        //Function to add newItem to the stack
        //Precondition: The stack exists and its not full.
        //Postcondition: The stack is changed and newItem is added
        //to the top of the stack

    virtual Type top() const = 0;
        //Function to return the top element of the stack.
        //Precondition: The stack exists and is non-empty.
        //Postcondition: If the stack is empty, the program terminates; otherwise,
        //the top element of the stack is returned.

    virtual void pop() = 0;
        //Function to remove the top element of the stack.
        //Precondition: The stack exists and is non-empty.
        //Postcondition: The stack is changed and the top element is removed from
        //stack.
};



int main()
{

    return 0;
}
