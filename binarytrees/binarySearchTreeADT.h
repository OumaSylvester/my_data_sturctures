/*This class defines a binary search tree by inheriting
from the binary tree*/

#include "binaryTreeADT.h"
#include<cassert>//for assert

template <class elemType>
class bSearchTreeType: public binaryTreeType<elemType>
{
public:
    bool search(const elemType& searchItem) const
    {
        //Function to determine if searchItem is in the binary search tree
        //Postcondition: Returns true if searchItem  is found in the binary
        // search tree; otherwise , returns false

        binaryTreeNode<elemType> *current;
        bool found = false;
        if(binaryTreeType<elemType>::root == NULL)
            cerr<<"Cannot search an empty tree"<<endl;
        else
        {
            current =binaryTreeType<elemType>:: root;
            while(current != NULL && !found)
            {
                if(current->info == searchItem)
                    found = true;
                else if(current->info > searchItem)
                    current = current->llink;
                else
                    current = current->rlink;

            }
        }
        return found;
    }

    void insert(const elemType& insertItem)
    {
        //Function to insert insertItem in the binary search tree.
        //Postcondition; If no node in the binary search tree has the same info as
        // insertItem, a node with info insertItem is created and inserted int eh binary
        //search tree.
        binaryTreeNode<elemType> *current; //pointer to traverse the tree
        binaryTreeNode<elemType> *trailCurrent; // pointer behind current ...used as the parent of the new node
        binaryTreeNode<elemType> *newNode; // pointer to create the node

        // create the new node to be inserted
        newNode = new binaryTreeNode<elemType>;
        assert(newNode != NULL);
        newNode->info = insertItem;
        newNode->llink = NULL;
        newNode->rlink = NULL;

        if(binaryTreeType<elemType>::root == NULL)
            binaryTreeType<elemType>::root = newNode;
        else
        {
            current =binaryTreeType<elemType>::root;
            while(current != NULL) //if current is NULL we have found the parent to insert our node to(trailCurrent)
            {
                trailCurrent = current; //keep track of the parent
                if(current->info == insertItem)
                {
                    cerr<<"The insert item is already in the tree, ";
                    cerr<<"duplicates are not allowed. "<<insertItem<<endl;
                    return;
                }
                else if(current->info > insertItem)
                    current=current->llink; //traverse the left subtree
                else
                    current = current->rlink;


            }//end while
            if(trailCurrent->info > insertItem)//check if the newNode is to be insert to the left subtree of trailCurrent
                trailCurrent->llink = newNode;
            else
                trailCurrent->rlink=newNode; // insert the newNode to the right
        }
    }

    void deleteNode(const elemType& deleteItem)
    {
        //Function to delete deleteItem from  the binary search tree.
        //Postcondition: if a node with the same info as deleteItem is found
        // it is deleted form the binary search tree
        binaryTreeNode<elemType> *current; //pointer to traverse the tree
        binaryTreeNode<elemType> *trailCurrent; // pointer behind current
        bool found = false;

        if(binaryTreeType<elemType>::root == NULL)
            cout<<"Cannot delete from the empty tree."<<endl;
        else
        {
            current =binaryTreeType<elemType>:: root;
            trailCurrent =binaryTreeType<elemType>:: root;

            while(current != NULL && !found)
            {
                //search for the item to be deleted
                if(current->info == deleteItem)
                    found = true;
                else
                {
                    //continue searching
                    trailCurrent = current;
                    if(current->info > deleteItem)
                        current = current->llink;
                    else
                        current = current->rlink;
                }

            }//end while
            if(current == NULL)
                cout<<"The delete item is not in the tree"<<endl;
            else if(found)
            {
                if(current == binaryTreeType<elemType>::root)
                    deleteFromTree(binaryTreeType<elemType>::root);
                else if(trailCurrent->info > deleteItem )
                    deleteFromTree(trailCurrent->llink);
                else
                    deleteFromTree(trailCurrent->rlink);
            }//end if
        }

    }//end deleteNode
private:
    void deleteFromTree(binaryTreeNode<elemType>* &p)
    {
        //Function to delete the node  to which p points is deleted
        // from the binary search tree
        //Postcondition: The node to which p points is deleted  from
        // the binary search tree.
        binaryTreeNode<elemType> *current; //pointer to traverse the tree
        binaryTreeNode<elemType> *trailCurrent; // pointer behind current
        binaryTreeNode<elemType> *temp; //pointer to delete the node

        if(p == NULL)
            //CASE 0
            cerr<<"Error: The node to be deleted is NULL."<<endl;
        else if(p->llink == NULL && p->rlink == NULL) //If both llink and rlink are NULL
        {
            //CASE 1
            temp = p;
            p = NULL; // set the node to NULL..deletes its info,
            delete temp; //deallocate the memory held by node p
        }
        else if(p->llink == NULL) //if the  llink is  NULL and rlink not NULL
        {
            //CASE 2
            temp = p;
            p = temp->rlink; //set p rlink to p
            delete temp; //deallocate the
        }
        else if(p->rlink == NULL) // if the rlink is  NULL and llink is not NULL
        {
            //CASE 3
            temp = p;
            p=temp->llink; //set p llink to p
            delete temp;
        }
        else //is both p rlink and llink  are not NULL
        {
            //Here we will decompose the problem to CASE 3 so that we solve it easily
            current = p->llink; // set the left subtree of p to NULL
            trailCurrent = NULL;
            while(current->rlink != NULL) //Traverse the right subtree of current
            {
                /*Move to  the left  subtree of  p traversing
                its rlink till we find an empty right subtree.
                We will swap the parent(trailCurrent) of the first found right subtree of current*/
                trailCurrent = current; //keep track of the parent..the node info to be swapped with deleteItem
                current = current->rlink; //advance to the next rlink till we find an empty right subtree
            }
            p->info = current->info; //swap the info of the node to be deleted  with the first found right subtre. Move it down to
            // a point  where it will be deleted using CASE 3
            if(trailCurrent == NULL) //current did not move. current == p->llink; adjust p
                p->llink = current->llink;
            else
                trailCurrent->rlink = current->llink;
            delete current;

        }
    }
};

