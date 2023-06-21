/*
This program creates a file and writes to it. It then opens the files file and read from it.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void WriteFile()
{
    //Creating a file and writing to ir
    ofstream outfile("../MyFirstFile.txt", ios_base::app); // creates and opens  the file, allows append option if file already exists
    if(outfile.fail()){ // Checks if kali linux creates a directory if does not exist, or if you are out of disk space or if you don't have  right permmission
        cout<<"Couldn't open the file!"; //if it does not, let the user no that the file couldn't be created

    }
    outfile <<"Appended text! Another test drive"<<endl;// writes 'Hello world' to the file
    outfile.close(); // closes the file
}

string ReadString(ifstream &file)
{
    /*A function to read a file from the hard disk*/
    char line[1024]; // Make sure this is big enough. We assume that a line in the file does not exceed 1023 characters
    file.getline(&(line[0]), 1024);// Read each char in a line of the file to the line array variable. Use a pointer to point to the location of the first character in the array
    //remeber the getline() function wants a character array not a string
    return string(line); //convert the character array to string object
}

int main()
{
    WriteFile();

    // Using code Code to Open a File and Read from it

    ifstream infile("wrting_to_file.cpp"); //opens the file for reading. Am reading my own cpp file in c=this case

    while(1){

        string contents = ReadString(infile);//read from the file to the variable content.Always looks for a space
        if(infile.eof() == true)
            break;// end fo file//exit the loop

        cout<<contents<<endl;//print the contents of the file to the screen
    }
    infile.close(); //closes the file

    return 0;
}

