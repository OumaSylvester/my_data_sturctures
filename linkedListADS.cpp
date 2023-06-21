#include<iostream>
using namespace std;

// Definition of the node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link; // Pointer to the next node
};
// This class specifies the members to implement an iterator to a linked list.
template <class Type>
class linkedListIterator
{
    /*Traversing the list from the first node. Enables you to process each node of the
    list.An iterator is an object so we will define this class linkedListIterator, to
    create iterators to the objects of class linkedListType.
    The iterator class would have one member variable pointing to (the current) node.
    */
public:
    linkedListIterator()
    {
    //Default constructor
    //Postcondition: current = NULL
    current = NULL;
    }

    linkedListIterator(nodeType<Type> *ptr)
    {
        // Constructor with a parameter.
        //Postcondition: current = ptr

        current = ptr;
    }

    Type operator*()
    {
        //Function to overload the dereferencing  operator *.
        //Postcondition: Returns the info contained in the node
        return current ->info;

    }
    linkedListIterator<Type> operator ++()
    {
        // overload the preincrement operator
        //Postcondition: The iterator is advanced to the next node
        current = current->link;
        return &this;
    }


    bool operator == (const linkedListIterator<Type>& right)const
    {
        //Overload the equality operator
        //Postcondition: Returns true if this iterator is equal to the
        // iterator specified by right, otherwise it returns false.
        return (current == right.current);
    }


    bool operator != (const linkedListIterator<Type>& right)const
    {
        //Overload the not equal operator
        //Postcondition: Returns true if this iterator is not equal to the
        // iterator specified right, otherwise returns false.
        return (current != right.current);

    }

private:
    nodeType<Type> &current; //pointer to point to the first node in the linked list

};

/*We have already defined a node to a linked list and  an iterator to a linked list
, now we implement the linked list intself*/

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
         //Function to determine determine wether the list is empty
        //Postcondition: Returns true if the list is empty, otherwise it returns false
       return(first == NULL);

    }

    void print() const
       {
            //Function to output the data contained in each node
            //Postcondition: none
           // we must traverse the list using the first list
            nodeType<Type> *current; // pointer to treverse the list
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
        cout = 0;
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


template<class Type>
class orderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
        //Function to determine whether searchItem is in the list.
        //Postcondition: Returns true if searchItem is in the list,
        // otherwise the value false is returned.
    void insert(const Type& newItem);
        //Function to insert newItem in the list.
        //Postcondition: first points to the new list, newItem
        // is inserted at the proper place in the list, and
        // count is incremented by 1.
    void insertFirst(const Type& newItem);
        //Function to insert newItem at the beginning of the list.
        //Postcondition: first points to the new list, newItem is
        // inserted at the beginning of the list, last points to the
        // last node in the list, and count is incremented by 1.
    void insertLast(const Type& newItem);
        //Function to insert newItem at the end of the list.
        //Postcondition: first points to the new list, newItem is
        // inserted at the end of the list, last points to the
        // last node in the list, and count is incremented by 1.
    void deleteNode(const Type& deleteItem);
        //Function to delete deleteItem from the list.
        //Postcondition: If found, the node containing deleteItem is
        // deleted from the list; first points to the first node
        // of the new list, and count is decremented by 1. If
        // deleteItem is not in the list, an appropriate message
        // is printed.

};

template<class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current; //pointer to traverse the list

    current = first; // start the search at the first node
    while(current != NULL && !found)
        if(current->info >= searchItem)
            found = true;
        else
            current = current->link;
    if(found)
        found = (current->info == searchItem); //test for equality
    return found;
}

template<class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    // duplicates allowed
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; // pointer just before the current
    nodeType<Type> *newNode; // pointer create a node

    bool found;

    newNode = new nodeType<Type>; //create the node
    newNode->info = newItem; // store newItem in the node
    newNode->link = NULL; // set the link of the newNode to NULL

    if(first == NULL) // list is empty
    {
        first = newNode;
        last = newNode;
        count++;
    }
    else
    {
        current = first;
        found = false;

        while(current != NULL && !found) // search the list
            if(current->info >= newItem)
                found=true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if(current == first)
        {
            newNode->link = first;
            first = newNode;
            count++;
        }
        else
        {
            trailCurrent->link = newNode;
            newNode->link=current;

            if(current == NULL)
                last = newNode;
            count++;
        }
    }

template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    orderedLinkedList::insert(newItem);
}

template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    orderedLinkedList::insert(newItem);
}


template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if(first == NULL)
        cout<<"Cannot delete from an empty list."<<endl;
    else
    {
        current = first;
        found = false;

        while(current != NUll && !found)
            if(current->info >= deleteItem)
                found=true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if(current == NULL)
            cout<<"The item to be deleted is not in the list"<<endl;
        else
        {
            if(current->info == deleteItem) // the item to be deleted is in the list
            {
                if(first == current) // list contains only one node
                {
                    first = first->link;
                    if(first == NULL)
                        last = NULL;
                    delete current;
                }
                else
                {
                        trailCurrent->link = current->link;
                        if(current == last)
                            last = trailCurrent;
                        delete current;
                }
                count--;

            }
            else
                cout<<"The item to be deleted is not in the list."<<endl;
    }
}


int main()
{

    return 0;
}
