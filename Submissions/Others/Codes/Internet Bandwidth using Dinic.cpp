#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 105, inf = 1e9;
int n, m, st, en;

// Manual :
// Just Create an object of Dinic with number of total nodes
// then just add edges with AddEdge
// then just call GetMaxFlow to get the maximum flow
// Edges should be added in both direction separately if the graph is undirected
const int INF = 2000000000;
struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};
struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge*> dad;
  vector<int> Q;
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
  void AddEdge(int from, int to, int cap) {
    G[from].emplace_back(from, to, cap, 0, G[to].size());
    if (from == to) G[from].back().index++;
    G[to].emplace_back(to, from, 0, 0, G[from].size() - 1);
  }
  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = G[x][i];
        if (!dad[e.to] && e.cap - e.flow > 0) {
          dad[e.to] = &G[x][i];
          Q[tail++] = e.to;
        }
      }
    }
    if (!dad[t]) return 0;
    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
        if (!e) { amt = 0; break; }
        amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
        e->flow += amt;
        G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }
  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};
/*
**************************
*------ DINITZ ENDS
**************************
*/
// Initialization : Dinic *Rawaha=new Dinic(n+1);
// Add Edge : Rawaha->AddEdge(a,b,c);
// Get Max Flow : Rawaha->GetMaxFlow(s,t)

int cs;
void solve() {
  cin >> n >> st >> en >> m;
  Dinic *dinic = new Dinic(n + 1);
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    dinic->AddEdge(u, v, w);
    dinic->AddEdge(v, u, w);
  }

  cout << "Case " << ++cs << ": " << dinic->GetMaxFlow(st, en) << '\n';
  delete(dinic);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}