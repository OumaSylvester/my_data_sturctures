/*A simple spreadsheet program*/

#include<iostream>
#include<string>
#include<iomanip>

//#include <graphics.h>
using namespace std;

int main()
{
    //Find out how to enlarge the console screen
    // Write to a file
    //TODO: Clear screen to display table


    string students_names [50];
    string subjects [5] = {"English", "Kiswahili", "Mathematics", "Science", "Social Studies"};

    int marks [50][5];
    int total_of_one_stu=0;
    int total_for_all_stu [50];
    float average[50];
    string students_grade[50];


    for(int stu=0; stu<2; stu++)
    {
        total_of_one_stu = 0;
        cout<<"Name of student "<<stu+1<<": ";
        getline(cin, students_names[stu]);
        cout<<"Enter marks for "<<students_names[stu]<<endl;
        for(int sub=0; sub<5; sub++)
        {
            cout<<subjects[sub]<<": ";
            cin>>marks[stu][sub];//This one enters a new line.How do i avoid that
            while(marks[stu][sub] <0 || marks[stu][sub] > 100)
            {
                cout<<"Invalid mark"<<endl;
                cout<<"Re-enter mark for "<<subjects[sub]<<": ";
                cin>>marks[stu][sub];
            }
            total_of_one_stu += marks[stu][sub];
        }

        average[stu] = total_of_one_stu/5;
        total_for_all_stu[stu] = total_of_one_stu;
        cin.ignore(256, '\n'); // ignore remaining input char i.e fron the for loop below
            // that adds an extra newline after the last mark is enterd hence empty line enter
            // as the next students name
        // There are several work arounds to this
    }

    // Assign grade
    for(int stu=0; stu<50; stu++)
    {
        if(average[stu] >=80 && average[stu]<=100)
            students_grade[stu] = "A ";
        else if(average[stu] >= 75 && average[stu] <80)
            students_grade[stu] = "A-";
        else if(average[stu] >= 70 && average[stu] <75)
            students_grade[stu] = "B+";
        else if(average[stu] >= 65 && average[stu] <70)
            students_grade[stu] = "B ";
        else if(average[stu] >= 60 && average[stu] <65)
            students_grade[stu] = "B-";
        else if(average[stu] >= 55 && average[stu] <60)
            students_grade[stu] = "C+";
        else if(average[stu] >= 50 && average[stu] <55)
            students_grade[stu] = "C ";
        else if(average[stu] >= 45 && average[stu] <50)
            students_grade[stu] = "C-";
        else if(average[stu] >= 40 && average[stu] <45)
            students_grade[stu] = "D+";
        else if(average[stu] >= 35 && average[stu] <40)
            students_grade[stu] = "D ";
        else if(average[stu] >= 30 && average[stu] <35)
            students_grade[stu] = "D-";
        else if(average[stu] > 0  && average[stu] < 30)
            students_grade[stu] = "E ";
        else
            students_grade[stu] = "Invalid mark";


    }


    // Display the students table
    cout<<setw(80)<<string(80, '-')<<endl;
    cout<<setw(32)<<"\b| Name "+string(24, ' ')<<setw(6)<<"| Eng "<<setw(6)<<"| Kis "<<setw(6)<<"| Mat "<<setw(6)<<"| Sci "<<setw(6)<<"| SS  ";
    cout<<setw(6)<<"| Tot "<<setw(6)<<"| Avr "<<setw(6)<<"| Gra |"<<endl;
    cout<<setw(80)<<string(80, '-')<<endl;
    for(int stu=0; stu<2; stu++)
    {
        cout<<setw(32)<<"| " + students_names[stu] +string(29 - students_names[stu].length(), ' ') + "|";
        cout<<setw(0);
        for(int sub=0; sub<5; sub++)
        {
            cout<<string(2, ' ')<<marks[stu][sub]<<string(1, ' ')<<"|";
        }
        cout<<string(1, ' ')<<total_for_all_stu[stu]<<string(1, ' ')<<"|";
        cout<<string(2, ' ')<<average[stu]<<string(1, ' ')<<"|";
        cout<<string(2, ' ')<<students_grade[stu]<<string(1, ' ')<<"|";
        cout<<endl;

        cout<<setw(80)<<string(80, '-')<<endl;
    }

}
