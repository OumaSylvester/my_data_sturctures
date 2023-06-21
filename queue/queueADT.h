

template <class Type>
class queueADT
{
    /*This class defines a queue as an abstract data structure*/
public:
    virtual bool isEmptyQueue() const
    {
        //Function to determine whether the queue is empty.
        //Postcondition: Returns true if the queue is empty,
        // otherwise returns false.
    }

    virtual bool isFullQueue() const
    {
        //Function to determine whether the queue is full.
        //Postcondition: Returns true if the queue is full,
        // otherwise returns false.
    }

    virtual void initializeQueue()
    {
        //Function to initialize the queue to an empty state.
        //Postcondition: The queue is empty.
    }

    virtual Type front() const
    {
        //Function to return the first element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: If the queue is empty, the program
        // terminates; otherwise, the first element of the queue
        // is returned.
    }

    virtual Type back() const
    {
        //Function to return the last element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: If the queue is empty, the program
        // terminates; otherwise, the last element of the queue
        // is returned.
    }

    virtual void addQueue(const Type& queueElement)
    {
        //Function to add queueElement to the queue.
        //Precondition: The queue exists and is not full.
        //Postcondition: The queue is changed and queueElement is
        // added to the queue.
    }

    virtual void deleteQueue()
    {
        //Function to remove the first element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: The queue is changed and the first element
        // is removed from the queue.
    }

};
