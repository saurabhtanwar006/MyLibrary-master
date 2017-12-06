struct DisjointSet
{
    vector<int> parent;
    vector<int> height;
    DisjointSet(int size)
    {
        ++size;
        parent.resize(size);
        height.resize(size);
    }
    void join(int element1, int element2)
    {
        if(find(element1) == find(element2)) return;
        int c1 = find(element1);
        int c2 = find(element2);
        if(height[c1] == height[c2])
        {
            ++height[c1];
            parent[c2] = c1;
        }
        else if(height[c1] > height[c2]) parent[c2] = c1;
        else parent[c1] = c2;
    }
    int find(int element)
    {
        if(parent[element] == 0) return element;
        parent[element] = find(parent[element]);
        return parent[element];
    }
    bool sameSet(int element1, int element2)
    {
        return find(element1) == find(element2);
    }
};

