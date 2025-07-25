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
int n, D;
vector<int> small, big;

bool ok(int d) {
  int sz1 = small.size(), sz2 = big.size();
  Dinic dinic(sz1 + sz1 + 1 + sz2 + 2);

  for (int i = 0; i < sz1; i++) {
    int u = i + 2, v = sz1 + i + 2;
    dinic.AddEdge(u, v, 1);
    // cout << u << ' ' << v << ' ' << 1 << '\n';
    for (int j = 0; j < sz1; j++) {
      if (i == j) continue;
      int dis = abs(small[i] - small[j]);
      if (dis <= d) {
        dinic.AddEdge(v, j + 2, 2);
        // cout << v << ' ' << j + 2 << ' ' << 2 << '\n';
      }
    }
    for (int j = 0; j < sz2; j++) {
      int dis = abs(small[i] - big[j]);
      if (dis <= d) {
        dinic.AddEdge(v, 2 + sz1 + sz1 + j, 2);
        // cout << v << ' ' << 2 + sz1 + sz1 + j << ' ' << 2 << '\n';
      }
    }
    int dis = small[i];
    if (dis <= d) {
      dinic.AddEdge(1, u, 2);
      // cout << 1 << ' ' << u << ' ' << 2 << '\n';
    }
    dis = abs(D - small[i]);
    if (dis <= d) {
      dinic.AddEdge(v, 2 + sz1 + sz1 + sz2, 2);
      // cout << v << ' ' << 2 + sz1 + sz1 + sz2 << ' ' << 2 << '\n';
    }
  }

  for (int i = 0; i < sz2; i++) {
    int u = sz1 + sz1 + i + 2;
    for (int j = 0; j < sz2; j++) {
      if (i == j) continue;
      int v = sz1 + sz1 + j + 2;
      int dis = abs(big[i] - big[j]);
      if (dis <= d) {
        dinic.AddEdge(u, v, 2);
        // cout << u << ' ' << v << ' ' << 2 << '\n';
      }
    }
    for (int j = 0; j < sz1; j++) {
      int v = j + 2;
      int dis = abs(big[i] - small[j]);
      if (dis <= d) {
        dinic.AddEdge(u, v, 2);
        // cout << u << ' ' << v << ' ' << 2 << '\n';
      }
    }

    int dis = big[i];
    if (dis <= d) {
      dinic.AddEdge(1, u, 2);
      // cout << 1 << ' ' << u << ' ' << 2 << '\n';
    }
    dis = abs(D - big[i]);
    if (dis <= d) {
      dinic.AddEdge(u, 2 + sz1 + sz1 + sz2, 2);
      // cout << u << ' ' << 2 + sz1 + sz1 + sz2 << ' ' << 2 << '\n';
    }
  }

  if (D <= d) {
    dinic.AddEdge(1, 2 + sz1 + sz1 + sz2, 2);
    // cout << 1 << ' ' << 2 + sz1 + sz1 + sz2 << ' ' << 2 << '\n';
  }

  int x = dinic.GetMaxFlow(1, 2 + sz1 + sz1 + sz2);
  // cout << "here: " << d << ' ' << x << '\n';

  return x >= 2;
}

int cs;
void solve() {
  small.clear(), big.clear();
  cin >> n >> D;
  for (int i = 1; i <= n; i++) {
    char c, tmp; cin >> c >> tmp;
    int x; cin >> x;
    if (c == 'S') small.push_back(x);
    else big.push_back(x);
  }

  int l = 1, r = D, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  // assert(ans != -1);
  cout << "Case " << ++cs << ": " << ans << '\n';
  // cout << ok(246) << '\n';
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