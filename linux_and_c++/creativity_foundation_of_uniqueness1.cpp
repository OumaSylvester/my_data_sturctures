#include<iostream>
using namespace std;

int main()
{
    for(int row =0; row<4; row++)
    {
        for(int column=0; column<5; column++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    //cout<<endl;

    //The 5 Asteriks logo
    cout<<"The 5 Asteriks Logo"<<endl;
    for(int row=1; row<=5; row++)
    {
        for(int column=1; column<=row; column++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    //cout<<endl;

    for(int row=1; row<=5; row++)
    {
        for(int column=1; column<=row; column++)
        {
            cout<<column;
        }
        cout<<endl;
    }

    //cout<<endl;

    for(int row=5; row>=1; row--)
    {
        for(int column=1; column<=row; column++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    //cout<<endl;

    for(int row=5; row>=1; row--)
    {
        for(int column=1; column<=row; column++)
        {
            cout<<column;
        }
        cout<<endl;
    }


    return 0;
}
