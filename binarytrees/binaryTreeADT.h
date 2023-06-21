#include<iostream>

using namespace std;
// Definition of the node
template <class elemType>
struct binaryTreeNode
{
    elemType info;
    binaryTreeNode<elemType> *llink;
    binaryTreeNode<elemType> *rlink;
};

//Definition of the class
template<class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator= (const binaryTreeType<elemType>& otherTree)
    {
        //Overload the assignment operator.
        if(this != &otherTree) //avoid self-copy
        {
            if(root != NULL) // if the binary tree is not empty
                            // destroy the binary tree
                destroy(root);
            if(otherTree.root == NULL) //otherTree is empty
                root = NULL;
            else
                copyTree(root, otherTree.root);
        }
        return *this;
    }
    bool isEmpty() const
    {
        //Returns true if the binary tree is empty; otherwise false
        return(root == NULL);
    }

    void inorderTraversal() const
    {
        //Function to do an inorder traversal of the binary tree
        inorder(root);
    }

    void preorderTraversal()const
    {
        //Function to do a postorder traversal of th binary tree
        preorder(root);
    }
    void postorderTraversal() const
    {
        //Function to do a postorder traversal  of the binary tree
        postorder(root);
    }

    int treeHeight() const
    {
        //Returns the  height of the binary tree
        return height(root);
    }

    int treeNodeCount() const
    {
        //Returns the number  of nodes in the binary tree
        return nodeCount(root);
    }
    int treeLeavesCount() const
    {
        //Returns the number of leaves in the binary tree
        return leavesCount(root);
    }
    void destroyTree()
    {
        //Deallocate the memory space occupied by the binary tree
        //Postcondition: root = NULL
        destroy(root);
    }

    binaryTreeType(const binaryTreeType<elemType>& otherTree)
    {
        //copy constructor
        if(otherTree.root == NULL) //otherTree is empty
            root = NULL;
        else
            copyTree(root, otherTree.root);
    }

    //Print the elements the binary tree
    void print()const
    {
        inorder(root);//prints all the elements of the binary tree
    }

    binaryTreeType()
    {
        //default constructor
        root = NULL;
    }

    ~binaryTreeType()
    {
        //default constructor
        destroy(root);
    }

protected:
    binaryTreeNode<elemType> *root;

private:
    void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,
                  binaryTreeNode<elemType>* otherTreeRoot)
                  {
                      //Makes a copy of the binary tree to which otherTreeRoot points.
                      //The pointer copiedTreeRoot points to the root of the copied binary tree.
                      if(otherTreeRoot == NULL)
                        copiedTreeRoot = NULL;
                      else
                      {
                          copiedTreeRoot = new binaryTreeNode<elemType>;
                          copiedTreeRoot->info = otherTreeRoot->info;
                          copyTree(copiedTreeRoot->llink, otherTreeRoot->rlink);
                          copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
                      }
                  }
    void destroy(binaryTreeNode<elemType>* &p)
    {
        //Function to destroy the binary tree to which p points
        //Postcondition: p = NULL
        if(p != NULL)
        {
            destroy(p->llink);
            destroy(p->rlink);
            delete p;
            p = NULL;
        }
    }

    void inorder(binaryTreeNode<elemType>* p) const
    {
        //Function to do an inorder traversal of the binary tree to which p points
        if(p != NULL)
        {
            inorder(p->llink); //traverse the left node
            cout<<p->info<<" " ; //visit the node
            inorder(p->rlink); //Traverse the right node
        }
    }

    void preorder(binaryTreeNode<elemType> *p) const
    {
        //Function to do a preorder traversal of the binary tree
        // to which p points
        if(p != NULL)
        {
            cout<<p->info<<" "; //Visit the node
            preorder(p->llink); //Traverse the left node
            preorder(p->rlink); //Traverse the right node
        }
    }

    void postorder(binaryTreeNode<elemType>* p) const
    {
        //Function to do a postorder traversal of the binary tree
        //to which points
        if(p != NULL)
        {
            postorder(p->llink); //Traverse the left node
            postorder(p->rlink); //Traverse the right node
            cout<<p->info<<" ";// Visit the node
        }
    }


    int height(binaryTreeNode<elemType>* p)const
    {
        //Function to return the height of binary tree
        // to which p points
        if(p == NULL)
            return 0;
        else
            return 1 +  max(height(p->llink), height(p->rlink)); //count all the nodes in the left and right and return the max
    }

    int max(int x, int y) const
    {
        //Returns the larger o x and y
        if(x > y)
            return x;
        else
            return y;
    }

    int nodeCount(binaryTreeNode<elemType>* p)const
    {
        //Function to return the number of nodes in  the binary
        //tree to which p points
        if(p == NULL)
            return 0;
        else
            return nodeCount(p->llink) + nodeCount(p->rlink);
    }
    int leavesCount(binaryTreeNode<elemType>* p) const
    {
        //Function to return the number of leaves in the binary
        // tree to which p points
        if(p == NULL)
            return 1;
        else
            return leavesCount(p->llink) + leavesCount(p->rlink);
    }

};
