#ifndef SCANNER_H
#define SCANNER_H

class Scanner
{
public:
    Scanner(std::string input = "") : _input(input) {}

    std::string nextToken()
    {
        // return next token.
        // throw exception std::string "next char doesn't exist." if next token not found.

        char c = _input[ptr];
        char punct[] = {'[', ']', '{', '}', '(', ')', ','}; // punctuation 標點符號
        char *p;
        int punct_size = sizeof(punct) / sizeof(punct[0]);
        temp = "";
        int size = _input.size();

        if (_input[ptr] == '\0')
            throw std::string("next char doesn't exist.");
        //忽略空白
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
        p = std::find(punct, punct + punct_size, c);
        //if (c == '(' || c == ',' || c == ')')
        if (p != punct + punct_size)
        {
            ptr++;
            temp = c;
        }
        //擷取token
        else
        {
            for (; ptr < size; ptr++)
            {
                p = std::find(punct, punct + punct_size, _input[ptr]);
                //if (_input[ptr] == '(' || _input[ptr] == ',' || _input[ptr] == ')' || _input[ptr] == ' ')
                if (p != punct + punct_size || _input[ptr] == ' ')
                    break;
                temp += _input[ptr];
            }
        }
        //cout << temp << endl;

        return temp;
    }

    bool isNum(string str)
    {
        stringstream sin(str);
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
};

#endif