#include <regex>

class Terminal
{
public:
    Terminal(std::string input)
    {
        std::string shape("(Rectangle|Ellipse|Triangle)"); //shape pattern
        std::string space_plus(" +");                      // space pattern
        std::string space(" ");
        std::string lparenthesis("\(");
        std::string decimalN("-?[0-9]+(.[0-9]*)?"); //((Rectangle|Ellipse|Triangle) \( *[0-9]+(.[0-9]*)?, *[0-9]+(.[0-9]*)?\))|(Triangle) \(\[-?[0-9]+(.[0-9]*)? *, *-?[0-9]+(.[0-9]*)?
        std::string str;
        std::regex pattern;

        str = shape + space + lparenthesis + ;
        pattern.assign(shapep + spacep);
    }
    std::string showResult()
    {
        return "";
    }
};