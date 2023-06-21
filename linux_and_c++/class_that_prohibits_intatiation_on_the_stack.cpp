#include<iostream>
using  namespace std;


class MonsterDB
{
    private:
        ~MonsterDB(){}; //private destrucotr prevents instance on stack

    public:
        static void DestroyInstance(MonsterDB* pInstance)
        {
            delete pInstance; // member can inkoe privet destructor
        }

        void DoSomething(){} //sample empty member method
};


int main()
{
    MonsterDB* myDB = new MonsterDB(); // on heap
    myDB->DoSomething();

    //uncommeent next line to see compile failure
    //delete myDB; // private destrucor cannot be invoked

    // use static member to release memory

    MonsterDB::DestroyInstance(myDB);
    return 0;
}
