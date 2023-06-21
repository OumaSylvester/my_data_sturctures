#include<iostream>
#include<vector>

using namespace std;

int main()
{
    //Instantiate using the default constructor, when you don't know the minimal size requirement of the container
    std::vector<int> vecIntegers = {89, 33, 11, 23, 99}; //only in cpp11 and above

    //Instantiate a vector with 10 elements(it can grow larger)
    std::vector<int> vecWithTenElements(10);

    //Instantiate a vector with 10 elements, each initialized to 90
    std::vector<int> vecWithTenInitElements(10, 90);

    //Instantiate one vector and initialize it to the contents of another
    std::vector<int> vecArrayCopy(vecWithTenInitElements);

    //Using iterators instantiate vector to 5 elements from another;
    std::vector<int> vecSomeElementIsCopied(vecWithTenElements.cbegin(), vecWithTenElements.cbegin()+5);

    //Insert sample integers into the vector
    vecIntegers.push_back(50);
    vecIntegers.push_back(1);
    vecIntegers.push_back(89);
    vecIntegers.push_back(474);


    cout<<"The vector contains ";
    cout<<vecIntegers.size()<<" elements"<<endl;
    return 0;
}
