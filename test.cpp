#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a;
    std::basic_istream<char>::__istream_type b = cin >> a;
    cout << b << endl;
    return 0;
}