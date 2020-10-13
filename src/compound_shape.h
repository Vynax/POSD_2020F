class CompoundShape : public Shape
{
private:
    std::vector<Shape *> *_shapes;

public:
    CompoundShape(std::string id, std::vector<Shape *> *shapes) : Shape(id), _shapes(shapes)
    {
        _color = "transparent";
        // The default color of compound shape should be "transparent".
        if (_shapes->size() == 0)
            throw std::string("This is not a compound shape!");
        // When there's no shape contain in the compound shape,
        // should throw std::string "This is not a compound shape!"
    }

    double area() const
    {
        vector<Shape *>::iterator ptr;
        // return sum of all containing shapes area.
        double areaN;
        for (areaN = 0, ptr = _shapes->begin(); ptr < _shapes->end(); ptr++)
        {
            areaN += (*ptr)->area();
        }
        return areaN;
    }

    double perimeter() const
    {
        vector<Shape *>::iterator ptr;
        // return sum of all containing shapes perimeter.
        double perimeterN;
        for (perimeterN = 0, ptr = _shapes->begin(); ptr < _shapes->end(); ptr++)
        {
            perimeterN += (*ptr)->perimeter();
        }
        return perimeterN;
    }

    std::string info() const
    {
        // return list of all containing shapes info with wrapped of "CompoundShape {}".
        // ex."Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}"
        std::string str("Compound Shape {");
        vector<Shape *>::iterator ptr;
        for (ptr = _shapes->begin(); ptr < _shapes->end(); ptr++)
        {
            str += (*ptr)->info();
            if (ptr < (_shapes->end()) - 1)
                str += ", ";
        }
        str += "}";
        return str;
    }

    void addShape(Shape *shape)
    {
        // add shape into compound shape.
        _shapes->push_back(shape);
    }

    void deleteShapeById(std::string id)
    {
        // search and delete a shape through id,
        // search all the containing shapes and the tree structure below,
        // if no match of id, throw std::string "Expected delete shape but shape not found"
        vector<Shape *>::iterator ptr;
        for (ptr = _shapes->begin(); ptr < _shapes->end(); ptr++)
        {
            if ((*ptr)->id() == id)
            {
                _shapes->erase(ptr);
                return;
            }
            else if ((*ptr)->color() == "transparent")
            {
                if (deleteShapeInCompound(*ptr, id))
                    return;
            }
            // str += (*ptr)->info();
            // if (ptr < (_shapes->end()) - 1)
            //     str += ", ";
        }
        std::string("Expected delete shape but shape not found");
        return;
    }

    Shape *getShapeById(std::string id)
    {
        // search and return a shape through id,
        // search all the containing shapes and the tree structure below,
        // if no match of id, throw std::string "Expected get shape but shape not found"
        return 0;
    }

    bool deleteShapeInCompound(Shape *CS, std::string id)
    {
        vector<Shape *>::iterator ptr;
        for (ptr = _shapes->begin(); ptr < _shapes->end(); ptr++)
        {
            if ((*ptr)->id() == id)
            {
                _shapes->erase(ptr);
                return true;
            }
            else if ((*ptr)->color() == "transparent")
            {
                if (deleteShapeInCompound(*ptr, id))
                    return true;
            }
        }

        return false;
    }
};
