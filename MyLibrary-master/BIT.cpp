struct FT
{
    std::vector<int> data;
    FT(int size)
    {
        data.resize(size+1);
    }
    void insert(int idx, int value)
    {
        while(idx < data.size())
        {
            data[idx] += value;
            idx += idx & -idx;
        }
    }
    int rsq(int from, int to)
    {
        return getSum(to) - getSum(from-1);
    }
    int getSum(int element)
    {
        int value = 0;
        while(element != 0)
        {
            value += data[element];
            element = element & (element - 1);
        }
        return value;
    }
};
