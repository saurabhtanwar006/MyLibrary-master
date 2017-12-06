struct FT2D
{
    std::vector<vector<int> > data;
    int sizeX, sizeY;
    FT2D(int sizeX, int sizeY)
    {
        this->sizeX = sizeX;
        this->sizeY = sizeY;
        data.resize(sizeX + 1);
        for(int i = 0; i <= sizeX; ++i)
        {
            data[i].resize(sizeY);
        }
    }
    void update(int x, int y, int val)
    {
        while(x <= sizeX)
        {
            int originalY = y;
            while(y <= sizeY)
            {
                data[x][y] += val;
                y += y & -y;
            }
            y = originalY;
            x += x & -x;
        }
    }
    int get(int x, int y)
    {
        int result = 0;
        while(x > 0)
        {
            int orignialY = y;
            while(y > 0)
            {
                result += data[x][y];
                y = y & (y-1);
            }
            x = x & (x-1);
            y = orignialY;
        }
        return result;
    }
};
