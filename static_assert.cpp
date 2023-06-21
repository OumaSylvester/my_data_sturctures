template<typename T>
class EveryThingButInt
{
public:
    EveryThingButInt()
    {
        static_assert(sizeof(T) != sizeof(int), "No int Pleas!");
    }
};

int main()
{
    EveryThingButInt<int> test; //template initialization with int. fails

    return 0;
}
