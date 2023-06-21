//Say yo want to determine that the string  input by the user is palindrome,
// you will have to reverse the string and compare the two
// STL strings can easily be reversed using the std::reverse algorithm

#include<string>
#include<iostream>
#include<algorithm>

int main()
{
    using namespace std;

    string strSample("Hello String! We will reverse you!");
    cout<<"The original sample string is: "<<endl;
    cout<<strSample<<endl<<endl;

    reverse(strSample.begin(), strSample.end());
    cout<<"After applying the std::reverse algorithm: "<<endl;
    cout<<strSample<<endl;
    return 0;
}
