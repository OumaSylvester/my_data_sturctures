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

