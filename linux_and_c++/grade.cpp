#include<iostream>
using namespace std;

int main()
{
    char grade;
    float averageMarks;
    cout<<"Enter the averge matks: ";
    cin>>averageMarks;
    if(averageMarks >=70)
        grade = 'A';
    else if(averageMarks >=60 && averageMarks <70)
        grade = 'B';
    else if(averageMarks >=50 && averageMarks <60)
        grade = 'C';
    else if(averageMarks >=40 && averageMarks<50)
        grade = 'D';
    else
        grade = 'E';
    cout<<"The grade is: "<<grade;
    return 0;

}
