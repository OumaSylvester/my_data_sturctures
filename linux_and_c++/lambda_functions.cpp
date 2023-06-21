/*Predicate functions */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Syntax of a lambda function is:
[optional parameters](parameter list){statements;}
*/

void DisplayNums(vector<int>& dynArray)
{
    for_each(dynArray.begin(), dynArray.end(),\
    [](int Element) {cout<<Element<<" ";}); //Lambda function
    cout <<endl;
}


int main()
{
    vector<int> myNums;
    myNums.push_back(501);
    myNums.push_back(-1);
    myNums.push_back(25);
    myNums.push_back(-35);

    DisplayNums(myNums);
    cout <<"Sorting them in descending order... "<<endl;
    sort(myNums.begin(), myNums.end(),\
    [](int Num1, int Num2) {return (Num2<Num1);}); //uses binary predicate in the form a lambda function Lambda function
    DisplayNums(myNums);
    //cout<<myNums.begin(); Throws an error
    return 0;
}
