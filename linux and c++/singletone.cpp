#include<iostream>
#include<string>
using namespace std;

/*The concept of singleton  uses private constructors, a  private  assignment operator,
and a static instance member*/

class President
{
    private:
        President() {}; // private dafult constructor
        President(const President&); // private copy constructor
        const President& operator=(const President&); //assignment operator

        string name;
    public:
        static President& GetInstance()
        {
            // static objects are contructoed only onece
            static President onlyInstance;
            return onlyInstance;
        }

        string GetName()
        {
            return name;
        }

        void SetName(string InputName)
        {
            name = InputName;
        }
};

int main()
{
    President& onlyPresident = President::GetInstance();
    onlyPresident.SetName("Abraham Lincoln");

    //uncomment lines to see how compile failures prohibi dublicates
     //President second; // cannot access constructor
    //President* third= new President(); //cannot access constructor
    // President fourth = onlyPresident; //cannot access copy constructor
    // onlyPresident = President::GetInstance(); // cannot access operator

    cout<<"The name of the President is: "<<President::GetInstance().GetName()<<endl;

    return 0;
}
