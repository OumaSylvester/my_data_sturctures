#include <iostream>
using namespace std;
constexpr int Square(int number){return number * number;}

int main()
{
    int family_ages [6] = {46, 29, 27, 26, 22, 17};
    /*
    cout << "Mom's age at index 0: " << family_ages[0] <<endl;
    cout << "Rose's age index 1: " << family_ages[1] <<endl;
    cout <<"Paulines age at index 2: " <<family_ages[2] <<endl;
    cout <<"Evance's age at index 3: " <<family_ages[3] <<endl;
    cout << "My age at index 4: " <<family_ages[4]<<endl;
    cout <<"Collins' age at index 5: "<<family_ages[5]<<endl;
    */

    /*
    const int ARRAY_LENGTH = 5;
    // Array of 5 integers, initialized using a const
    int myNumbers [ARRAY_LENGTH] = {5, 10, 0, -101, 20};
    // Using a constexpr for array of 25 integers
    int moreNumbers [Square(ARRAY_LENGTH)];
    cout << "Enter index of the element to be changed: ";
    int elementIndex = 0;
    cin >> elementIndex;

    cout << "Enter new value: ";
    int newValue =0;
    cin >>newValue;

    myNumbers[elementIndex] = newValue;
    moreNumbers[elementIndex] = newValue;

    cout << "Element " <<elementIndex << " in array myNumbers is: ";
    cout << myNumbers[elementIndex] <<endl;

    cout << "Element " << elementIndex << " in array moreNumbers is: ";
    cout << moreNumbers[elementIndex] <<endl;
    cout << "Let us see the junk assigened by the compiler: " <<moreNumbers[6]<<endl;
    */

    // Multi dimensional arrays
    int solarPanels [2][3] = {{0,1,2}, {3,4,5}};

    int three_rows_three_columns [3][3] ={{123,456,789},{733, 938,262},{902,213,451}};
    cout << "Memory address of three_rows_three_columns is: " <<three_rows_three_columns<<endl;
    cout << "Memory address of row 0 in the array is: " <<three_rows_three_columns[0]<<endl;
    cout << "Row 0 elemnt 0 is: " <<three_rows_three_columns[0][0]<<endl;
    return 0;
}
