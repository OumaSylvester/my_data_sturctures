#include<iostream>

using namespace std;

struct nodeType
{
    int info;
    nodeType *link;
};
nodeType* buildLinkedListBackward();

int main()
{
    nodeType *current = buildLinkedListBackward(); // create the linked list
    // Display the liked list
    cout<<"Your list: "<<endl;
    while(current != NULL)
    {
        cout<<current->info<<"  ";
        current=current->link;
    }
    return 0;
}

nodeType* buildLinkedListBackward()
{
    nodeType *first, *newNode;
    int num;

    cout<<"Enter a list of integers ending 100"<<endl;
    cin >> num;
    first = NULL;

    while(num != 100)
    {
        newNode = new nodeType;
        newNode->info = num;
        newNode->link = first;

        first = newNode;
        cin >> num;
    }

    return first; // returns the pointer to the linked list i.e first element
}//end buildLinkedListBackward
