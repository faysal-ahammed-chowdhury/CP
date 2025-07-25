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
const double eps = 1e-6;
ll n, penguin_cnt;
double d;
array<int, 4> a[N];

double get_distance(double x1, double y1, double x2, double y2) {
  return sqrt((abs(x1 - x2) * abs(x1 - x2)) + (abs(y1 - y2) * abs(y1 - y2)));
}

bool f(int sink) {
  Dinic dinic(n + n + 1);
  for (int i = 1; i <= n; i++) {
    dinic.AddEdge(0, i, a[i][2]);
    if (i == sink) continue;
    dinic.AddEdge(i, i + n, a[i][3]);
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      double x = get_distance(a[i][0], a[i][1], a[j][0], a[j][1]);
      if (x - eps <= d) {
        int u = n + i;
        int v = j;
        dinic.AddEdge(u, v, a[i][3]);
      }
    }
  }

  int flow = dinic.GetMaxFlow(0, sink);
  // cout << flow << '\n';
  return flow >= penguin_cnt;
}

int cs;
void solve() {
  cin >> n >> d;
  penguin_cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    penguin_cnt += a[i][2];
  }

  cout << "Case " << ++cs << ": ";
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (f(i)) {
      cout << i - 1 << ' ';
      cnt++;
    }
  }
  if (cnt == 0) cout << -1;
  cout << '\n';
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