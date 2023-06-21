//B-tree node
template<class recType, int bTreeOrder> //reType stands  for record type>>key type
struct bTreeNode
{
    int recCount; //number of records/keys in the list
    recType list[bTreeOrder - 1]; //list of records/keys
    bTreeNode *children[bTreeOrder]; //array of pointers to children of the node
};

//B-tree ADT
template<class recType, int bTreeOrder>
class bTree
{
public:
    bool search(const recType& searchItem)
    {
        //Function to determine if searchItem is in the B-tree
        //Postcondition: Returns true if search Item is found in the B-tree; otherwise, returns false
        bool found = false;
        int location;

        bTreeNode<recType, bTreeOrder> *current;

        current = root;

        while(current != NULL && !found)
        {
            searchNode(current, item, found, location);
            if(!found)
                current=current->children[location];//make the next node the root
        }
        retu found;
    }//end search

    void insert(const recType& insertItem)
    {
        //Function to insert insertItem in the B-tree.
        //Postcondition: If insertItem is not in the B-tree, it is inserted in the B-tree.
    }

    void inOrder()
    {
        //Function to do an inorder traversal of the B-tree.
    }
    bTree()
    {
        //Constructor
    }
protected:
    bTreeNode<recType, bTreeOrder> *root;

private:
    void searchNode(bTreeNode<recType, bTreeOrder> *current, const recType& item,
                    bool& found, int& location)
                    {
                        location = 0;
                        while(location < current->recCount && item >current->list[location])
                            location++;
                        if(location < current->recCount && item == current->list[location])
                            found = true;
                        else
                            found = false;
                    }//end searchNode
};
