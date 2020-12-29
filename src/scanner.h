#ifndef SCANNER_H
#define SCANNER_H

#include <sstream>
class Scanner
{
public:
    Scanner(std::string input = "") : _input(input)
    {
    }

    std::string nextToken()
    {
        // return next token.
        // throw exception std::string "next char doesn't exist." if next token not found.

        char c = _input[ptr];
        std::vector<std::string> word;
        word.push_back("Ellipse");
        word.push_back("Rectangle");
        word.push_back("Triangle");
        word.push_back("CompoundShape");

        char punct[] = {'[', ']', '{', '}', '(', ')', ','}; // punctuation 標點符號
        std::vector<std::string> punct_vec;
        punct_vec.push_back("[");
        punct_vec.push_back("]");
        punct_vec.push_back("{");
        punct_vec.push_back("}");
        punct_vec.push_back("(");
        punct_vec.push_back(")");
        punct_vec.push_back(",");

        std::string punct_str[] = {"[", "]", "{", "}", "(", ")", ","};
        //char *p;
        //int punct_size = sizeof(punct) / sizeof(punct[0]);
        //int punct_size = strlen(punct);
        temp = "";
        int size = _input.size();
        //忽略空白
        if (_input[ptr] == '\0')
        {
            throw std::string("next char doesn't exist.");
        }
        while (!str_in_array(temp, word) && !str_in_array(temp, punct_vec) && !isNum(temp))
        {
            if (c == ' ')
            {
                ptr++;
                while (ptr < size)
                {
                    if (_input[ptr] != ' ')
                        break;
                    ptr++;
                }
                /*for (int i = ptr; i < _input.size(); i++)
            {
                if (_input[ptr] == ' ')
                    ptr++;
            }*/
            }

            c = _input[ptr];
            //如果第一個字元是這些就直接回傳

            //if (c == '(' || c == ',' || c == ')')
            //p = std::find(punct, punct + punct_size, c);
            //if (p != punct + punct_size)
            if (char_in_array(_input[ptr], punct))
            {
                ptr++;
                temp = c;
            }
            //擷取token
            else
            {
                for (; ptr < size; ptr++)
                {
                    //p = std::find(punct, punct + punct_size, _input[ptr]);
                    //if (_input[ptr] == '(' || _input[ptr] == ',' || _input[ptr] == ')' || _input[ptr] == ' ')
                    //if (p != punct + punct_size || _input[ptr] == ' ')
                    if (char_in_array(_input[ptr], punct) || _input[ptr] == ' ')
                        break;
                    temp += _input[ptr];
                }
            }
            //cout << temp << endl;
        }
        //cout << str_in_array("Ellipse", word) << endl;
        //cout << word[0] << endl;
        return temp;
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
        if (p != array + size) //如果input不在array裡面，p會指向最後面不存在的東西
            return true;
        else
            return false;
    }

    bool str_in_array(std::string input, std::vector<std::string> array)
    {
        // std::string *p;
        // size_t size = sizeof(array) / sizeof(array[0]);
        // p = std::find(array, array + size, input);
        for (size_t i = 0; i < array.size(); i++)
        {
            if (input == array[i])
                return true;
            //cout << array[i] << endl;
        }

        return false;
        /*if (p != array + size)
            return true;
        else
            return false;*/
    }
    bool isDone()
    {
        return done;
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
    std::string _input = "";
    std::string temp = "";
    int ptr = 0;
    bool done;
};

#endif