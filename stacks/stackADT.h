template<class Type>
class stackADT
{
public:
    virtual void initializeStack()
    {
        //Method to initialize the stack into an empty list
        //Postcondition: Stack is empty
    }


    virtual bool isEmptyStack() const
    {
        // Function to determine whether the stack is empty
        //Postcondition: Returns true if the stack is empty, otherwise returns false

    }
    virtual bool isFullStack() const
    {
        // Function to determine whether the stack is full
        //Postcondition: Returns true if the stack is full, otherwise returns false
        //return;
    }

    virtual void push(const Type& newItem)
    {

        //Function to add newItem to the stack
        //Precondition: The stack exists and is not full
        //Postcondition: The stack is changed and newItem is added to the top of the
        // stack
    }


    virtual Type top() const
    {
        //Function to return  the top element of the stack
        //Precondition: The stack exists and is not empty
        //Postcondition:If the is empty, the program terminates; otherwise, the top
        // element of the stack is returned
        //return;
    }

    virtual void pop()
    {
        //Function to remove the top element of the stack
        //Precondition: The stack is exists and is not empty.
        //Postcondition: The stack is changed and the top element
        // is removed from the stack
    }

};
