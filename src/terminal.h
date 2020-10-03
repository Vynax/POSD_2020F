#include <regex>

class Terminal
{
public:
    Terminal(std::string input)
    {
        std::string shapep("(Rectangle|Ellipse|Triangle)"); //shape pattern
        std::string spacep(" ");                            // space pattern
        std::string lparenthesis("\(");
        std::string decimal_point("[0-9]+(.[0-9]*)?"); //((Rectangle|Ellipse|Triangle) \( *[0-9]+(.[0-9]*)?, *[0-9]+(.[0-9]*)?\))|(Triangle) \(\[-?[0-9]+(.[0-9]*)? *, *-?[0-9]+(.[0-9]*)?
        std::string str;
        std::regex pattern;

        str = shapep + spacep + lparenthesis + ;
        pattern.assign(shapep + spacep);
    }
    std::string showResult()
    {
        return "";
    }
};
