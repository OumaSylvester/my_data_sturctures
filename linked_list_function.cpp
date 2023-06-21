/*
This program implements a linked list Forward.
A new node is always insert at the end of the list.
*/

#include<iostream>
using namespace std;

struct nodeType
{
    int info;
    nodeType *link;
};

nodeType* buildLinkedListForward();
int main()
{
    nodeType *current = buildLinkedListForward(); // create the linked list
    // Display the liked list
    cout<<"Your list: "<<endl;
    while(current != NULL)
    {
        cout<<current->info<<"  ";
        current=current->link;
    }
    return 0;
}

nodeType* buildLinkedListForward()
{
    nodeType *first, *newNode, *last;
    int num;
    cout << "Enter a list of integers ending with 100: "<< endl;
    cin >> num;
    first = NULL;
    while (num != 100)
    {
        newNode = new nodeType; // allocate memory for the newNode
        newNode->info = num; // set newNode info to num
        newNode->link = NULL; // set newNode link to NULL. Its the only link so far hence the last
        if (first == NULL) // if first is NULL set firt to our newNode
        {
            first = newNode;
            last = newNode; // also set last to newNode since its the only node
        }
        else
        {
            last->link = newNode; // is first node already exists, set the last node link to  our newNode.
            // The previous last one points the newNode
            last = newNode; // then set the last node to newNode. Replace
        }
        cin >> num;
    }//end while
    return first; // returns the pointer to the linked list i.e first node
}//end buildListForward

