#include <iostream>
using namespace std;

// Declaring constants using constexpr
// constexpr alllows function like declaration of constants
constexpr double GetPi() {return 22.0 / 7;}
//One contsexpr can use another
constexpr double Twice(){return 2 * GetPi();}

int main()
{
    //float distance = 23_m;

    auto coinFlippedHeads = true;
    auto largeNumber = 2500000000000;
    cout << "coinFlippedHeads = " << coinFlippedHeads;
    cout << ", size of(coinflippedHeads) = " << sizeof(coinFlippedHeads) <<endl;

    cout << "largeNumber = " << largeNumber;
    cout << ", sizeof(largeNumber) = " <<sizeof(largeNumber) <<endl;

    // Using typedef to Substitute a Variables Type
    typedef unsigned int STRICTLY_POSITVE_INT;
    STRICTLY_POSITVE_INT num_eggs_in_basket = 292;
    cout << "Number of eggs in a basket is: " << num_eggs_in_basket << endl;

    // Is this a constant i.e int literal constants ... .i don't know what is measn for 10 to be a literal constants
    int someNumber = 0b1010;
    cout <<"some number: " <<someNumber <<endl;
    someNumber = 13;
    cout <<"some numer changed: " <<someNumber <<endl;

    // Declaring constants using const keyword
    const double pi = 22.0 / 7;
    cout <<"The value of contstant pi is: " <<pi <<endl;
    // pi = 3.142;



    cout <<"constant pi contains value: " <<pi <<endl;
    cout << "constexpr GetPi() returns: " << GetPi() <<endl;
    cout <<"constexpr TwicePi() returns: " << Twice() <<endl;

    // Enumarations.... allows a particular variable to accep only a set of values
    enum RainbowColors{
        Violet,
        Indigo,
        Blue,
        Green,
        Yellow,
        Orange,
        Red
    };

    enum CardinalDirections{
        North = 25,
        South,
        East,
        West
    };

    RainbowColors her_best_color = Blue; // Initial value
    cout <<"Her favorite color is: " <<her_best_color <<endl;

    cout << " Displaying directions and their symbolic values" <<endl;
    cout <<" North: " <<South << endl;

    // Defining constants using #define
    // #define is a preprocessor macro. The compiler replaces every use of the  defined variable with the text value of the
    // constant. It doe'snt care about the type of the variable
    // #define is deprecated and should not be used

    return 0;
}
