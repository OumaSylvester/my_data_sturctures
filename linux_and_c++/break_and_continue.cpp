 #include <iostream>
 using namespace std;

 int main()
 {
    /*Continue helps you execute the loop from the top ...the code followin it within the block is skipped
    case of a continue within a for loop, the loop expression (the third expression within the for statement typically used to increment the counter)
    is evaluated before the condition is reevaluated.
    break exists the loop's block, theby ending the loop when invoked*/
    for(;;) // an infinite for loop
    {
        cout <<"Enter two numbers: ";
        int num1 = 0, num2;
        cin >>num1;
        cin >>num2;

        cout <<"Do you wish correct the numbers(y/n)? ";
        char changeNumbers = '\0';
        cin >> changeNumbers;

        if (changeNumbers == 'y')
            continue; // restart the loop
        cout << num1 <<" x "<<num2<<" = "<<num1 *  num2<<endl;
        cout << num1 <<" + "<<num2<< " = "<<num1 + num2<<endl;

        cout <<"Pree x to exit or any other key to recalculate"<<endl ;
        char userSelection = '\0';
        cin >>userSelection;

        if(userSelection == 'x')
            break; // exit the infinite loop
    }
    cout <<"Goodbye!"<<endl;
    return 0;

 }

