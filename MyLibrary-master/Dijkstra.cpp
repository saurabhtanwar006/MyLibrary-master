struct Edge
{
    int node, cost;
    Edge(int node, int cost)
    {
        this->node = node;
        this->cost = cost;
    }
    bool operator < (const Edge &b) const
    {
        return this->cost < b.cost;
    }
};
const int MAXN = 1000;
vector<Edge> G[MAXN];
int dist[MAXN];
int parent[MAXN];
bool used[MAXN];
void Dijkstra(int root)
{
    fill(dist, &dist[MAXN], 1 << 30);
    fill(parent, &parent[MAXN], -1);
    priority_queue<Edge> Q;
    dist[root] = 0;
    Q.push(Edge(root, 0));

    while(!Q.empty())
    {
        int currentNode = Q.top().node;
        Q.pop();
        for(size_t i = 0; i < G[currentNode].size(); ++i)
        {
            int child = G[currentNode][i].node;
            int cost = G[currentNode][i].cost;
            if(used[child])continue;
            if(dist[currentNode] + cost < dist[child])
            {
                dist[child] = dist[currentNode] + cost;
                parent[child] = currentNode;
                Q.push(Edge(child, -dist[child]));
            }
        }
        used[currentNode] = true;
    }
}
void printPath(int node)
{
    if(node == -1) return;
    printPath(parent[node]);
    cout<<node<<" ";
}
