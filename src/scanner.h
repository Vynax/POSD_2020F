class Scanner
{
public:
    Scanner(std::string input) : _input(input) {}

    std::string nextToken()
    {
        // return next token.
        // throw exception std::string "next char doesn't exist." if next token not found.

        char c = _input[ptr];
        char array[] = {'{', '}', '(', ')', ','};
        char *p;
        int array_size = sizeof(array) / sizeof(array[0]);
        temp = "";

        //忽略空白
        if (c == ' ')
        {
            ptr++;
            while (ptr < _input.size())
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

        if (_input[ptr] == '\0')
            throw std::string("next char doesn't exist.");
        c = _input[ptr];
        //如果第一個字元是這些就直接回傳
        p = std::find(array, array + array_size, c);
        //if (c == '(' || c == ',' || c == ')')
        if (p != array + array_size)
        {
            ptr++;
            temp = c;
        }
        //擷取token
        else
        {
            for (; ptr < _input.size(); ptr++)
            {
                p = std::find(array, array + array_size, _input[ptr]);
                //if (_input[ptr] == '(' || _input[ptr] == ',' || _input[ptr] == ')' || _input[ptr] == ' ')
                if (p != array + array_size || _input[ptr] == ' ')
                    break;
                temp += _input[ptr];
            }
        }
        //cout << temp << endl;

        return temp;
    }

private:
    std::string _input = "";
    std::string temp = "";
    int ptr = 0;
};
