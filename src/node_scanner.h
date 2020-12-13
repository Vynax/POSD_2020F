#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
class NodeScanner
{
public:
    NodeScanner(std::string input = "") : _input(input)
    {
        punct_vec.push_back("{");
        punct_vec.push_back("}");
        punct_vec.push_back("(");
        punct_vec.push_back(")");
        punct_vec.push_back(",");
    }
    std::string nextToken()
    {
        // return next token.
        // throw exception std::string "next token doesn't exist." if next token not found.

        char c = _input[ptr];

        char punct[] = {'{', '}', '(', ')', ','}; // punctuation 標點符號

        //std::string punct_str[] = {"[", "]", "{", "}", "(", ")", ","};
        //char *p;
        //int punct_size = sizeof(punct) / sizeof(punct[0]);
        //int punct_size = strlen(punct);
        temp = "";
        int size = _input.size();
        //忽略空白
        if (_input[ptr] == '\0' || ptr >= size)
        {
            throw std::string("next token doesn't exist.");
        }
        while (ptr < size && !str_AZ_az(temp) && !str_in_array(temp, punct_vec) && !isNum(temp))
        {
            //只要是空白就繼續跑，跑到不是空白為止
            if (c == ' ')
            {
                ptr++;
                while (ptr < size)
                {
                    if (_input[ptr] != ' ')
                        break;
                    ptr++;
                }
            }

            c = _input[ptr];

            //擷取token

            //如果第一個字元是這些就直接回傳
            if (char_in_array(_input[ptr], punct))
            {
                ptr++;
                temp = c;
            }
            else
            {
                //只要不是合法標點符號或空白就加入token
                for (; ptr < size; ptr++)
                {
                    c = _input[ptr];
                    if (char_in_array(c, punct) || c == ' ')
                        break;
                    else if (!isalpha(c) && !isdigit(c) && !(c == '.'))
                        continue;
                    temp += c;
                    //cout << "hi2" << endl;
                }
            }
            //cout << "hi3" << endl;
            //cout << temp << endl;
        }
        //cout << temp << endl;
        if (!str_AZ_az(temp) && !str_in_array(temp, punct_vec) && !isNum(temp))
            throw std::string("next token doesn't exist.");
        //cout << "sc:" << temp << endl;
        return temp;
    }

    // you can add other public functions if you needed.

    void set_ptr(int n)
    {
        ptr = n;
    }
    int get_ptr()
    {
        return ptr;
    }
    int input_size()
    {
        return _input.size();
    }
    bool char_in_array(char input, char array[])
    {
        char *p;
        size_t size = strlen(array);
        //int size = (sizeof(array) / sizeof(array[0]));
        p = std::find(array, array + size, input);
        //cout << "hi1" << endl;
        if (p != array + size) //如果input不在array裡面，p會指向最後面不存在的東西
            return true;
        else
            return false;
    }
    bool str_in_array(std::string input, std::vector<std::string> array)
    {
        for (size_t i = 0; i < array.size(); i++)
        {
            if (input == array[i])
                return true;
            //cout << array[i] << endl;
        }

        return false;
    }
    bool str_AZ_az(std::string s)
    {
        if (s.size() <= 0)
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            if (!isalpha(s[i])) //如果有一個字元不是字母就false
                return false;
        }
        return true;
    }
    bool isNum(std::string str)
    {
        std::stringstream sin(str);
        double d;
        char c;
        if (!(sin >> d))
        {
            /*解釋： 
            sin>>t表示把sin轉換成double的變數（其實對於int和float型的都會接收），
			如果轉換成功，則值為非0，如果轉換不成功就返回為0 
            */
            return false;
        }
        if (sin >> c)
        {
            /*解釋：
            此部分用於檢測錯誤輸入中，數字加字串的輸入形式（例如：34.f），在上面的的部分（sin>>t）
            已經接收並轉換了輸入的數字部分，在stringstream中相應也會把那一部分給清除，
            此時接收的是.f這部分，所以條件成立，返回false 
            */
            return false;
        }
        return true;
    }

private:
    std::vector<std::string> punct_vec;
    //std::vector<std::string> word;
    std::string _input;
    std::string temp = "";
    int ptr = 0;
};
