
#include<iostream>

using namespace std;

struct nodeType
{
    int info;
    nodeType *link;
};



int main()
{
    /*we need three pointers to build the list; one to point to the first node,
    which cannot be moved, one to point to the last node in the list, and one to create
    the new node.
    */
    nodeType *first,*last, *newNode;
    int num;
    char quit = '\0'; // allows user to quit the program

    first = NULL;
    last = NULL;
    cout<<"Enter 'x' to quit: "<<endl;
    do{
        cout<<"Add a number to the list: "<<endl;
        cin >> num;
        newNode = new nodeType; // allocate memory of type nodeType

        newNode->info = num; // copy the value of num into the info field of the newNode
        newNode->link=NULL; // initialize the link field of the newNode to NULL.Its always the last node

        if(first == NULL) //if first is null, the list is empty; make first and last point to new node
        {
            first = newNode; // rem its only one node so its first and the last one
            last = newNode;
        }
        else
        {
            last->link=newNode; // insert new node at the end of the list
            last = newNode; // set last so that it points at the actual last node in the list
        }
        cin>>quit;
        //if(quit == 'x' || quit == 'X')
          //  break;
    }while(quit != 'x' || quit != 'X');

    nodeType *current;
    current = first;
    while(current != NULL)
    {
        cout<<current->info<<"  ";
        current=current->link;
    }

    return 0;
}
