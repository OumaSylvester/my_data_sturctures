#include<iostream>>
#include "linkedQueueADT.h"

using namespace std;

int main()
{
    linkedQueueType<int> queue1;
    int x, y;


    queue1.initializeQueue();

    x=4;
    y=5;
    queue1.addQueue(x);
    queue1.addQueue(y);
    x=queue1.front();
    queue1.deleteQueue();
    queue1.addQueue(x+5);
    queue1.addQueue(16);
    queue1.addQueue(x);
    queue1.addQueue(y- 3);

    cout<<"Queue Elements: ";
    while(!queue1.isEmptyQueue())
    {
        cout<<queue1.front()<<" ";
        queue1.deleteQueue(); // to allow you to access the next node in the queue
    }
    cout<<endl;

    return 0;
}
