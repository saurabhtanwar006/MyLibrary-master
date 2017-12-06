struct union_find {
  int components;
  vector<int> root, next, size;
  void clear(int n) {
    components = n;
    root.resize(n);
    iota(root.begin(), root.end(), 0);
    next.assign(n, -1);
    size.assign(n,  1);
  }
  bool find(int x, int y) { return root[x] == root[y]; }
  bool unite(int x, int y) {
    if ((x = root[x]) == (y = root[y])) return false;
    if (size[x] < size[y]) swap(x, y);
    size[x] += size[y];
    for (int z; y >= 0; y = z) {
      z = next[y];
      next[y] = next[x];
      next[x] = y;
      root[y] = x;
    }
    --components;
    return true;
  }
};
// item enumeration above
struct union_find {
  vector<int> p; 
  union_find(int n) : p(n, -1) { };
  bool unite(int u, int v) { 
    if ((u = root(u)) == (v = root(v))) return false;
    if (p[u] > p[v]) swap(u, v);
    p[u] += p[v]; p[v] = u;
    return true;
  }
  bool find(int u, int v) { return root(u) == root(v); }
  int root(int u) { return p[u] < 0 ? u : p[u] = root(p[u]); }
  int size(int u) { return -p[root(u)]; }
};
