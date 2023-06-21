#include "linked_list.h"
using namespace std;

template<class Type>
class unorderedLinkedList: public linkedListType<Type>
{
public:

    /* Implement the operations search, insertFirst, insetLast and deleteNode
    which are different for unordered and ordered linked list
    */
    bool search(const Type& searchItem) const
    {
        // Function to determine whether searchItem is in the list
        //Postcondition: Returns true if searchItem is in the list, otherwise false
        nodeType<Type> *current; // pointer to traverse the list
        bool found = false;

        current = first; // set current to point to the first node in the list
        while(current != NULL && !found) // search the list

            if(current->info == searchItem) // search item is found
                found = true;
            else
                current = current->link; // make current point to the next node

        return found;
    }

    void insertFirst(const Type& newItem)
    {
        // Function to insert newItem at the beginning of the list
        //Postcondition: first points to the new list, newItem is inserted
        // at the beginning of the list, last points to the last node, and count
        // is incremented by 1
        nodeType<Type> *newNode; // pointer to create the new node
        newNode = new nodeType<Type>; // create the new node
        newNode->info = newItem; // store the newItem in the node
        first = newNode; //make first point to the actual first node
        count++; // increment
        if(last == NULL) // if the list was empty, newNode is also the last node in the list
            last = newNode;
    }

    void insertLast(const Type& newItem)
    {
        //Function to insert newItem at the end of the list.
        //Postcondition: first points to the new list, newItem is
        // inserted at the end of the list, last points to the
        // last node, and count is incremented by 1
        nodeType<Type> *newNode; // pointer to create the new node
        newNode = new nodeType<Type>; // create the new node
        newNode->info = newItem; //store the newItem in the node
        newNode->link = NULL; //set the link field of the newNode to NULL

        if(first == NULL) // if the list is empty, newNode is both the first and last node
        {
            first = newNode;
            last = newNode;
            count++; //increment count
        }
        else //the list is not empty, insert the newNode after the last
        {
            last->link = newNode; //insert newNode after the last
            last = newNode; // make last point to the actual last node in the list
            count++;
        }

    }
    void deleteNode(const Type& deleteItem)
    {
        // Function to delete deleteItem from from the list
        //Postcondition: If found, the node containing deleteItem
        // is deleted from the list. first points to the fist node, last
        // points to the last node of the updated list, and count is decremented by 1
        nodeType<Type> *current; // pointer to traverse the list
        nodeType<Type> *trailCurrent; // pointer just before current
        bool found;

        if(first == NULL) // The list is empty
            cout<<"Cannot delete from an empty list."<<endl;
        else
        {
            if(first->info == deleteItem) // node to be deleted is the first node
            {
                current = first;
                first = first->link;
                count--;

                if(first == NULL) // the list has only one node
                    last = NULL;

                delete current;
            }
            else // search the list for node with the given info
            {
                found = false;
                trailCurrent = first; // set trailCurrent to point to the first node in the list

                current = first->link; //set current to point to the next node in the list

                while(current != NULL && !found)
                {
                    if(current->info != deleteItem)
                    {
                        trailCurrent = current;
                        current = current->link;
                    }
                    else
                        found = true;
                }
                if(found) // if found delete the node
                {
                    trailCurrent->link = current->link;
                    count--;

                    if(last == current) // node to be deleted was the last node
                        last = trailCurrent; // update the value of the last
                    delete current
                }
                else
                    cout<<"The item to be deleted is not in the list."<<endl;
            }
        }
    }

};
