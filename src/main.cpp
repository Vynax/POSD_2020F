#include <iostream>
#include "terminal.h"
#include <fstream>
#include <stdio.h>
#include <regex>
using namespace std;
int main(int argc, char *argv[])
{
    // stringstream ss;
    // ss.str("");
    // ss.clear();
    string str = "";
    string str_sum = "";
    vector<string> vec;
    regex e("\\r");
    std::cout << "We have " << argc << " arguments" << std::endl;
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "[" << i << "] " << argv[i] << std::endl;
    }
    ifstream ifile(argv[1]);
    if (ifile.is_open())
    {
        while (getline(ifile, str))
        {
            str = regex_replace(str, e, " ");
            vec.push_back(str);
            //std::cout << str << std::endl;
            //         //std::cout.flush();
            //         ss << str;
            //         cout << ss.str() << endl;
            str_sum = str_sum + str;
            //         cout << str_sum << endl;
            //         //printf("%s\n", str.c_str());
            //         //printf("sum:%s\n", str_sum.c_str());
        }
        //str_sum += str;
        cout << vec.size() << endl;
        // for (int i = 0; i < vec.size(); i++)
        // {
        //     str_sum += vec.at(i);
        //     cout << vec.at(i) << endl;
        // }
        ifile.close();
    }
    cout << std::flush;
    //str_sum = regex_replace(str_sum, e, "");
    cout << "sum2" << str_sum << endl;

    cout << std::flush;
    //Terminal t(str_sum);

    return 0;
}