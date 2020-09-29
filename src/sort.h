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
        if (_feature == "area")
        {
            return lo->area() < hi->area();
        }

        else if (_feature == "perimeter")
        {
            return lo->perimeter() < hi->perimeter();
        }
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

    /*if (first < last)
    {
        //printf("%d\n", first);
        auto q = partition123(first, last, comp);
        quickSort(first, q, comp);
        quickSort(q + 1, last, comp);
    }*/

    //randomized version
    if (first < last)
    {
        //printf("%d\n", first);
        auto q = Random_partition(first, last, comp);
        quickSort(first, q, comp);
        quickSort(q + 1, last, comp);
    }
}

template <class RAIterator, class Compare123>
//RAIterator partition123(RAIterator first, RAIterator last, Compare123 comp)
RAIterator partition123(RAIterator first, RAIterator last, Compare123 comp)
{
    // 請參考 https://en.wikipedia.org/wiki/Quicksort
    auto pivot = last - 1;
    //RAIterator j;
    auto i = first;
    for (auto j = first; j < pivot; j++)
    {
        if (comp(*j, *pivot))
        {
            std::swap(*j, *i);
            i++;
        }
    }
    std::swap(*i, *pivot);
    return i;
}
template <class RAIterator, class Compare123>
RAIterator Random_partition(RAIterator first, RAIterator last, Compare123 comp)
{
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int random_variable = std::rand();
    int dist = std::distance(first, last); //取得需比較之數量
    int i = random_variable % dist;
    //printf("%d %d %d\n", random_variable, dist, i);
    std::swap(*(last - 1), *(first + i));
    return partition123(first, last, comp);
}