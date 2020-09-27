bool areaAscendingCompare(Shape *a, Shape *b)
{
    return true;
};

bool areaDescendingCompare(Shape *a, Shape *b)
{
    return true;
};

bool perimeterAscendingCompare(Shape *a, Shape *b)
{
    return true;
};

bool perimeterDescendingCompare(Shape *a, Shape *b)
{
    return true;
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
};

//RAIterator = RandomAccessIterator
template <class RAIterator, class Compare123>
void quickSort(RAIterator first, RAIterator last, Compare123 comp)
{
    RAIterator *q;
    if (first < last)
    {
        //printf("%d\n", first);
        **q = partition123(*first, *last, comp);
        printf("hi4\n");
        quickSort(first, *q - 1, comp);
        printf("hi5\n");
        quickSort(*q, last, comp);
        printf("hi6\n");
    }
    //RAIterator i,j;
    //if (comp(first, last))
}

template <class RAIterator, class Compare123>
RAIterator partition123(RAIterator first, RAIterator last, Compare123 comp)
{
    // 請參考 https://en.wikipedia.org/wiki/Quicksort
    RAIterator pivot = last;
    RAIterator j;
    RAIterator i = first;
    for (j = first; j < last; j++)
    {
        printf("hi1\n");
        if (comp(j, pivot))
        {
            printf("hi2\n");
            std::swap(j, pivot);
            printf("hi3\n");
            i++;
        }
    }
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