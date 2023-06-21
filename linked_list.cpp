#include<iostream>
using namespace std;

struct nodeType
{
    int info;
    nodeType *link;
};

int main()
{
    nodeType *head, *newNode;
    nodeType *current;
    current = head;
    head ->info=22;
    newNode->info=17;
    //head->link=newNode;

   // current ->info = 46;
    while(current != NULL)
    {
       cout << current->info <<"  ";
       current = current->link;
    }
    //cout<<"\nHead info:"<<head->info<<endl;
    return 0;
}
