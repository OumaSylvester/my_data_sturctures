#include<iostream>
#include "binarySearchTreeADT.h"

using namespace std;
int main()
{
    bSearchTreeType<int> myTestTree;
    cout<<"Insert:  Enter numbers ending -999: "<<endl;
    int num;
    cin>>num;
    while(num != -999)
    {
        myTestTree.insert(num);
        cin>>num;
    }
    //Print the entered values
    cout<<"In-order traversal: "<<endl;

    myTestTree.print();
    cout<<"\nEnter value to delete:"<<endl;
    int deleteValue;
    cin>>deleteValue;
    myTestTree.deleteNode(deleteValue);
    cout<<"Your tree after deletion: "<<endl;
    myTestTree.print();

    cout<<"\nEnter value to search: "<<endl;
    int searchValue;
    cin>>searchValue;
    bool found=myTestTree.search(searchValue);
    if(found)
        cout<<searchValue<<" is in the tree."<<endl;
    else
        cout<<searchValue<<" was not found in the tree."<<endl;
    return 0;
}
