bool areaAscendingCompare(Shape *a, Shape *b)
{
    return (a->area() < b->area());
};

bool areaDescendingCompare(Shape *a, Shape *b)
{
    return a->area() > b->area();
};

bool perimeterAscendingCompare(Shape *a, Shape *b)
{
    return a->perimeter() < b->perimeter();
};

bool perimeterDescendingCompare(Shape *a, Shape *b)
{
    return a->perimeter() > b->perimeter();
};

class AscendingCompare
{
private:
    std::string _feature;

public:
    AscendingCompare(std::string feature) : _feature(feature) {}
    bool operator()(Shape *lo, Shape *hi)
    {
        printf("hi7\n");
        if (_feature == "area")
        {
            printf("hi8\n");
            return lo->area() < hi->area();
        }

        else if (_feature == "perimeter")
        {
            printf("hi9\n");
            return lo->perimeter() < hi->perimeter();
        }
        printf("hi10\n");
        return 0;
    }
};

class DescendingCompare
{
private:
    std::string _feature;

public:
    DescendingCompare(std::string feature) : _feature(feature) {}
    bool operator()(Shape *lo, Shape *hi)
    {
        if (_feature == "area")
        {
            return lo->area() > hi->area();
        }

        else if (_feature == "perimeter")
        {
            return lo->perimeter() > hi->perimeter();
        }
        return 0;
    }
};

//RAIterator = RandomAccessIterator
template <class RAIterator, class Compare123>
void quickSort(RAIterator first, RAIterator last, Compare123 comp)
{

    if (first < last)
    {
        //printf("%d\n", first);
        auto q = partition123(first, last, comp);
        printf("hi4\n");
        quickSort(first, q, comp);
        printf("hi5\n");
        quickSort(q + 1, last, comp);
        printf("hi6\n");
    }
    //RAIterator i,j;
    //if (comp(first, last))
}

template <class RAIterator, class Compare123>
RAIterator partition123(RAIterator first, RAIterator last, Compare123 comp)
{
    // 請參考 https://en.wikipedia.org/wiki/Quicksort
    auto pivot = last - 1;
    //RAIterator j;
    auto i = first;
    for (auto j = first; j < pivot; j++)
    {
        printf("hi1\n");
        if (comp(*j, *pivot))
        {
            printf("hi2\n");
            std::swap(*j, *i);
            printf("hi3\n");
            i++;
        }
    }
    std::swap(*i, *pivot);
    return i;
}

void RAndom_partition()
{
    /*std::srand(std::time(nullptr)); // use current time as seed for random generator
    int random_variable = std::rand();
    int dist = std::distance(first, last);
    int i = random_variable % dist;
    printf("%d %d %d\n", random_variable, dist, i);
    std:swap( last, first+i);*/
}