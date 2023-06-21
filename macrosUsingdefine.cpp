#include<iostream>
#include<string>

using namespace std;

#define ARRAY_LENGTH 25
#define Pi 3.1416
#define my_double double
#define FAV_WHISKY "Jack Daniels"

int main()
{
    int mynumbers [ARRAY_LENGTH] = {0};
    cout<<"Array's length: "<<sizeof(mynumbers)/sizeof(int)<<endl;

    cout<<"Enter a radius: ";
    my_double radius = 0;
    cin>>radius;
    cout<<"Area is: "<<Pi * radius*radius<<endl;

    string favorite_whisky(FAV_WHISKY);
    cout<<"My favorite drink is: "<<favorite_whisky<<endl;

    return 0;
}

