#include <bits/stdc++.h>
using namespace std;
#define Fr(i, a, b) for (int (i) = (a); (i) <= (b); (i) ++)
#define Rf(i, a, b) for (int (i) = (a); (i) >= (b); (i) --)

#define endl '\n'
#define all(x) x.begin(),x.end()
#define mp make_pair

#define ll long long
#define ld long double
#define pb push_back

#define M 1000000007

#define pi 2*acos(0)
#define F first
#define S second
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(0)

typedef vector < int > vi;
typedef pair < int , int > pii;

const int INF = INT_MAX;
const ll INFL = LLONG_MAX;
const int size = 1e5 + 9;
typedef pair < int , ll > pli;
typedef pair < ll , int > node;
vector < pli > Adj[size];
int mark[size];
ll PR[size];
void Prim(int src){
  priority_queue < node , vector < node > , greater < node > > Q;
  Q.push(node(0,src));
  ll mst_weight=0;
  while(!Q.empty()){
    node tmp = Q.top();
    Q.pop();
    if(mark[tmp.S]==1)
      continue;
    mark[tmp.S] = 1;
    mst_weight += tmp.F;
    for(auto it : Adj[tmp.S]){
      if(mark[it.F]==1)
	continue;
      if(it.S<PR[it.F]){
	PR[it.F] = it.S;
	Q.push(node(it.S,it.F));
      }
    }
  }
  cout<<mst_weight<<endl;
}
int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<=n;i++)
    PR[i] = INF;
  // n nodes m edges
  for(int i=0;i<m;i++){
    int x,y,w;
    cin>>x>>y>>w;
    Adj[x].pb(pli(y,w));
    Adj[y].pb(pli(x,w));
  }
  int root=1;
  //cin>>root;
  Prim(root);
  return 0;
}
