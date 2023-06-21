#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> dyn_array (3); // dynamic array of int. A sequential container(array)
    dyn_array[0] = 365;
    dyn_array[1] = -421;
    dyn_array[2] = 789;

    cout << "Number of integers in array: " << dyn_array.size()<<endl;
    cout << "Enter another element to insert: "<<endl;
    int newValue = 0;
    cin >> newValue;
    dyn_array.push_back(newValue);

    cout << "Number of integers in array: " << dyn_array.size()<<endl;
    cout << "Last element in array: ";
    cout << dyn_array[dyn_array.size() - 1]<<endl;
    return 0;
}
