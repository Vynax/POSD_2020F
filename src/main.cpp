#include <iostream>
#include "terminal.h"

using namespace std;
int main(int argc, char *argv[])
{
    std::cout << "We have " << argc << " arguments" << std::endl;
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "[" << i << "] " << argv[i] << std::endl;
    }
    string s = "123";
    s = s + "hello";

    cout << s << endl;
    return 0;
}