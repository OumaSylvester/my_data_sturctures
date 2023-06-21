//#include<iostream>
#include "linked_list_iterator.h"

using namespace std;

template<class Type>
class linkedListType
{
    /*This class specifies the members implement the basic properties of a
    linked list. This is an abstract class*/
public:
    const linkedListType<Type>& operator = (const linkedListType<Type>& otherList)
    {
        // Overload the assignment operator
        if(this != &otherList) // avoid self-copy
        {
            copyList(otherList);
        }
        return *this;

    }

    void initializeList()
     {
         //Initializes the list to any empty state.
        // Postcondition: first = NULL, last=NULL, count = 0;
        // this function uses destroyList() which is of O(n) hence this is O(n) too
        destroyList(); //if the list has any nodes, delete them.
     }
    bool isEmpyList() const
    {
         //Function to determine determine whether the list is empty
        //Postcondition: Returns true if the list is empty, otherwise it returns false
       return(first == NULL);

    }

    void print() const
       {
            //Function to output the data contained in each node
            //Postcondition: none
           // we must traverse the list using the first list
            nodeType<Type> *current; // pointer to traverse the list
            current = first;
            while(current != NULL) // while more data to print
            {
                cout<<current->info<<" ";
                current = current->link;
            }
        // rem if we use the first node we would lose the whole list
        // this function is all of O(n)

       }

    int length() const
    {
        // Function to return the number of nodes in a list
        //Postcondition: The value of count is returned
        // How many nodes are in the list is stored in variable count
        return count;
    }


    void destroyList()
     {
       //Function to delete all the nodes from the list.
        //Postcondition: first = NULL, last = NULL, count =0;
        nodeType<Type> *temp; // pointer to deallocate memory occupied by the node
        while(first != NULL)
        {
            temp = first;
            first = first->link; // advance first to next
            delete temp; // deallocate memory occupied by temp. Delete sets to NULL
        }
        last = NULL;  //initialize last to NULL; first has already been set to NULL by
        // the while loop
        count = 0;
     }
    Type front() const
    {
        //Function to return the first element of the list.
        //Precondition: The  list must exist and must not be empty
        //Postcondition: If the list is empty the function terminates;
        // otherwise, the first element of the list is returned
        // Returns the info contained in the first node
        assert(first != NULL); // is the list is empty the asset terminates the program
        return first->info; // return the info of the first node

    }

    Type back() const
     {
          // Function to return the last element of the list
        //Precondition: The list must exist and not empty.
        //Postcondition: If the list is empty the function terminates;
        // otherwise, the last element of the list is returned
        assert(last != NULL);
        return last->info; // return info of the last node
        // O(1)

     }

    virtual bool search(const Type& searchItem) const = 0;
        //Function to determine weather searchItem is in the list
        //Postcondition: Returns true if search item is in the list,
        // false otherwise

    virtual void insertFirst(const Type& newItem) =0;
        //Function to insert newItem at the beginning of the list.
        //Postcondition: first points to the new list, newItem is inserted
        //at the beginning of the list, last points to the last node in the list,
        //and count is incremented by 1.
    virtual void insertLast(const Type& newItem) = 0;
        //Function to insert newItem at the end of the list.
        //Postcondition: first points to the new list, newItem is
        // inserted at the end of the list, last points to the
        // last node in the list, and count is incremented by 1

    virtual void deleteNode(const Type& deleteItem) = 0;
        // Function to delete deleteItem in the list;
        //Postcondition: If found, the node containing the deleteItem
        // is deleted from the list. first points the fist node, last points to
        // last node of the updated list, and count is decremented by 1

    linkedListIterator<Type> begin()
    {
    // Function to return an iterator at the beginning of the
    // linked list.
    //Postcondition: Returns an iterator such that current is set to first
        linkedListIterator<Type> temp(first);
        return temp;

    }


    linkedListIterator<Type> end()
    {
        //Function to return an iterator one element past the
        // last element of the linked list
        //Postcondition: Returns an iterator such that last is set to NULL
        // O(1)
        // returns an iterator to the last node in the  list
        linkedListIterator<Type> temp(NULL);
        return temp;
    }


    linkedListType()
     {
         //default constructor
        // Initializes the list to an empty state
        //Postcondition: first = NULL, last = NULL, count = 0;
        first = NULL;
        last = NULL;
        count =0;
     }
    linkedListType(const linkedListType<Type>& otherlist)
    {
         //copy constructor
         //because our class contains pointer data members we will need
         // to define our own copy constructor to ensure deep copy
         // the copy  constructor makes an identical copy of the linked list.
         // This can be done by calling the copyList()
         // we must first set first to NULL before calling the function copyList
         first = NULL;
         copyList(otherlist);
    }


    ~linkedListType()
    {
        // destructor
        // Deletes all the nodes from the list
        //Postcondition: The list object is destroyed
        //we must traverse each node in the list and deallocate memory occupied
        // by the nodes. This can be done by calling the destroyList()
        destroyList();

    }

protected:
    int count;  // variable to store the number  list elements
    nodeType<Type> *first; // pointer to the first node of the list. Protected not private to allow inherited classes to use them directly
    nodeType<Type> *last; // pointer to the last node of the list

private:
    void copyList(const linkedListType<Type>& otherlist)
    {
        //Function to make a copy otherlist
        //Postcondition: A copy of other list is created and assigned to this list.
        nodeType<Type> *newNode; // pointer to create a node
        nodeType<Type> *current; // pointer to traverse the  list

        if(first != NULL) // if  the list is nonempty, empty it
            destroyList();

        if(otherlist.first == NULL) //otherlist is empty
        {
            first = NULL;
            last = NULL;
            count = 0;
        }
        else
        {
            current = otherlist.first; //current points to the list to be copied
            count = otherlist.count;

            // copy the first node
            first = new nodeType<Type>; //create the node
            first->info = current->info; // copy the node
            first->link=NULL; // set the link field of the node toNULL
            last = first; // make last point to the first node
            current = current->link; // make current point to the next node

            // copy the remaining list
            while(current != NULL)
            {
                newNode = new nodeType<Type>; // create a node
                newNode->info = current->info; // copy the info
                newNode->link = NULL; //set the link of the newNode to NULL
                last->link = newNode; //attach newNode after last
                last = newNode; // make last point to the actual last node
                current = current->link; // make current point to the next node
            }
        }

    }

};



