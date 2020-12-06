#include <iostream>
#include "terminal.h"
#include <fstream>
#include <stdio.h>
#include <regex>
using namespace std;
int main(int argc, char *argv[])
{
    stringstream ss;
    ss.str("");
    ss.clear();
    string str = "";
    string str_sum = "";
    vector<string> vec;
    regex e("\\r");
    std::cout << "We have " << argc << " arguments" << std::endl;
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "[" << i << "] " << argv[i] << std::endl;
    }
    switch (argc)
    {
    case 0:
    case 1:
        cout << "Missing Arguments" << endl;
        return 0;
        break;
    case 5:
        break;
    default:
        break;
    }
    ifstream ifile(argv[1]);
    ofstream ofile(argv[2]);
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

    ss << argv[3] << " " << argv[4];
    cout << ss.str() << endl;
    str_sum += (" " + ss.str());
    cout << std::flush;
    cout << "sum2" << str_sum << endl;

    cout << str_sum << endl;
    try
    {
        Terminal t(str_sum);
        ofile << t.showResult();
        ofile.close();
    }
    catch (string e)
    {
        cout << e << endl;
        ofile.close();
    }

    cout << std::flush;
    //Terminal t(str_sum);

    return 0;
}