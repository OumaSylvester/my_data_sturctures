#include<iostream>
#include<cassert>
#include "../stackADT.h"
//This class specifies the basic operation on a stack as a linked list
using namespace std;
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template<class Type>
class linkedStackType: public stackADT<Type>
{
public:

    const linkedStackType<Type>& operator=(const linkedStackType<Type>& otherStack)
    {
        //Function to overload the assignment operator
        if(this != &otherStack) //avoid self-copy
            copyStack(otherStack);
        return *this;
    }

    bool isEmptyStack() const
    {
        //Function to determine whether stack is empty.
        //Postcondition: Returns true if the stack is empty; otherwise false
        return(stackTop==NULL );
    }
    bool isFullStack() const
    {
        //Function to determine if the stack is full.
        //PostCondition: Returns falls
        // stack is never full because memory is allocated dynamically
        return false;
    }
    void initializeStack()
    {
       //Function to initialize the  stack to an empty list.
       //Postcondition: The stack elements are removed
       // stackTop = NULL;
       nodeType<Type>* temp; // pointer to delete the node
       while(stackTop != NULL) // while there are elements in the stack
       {
           temp  = stackTop; // set temp to point to the current node
           stackTop = stackTop->link; // advance the stackTop to the next node
           delete temp; // deallocate memory occupied by temp
       }
    }

    void push(const Type& newItem)
    {
        //Function to add newItem to the stack
        //Precondition: Stack exists and is not full
        //Postcondition: The stack is changed and newItem is added to the top
        // of the stack
        nodeType<Type>* newNode; // pointer to create a new node
        newNode = new nodeType<Type>; // create the node
        newNode->info = newItem; // store newElement in the node
        newNode->link=stackTop; // insert a new node b4 stackTop
        stackTop=newNode;  //set the stackTop to point to the newnode
    }

    Type top() const
    {
        //Function to return the top element of the stack
        //Precondition: Stack exists and is not empty
        //Postcondition: If the stack is empty, the program terminates; otherwise
        // the top element of the stack is returned
        assert(stackTop != NULL);  //is stack is empty, terminate the program
        return stackTop->info; //return the top element

    }
    void pop()
    {
        // Function to remove the top element of the stack
        //Precondition: Stack exists and is not empty
        //Postcondition: Stack is changed  and top element is removed from the stack

        nodeType<Type>* temp; //pointer to deallocate memory
        if(stackTop != NULL)
        {
            temp = stackTop; //set temp to point to the top node
            stackTop = stackTop->link; // advance the stackTop to the next node
            delete temp; //delete the top node
        }
        else
            cout<<"Cannot remove from and empty stack."<<endl;
    }
    linkedStackType()
    {
        //Default constructor
        //Initializes the stack to an empty state when the stack is declared
        //Postcondition:
        stackTop=NULL;
    }
    linkedStackType(const linkedStackType<Type>& otherStack)
    {
        //Copy constructor
        stackTop = NULL;
        copyStack(otherStack);

    }
    ~linkedStackType()
    {
        //Destructor
        //Postcondition: all the elements of the stack are removed
        initializeStack();
    }

private:
    nodeType<Type>* stackTop; // pointer to the stack

    void copyStack(const linkedStackType<Type>& otherStack)
    {
        //Function to copy the elements of otherStack to this stack
        //Postcondition: a copy of otherStack is made is assigned to this stack
        nodeType<Type> *newNode, *current, *last;
        if(stackTop != NULL) // if stack is non-empty make it empty
            initializeStack();
        if(otherStack.stackTop == NULL)
            stackTop = NULL;
        else
        {
            current = otherStack.stackTop; // make current to point to the stack to
                                            // to be copied
            // copy the stackTop element of the stack
            stackTop = new nodeType<Type>; // create the node
            stackTop->info = current->info; // copy the info
            stackTop->link = NULL; // set the link field to NULL
            last = stackTop; //set last to point to the node
            current = current->link; // set current to point to the next node

            //copy the remaining stack
            while(current != NULL)
            {
                newNode = new nodeType<Type>;
                newNode->info = current->info;
                newNode->link =NULL;
                last->link = newNode;
                last = newNode;
                current = current->link;
            }//end while
        }// end else
    }// end copyStack
};
