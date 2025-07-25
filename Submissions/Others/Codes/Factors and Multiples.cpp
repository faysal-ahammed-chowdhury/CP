#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Manual :
// Just Create an object of Dinic with number of total nodes
// then just add edges with AddEdge
// then just call GetMaxFlow to get the maximum flow
// Edges should be added in both direction separately if the graph is undirected
const int INF = 2e9;
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

const int N = 105;
int n, m;
vector<int> a, b;

int cs;
void solve() {
  a.clear(), b.clear();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    a.push_back(x);
  }
  cin >> m;
  Dinic dinic(2 + n + m);
  for (int i = 1; i <= n; i++) {
    dinic.AddEdge(0, i, 1);
  }
  for (int i = 1; i <= m; i++) {
    dinic.AddEdge(n + i, n + m + 1, 1);
    int x; cin >> x;
    b.push_back(x);
    for (int j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        for (int k = 0; k < n; k++) {
          if (a[k] == j) {
            dinic.AddEdge(k + 1, n + i, 1);
            // cout << k + 1 << ' ' << n + i << '\n';
          }
        }
        int another = (x / j);
        if (j != another) {
          for (int k = 0; k < n; k++) {
            if (a[k] == another) {
              dinic.AddEdge(k + 1, n + i, 1);
              // cout << k + 1 << ' ' << n + i << '\n';
            }
          }
        }
      }
    }
  }

  int bpm = dinic.GetMaxFlow(0, n + m + 1);
  cout << "Case " << ++cs << ": " << bpm << '\n';
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