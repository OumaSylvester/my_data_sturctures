#include "queueADT.h"
#include<cassert>


template<class Type>
class queueType:public queueADT<Type>
{
    /*This class species the operations on a  queue as an array*/
public:
    const queueType<Type>& operator=(const queueADT<Type>& otherQueue)
    {
        //Overload the assignment operator
    }

    bool isEmptyQueue() const
    {
        //Function to determine whether the queue is empty.
        //Postcondition: Returns true if the queue is empty,
        // otherwise returns false.
        return(count == 0);
    }

    bool isFullQueue() const
    {
        //Function to determine whether the queue is full.
        //Postcondition: Returns true if the queue is full,
        // otherwise returns false.
        return(count == maxQueueSize);
    }

    void initializeQueue()
    {
        //Function to initialize the queue to an empty state.
        //Postcondition: The queue is empty.
        queueFront = 0;
        queueRear = maxQueueSize -1;
        count = 0;
    }

    Type front() const
    {
        //Function to return the first element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: If the queue is empty, the program
        // terminates; otherwise, the first element of the queue
        // is returned.
        assert(!isEmptyQueue());
        return list[queueFront];
    }

    Type back() const
    {
        //Function to return the last element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: If the queue is empty, the program
        // terminates; otherwise, the last element of the queue
        // is returned.
        assert(!isEmptyQueue());
        return list[queueRear];
    }

    void addQueue(const Type& newElement)
    {
        //Function to add queueElement to the queue.
        //Precondition: The queue exists and is not full.
        //Postcondition: The queue is changed and queueElement is
        // added to the queue.
        if(!isFullQueue())
        {
            queueRear = (queueRear + 1) % maxQueueSize; //Use modulus operator to
                                                        // advance queueRear because the
                                                        // the array is circular
            count ++;
            list[queueRear] = newElement;
        }
        else
            cout<<"Cannot add to a full queue."<<endl;
    }

    void deleteQueue()
    {
        //Function to remove the first element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: The queue is changed and the first element
        // is removed from the queue.
        if(!isEmptyQueue())
        {
            count--;
            queueFront = (queueFront) % maxQueueSize; // use the mod operator to
                                                        // advance the queueFront
                                                        // because the array is circular

        }
    }

    queueType(int queueSize=100)
    {
        //Constructor
        if(queueSize <= 0)
        {
            cout<<"Size of the array to hold the queue must be positive."<<endl;
            cout<<"Creating an array of size 100"<<endl;
            maxQueueSize = 100;
        }
        else
            maxQueueSize = queueSize; // set maximum maxQueueSize to queueSize
        queueFront = 0; // initialize queueFront
        queueRear = maxQueueSize -1; //initialize queueRear
        count = 0; // set count to 0
        list = new Type[maxQueueSize];  // create the array to hold the new elements
    }
    queueType(const queueType<Type>& otherQueue)
    {
        //Copy constructor
    }

    ~queueType()
    {
        //Destructor
        delete [] list;
    }

private:
    int maxQueueSize; // variable to store the maximum queue size
    int count; //variable to store the number of elements in the queue
    int queueFront; // variable to point to the first element of the queue
    int queueRear; // variable to point to the last element of the queue
    Type *list; // pointer to the array that holds the queue elements

};
