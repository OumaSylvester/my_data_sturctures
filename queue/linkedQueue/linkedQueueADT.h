/**This class specifies the basic operations on a queue as a linked list/*/

#include "../queueADT.h"
#include <cassert>
#include<iostream>

using namespace std;


//Definition of the node
template<class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

//Definition of the linkedQueueType class
template<class Type>
class linkedQueueType: public queueADT<Type>
{
public:
    const linkedQueueType<Type>& operator= (const linkedQueueType<Type>& otherQueue)
    {
        //Overload the assignment operator.
        if(this != &otherQueue) // avoid self copy to save CPU time
            copyQueue(otherQueue);
        return *this;
    }

    bool isEmptyQueue() const
    {
        //Function to determine whether the queue is empty.
        //Postcondition: Returns true if the queue is empty,
        // otherwise returns false.
        return(queueFront == NULL);
    }
    bool isFullQueue() const
    {
        //Function to determine whether the queue is full.
        //Postcondition: Returns true if the queue is full,
        // otherwise returns false.
        return false ; //Since memory is allocated dynamically the queue is full only if the program runs out of memory.
    }

    void initializeQueue()
    {
        nodeType<Type> *temp;
        while(queueFront != NULL) //while there are elements left in the queue
        {
            temp = queueFront; // set temp to current node
            queueFront = queueFront->link; // advance first to the next node

            delete temp; // deallocate memory occupied by temp
        }
        queueRear = NULL; // set rear to NULL
    }

    Type front() const
    {
        //Function to return the first element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: If the queue is empty, the program
        // terminates; otherwise, the first element of the
        // queue is returned.
        assert(queueFront != NULL);
        return queueFront->info;
    }


    Type back() const
    {
        //Function to return the last element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: If the queue is empty, the program
        // terminates; otherwise, the last element of the
        // queue is return
        assert(queueRear != NULL);
        return queueRear->info;
    }

    void addQueue(const Type& newElement)
    {
        //Function to add queueElement to the queue.
        //Precondition: The queue exists and is not full.
        //Postcondition: The queue is changed and queueElement is
        // added to the queue.
        nodeType<Type>* newNode; // pointer to new node
        newNode = new nodeType<Type>; // Create the node
        newNode->info = newElement;
        newNode->link = NULL;

        if(queueFront == NULL)
        {
            queueFront = newNode;
            queueRear= newNode;
        }
        else
        {
            queueRear->link=newNode; // link the second last node to the last node. The second last node is currently held in queueRear
            queueRear = queueRear->link; // set queueRear to the exact last node in the queue
        }

    }

    void deleteQueue()
    {
        //Function to remove the first element of the queue.
        //Precondition: The queue exists and is not empty.
        //Postcondition: The queue is changed and the first element
        // is removed from the queue.
        nodeType<Type> *temp;

        if(!isEmptyQueue())
        {
            temp = queueFront; // make temp point to the first node
            queueFront = queueFront->link; // advance queueFront to the next node

            delete temp; // delete the first node(deallocate memory)

            if(queueFront == NULL) // is there was only one element in the queue.
                //Like no next element in the queue. If after deletion the queue is empty
                queueRear = NULL; //set queueRear to NULL
        }
        else
            cout<<"Cannot delete from an empty queue"<<endl;
    }

    linkedQueueType()
    {
        //Default constructor
        queueFront = NULL; // Set queueFront to NULL
        queueRear = NULL; // Set queueRear to NULL
    }

    linkedQueueType(const linkedQueueType<Type>& otherQueue)
    {
        //Copy constructor
        queueFront = NULL;
        copyQueue(otherQueue); // copy queue
    }

    ~linkedQueueType()
    {
        //Destructor
        initializeQueue(); // deallocate all the memory if the queue goes out of scope
    }
private:
    nodeType<Type> *queueFront; // pointer to the front of the queue
    nodeType<Type> *queueRear; // pointer to the rear element of the queue

    void copyQueue(const linkedQueueType<Type>& otherQueue)
    {
        nodeType<Type> *newNode,*current; // current is used to hold the current node, the newNode  will  temporarily store the last node copied

        if(queueFront != NULL) // if our first node is not empty, empty it
            initializeQueue(); // empty the queue, deallocating all the memory
        if(otherQueue.queueFront == NULL)
            queueFront = NULL;
        else
        {
            current = otherQueue.queueFront; // set to the first node of otherStack
            queueFront->info = current->info; // set our first node info to current info
            queueFront->link = NULL; // set our first node link to NULL
            queueRear = queueFront; // set the last node in the queue to point to the first

            current = current->link; // then advance current to the next node

            while(current != NULL) // while not in the last node of  otherQueue
            {
                newNode = new nodeType<Type>; // allocate memory to the newNode. To be used to temporarily represent the last node
                newNode->info = current->info; // // set newNode it info to current info
                newNode->link = NULL; // set it link to NULL since it represents the last node in the queue at the moment

                queueRear->link = newNode; // set our last node queueRear to point to new node. That means it won't be the las node anymore but the last node
                queueRear = newNode; // set our last node to newNode

                current = current->link; //advance the current to the next in the otherQueue

            }


        }
    }
};
