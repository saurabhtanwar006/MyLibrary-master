
const int MAXN = 1000 * 1000 + 10;

int fen[MAXN];

void add(int x, int val)
{
    for (int i = x + 1; i < MAXN; i += i & (-i)) fen[i] += val;
}

int get(int x)
{
    int ans = 0;
    for (int i = x; i > 0; i -= i & (-i)) ans += fen[i];
    return ans;
}

int sum(int x, int y)
{
    return get(y) - get(x);
}

