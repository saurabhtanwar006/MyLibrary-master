
vector<int> precompute(const string &str)
{
    vector<int> b(str.size() + 1, 0);
    b[0] = -1;
    int j = -1;
    for(int i = 0; i < str.size(); ++i)
    {
        while(j >= 0 && str[i] != str[j]) j = b[j];
        ++j;
        b[i+1] = j;
    }
    return b;
}
vector<int> KMP(const string &heystack, const string &needle)
{
    vector<int> b = precompute(needle);
    vector<int> positions;
    int j = 0;
    for(int i = 0; i < heystack.size(); ++i)
    {
        while(j >= 0 && heystack[i] != needle[j]) j = b[j];
        ++j;
        if(j == needle.size())
        {
            positions.push_back(i-j+1);
            j = b[j];
        }
    }
    return positions;
}
