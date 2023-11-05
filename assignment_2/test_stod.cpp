#include <iostream>
#include <string>

using std::cout;
using std::cin;

using std::stod;
using std::string;

int main()
{
    string num = "-456.123";
    double i = stod(num);
    cout << i << '\n';
    return 0;
}