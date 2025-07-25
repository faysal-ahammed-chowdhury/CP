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

const int N = 25;
vector<pair<int, int>> white, black;
int n, m;
string s[N];

bool is_connected(pair<int, int> a, pair<int, int> b) {
  int d = abs(a.first - b.first) + abs(a.second - b.second);
  return d == 1;
}

int cs;
void solve() {
  white.clear(), black.clear();
  cin >> n >> m;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'o') continue;
      cnt++;
      bool is_white = ((j % 2 == 0) + (i % 2 == 0)) % 2;
      if (is_white) white.push_back({i, j});
      else black.push_back({i, j});
    }
  }

  int sz1 = white.size(), sz2 = black.size();
  Dinic dinic(sz1 + sz2 + 2);
  for (int i = 0; i < sz1; i++) {
    dinic.AddEdge(0, i + 1, 1);
    for (int j = 0; j < sz2; j++) {
      int u = i + 1, v = sz1 + j + 1;
      if (is_connected(white[i], black[j])) {
        dinic.AddEdge(u, v, 1);
      }
    }
  }

  for (int i = 0; i < sz2; i++) {
    dinic.AddEdge(sz1 + i + 1, sz1 + sz2 + 1, 1);
  }

  int bpm = dinic.GetMaxFlow(0, sz1 + sz2 + 1);
  cout << "Case " << ++cs << ": " << cnt - bpm << '\n';
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