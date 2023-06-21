#include "binarySearchTreeADT.h"

template<class elemType>
struct AVLNode
{
    elemType info; //data contained in the node
    int bfactor; // balance factor
    AVLNode<elemType> *llink; // left subtree of the AVL
    AVLNode<elemType> *rlink; // right subtree of the AVL tree
};

template<class elemType>
class AVLTreeType: public bSearchTreeType<elemType>
{
    void rotateToLeft(AVLNode<elemType>* &root) // the pointer of the node requiring the  rotation is passed as a parameter
    {
            AVLNode<elemType> *p; //pointer to the root of the right subtree of root
            if(root == NULL)
                cerr<<"Error in the tree"<<endl;
            else if(root->rlink == NULL)
                cerr<<"Error in the tree: No right subtree to rotate."<<endl;
            else
            {
                p=root->rlink;
                root->rlink = p->llink; //the left subtree of p becomes  the right subtree of  root
                p->llink = root; //make the left subtree of p point to root
                root=p;  //make p the new root node
            }

    }//end rotateLeft

    void rotateToRight(AVLNode<elemType>* &root)
    {
        AVLNode<elemType>* p; //pointer to the root of the left subtree of root
        if(root == NULL)
            cerr<<"Error in the tree"<<endl;
        else if(root->llink == NULL)
            cerr<<"Error in the tree: No left subtree to rotate."<<endl;
        else
        {
            p=root->llink;
            root->llink=p->rlink; //the right subtree of p becomes the left subtree of the root
            p->rlink=root; // root becomes the right subtree of p
            root = p; //make p the new root node
        }
    }//end rotateRight
};
