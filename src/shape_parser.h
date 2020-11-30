class ShapeParser
{
public:
    ShapeParser(std::string input)
    {
        // initialize a scanner for handling input.
        // initialize a shape builder for handling building shape.
    }

    void parser()
    {
        // using Scanner::nextToken() to get all information to determine what to build,
        // and provide the argument the shape needed.
        // use functions in ShapeBuilder to build out the shape.
        // the shape with invalid argument should be ignored (see example bellow).
    }

    std::deque<Shape *> getResult()
    {
        // return result.
        std::deque<Shape *> result;
        return result;
    }
};
