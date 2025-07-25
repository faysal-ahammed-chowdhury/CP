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

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

const int N = 27, inf = 1e9;
string g[N];
int n;
vector<pair<int, int>> humans, ghosts;
int dis[55][N][N];

bool is_valid(int i, int j) {
  return i >= 1 and i <= n and j >= 1 and j <= n and g[i][j] != '#';
}

void bfs(int i, int j, int id) {
  queue<pair<int, int>> q;
  q.push({i, j});
  dis[id][i][j] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
      int nwx = x + dx[k], nwy = y + dy[k];
      if (is_valid(nwx, nwy) and dis[id][nwx][nwy] == inf) {
        dis[id][nwx][nwy] = dis[id][x][y] + 1;
        q.push({nwx, nwy});
      }
    }
  }
}

bool ok(int time) {
  int sz1 = ghosts.size(), sz2 = humans.size();
  Dinic dinic(2 + sz1 + sz2 + 1);
  for (int i = 0; i < sz1; i++) {
    int u = i + 2, id = i + 1;
    dinic.AddEdge(1, u, 1);
    for (int j = 0; j < sz2; j++) {
      auto [x, y] = humans[j];
      int v = j + 2 + sz1;
      int d = dis[id][x][y];
      if (d <= time) {
        dinic.AddEdge(u, v, 1);
      }
    }
  }
  for (int j = 0; j < sz2; j++) {
    int u = j + sz1 + 2;
    dinic.AddEdge(u, sz1 + sz2 + 2, 1);
  }
  return dinic.GetMaxFlow(1, sz1 + sz2 + 2) >= sz2;
}

int cs;
void solve() {
  cin >> n;
  humans.clear(), ghosts.clear();
  for (int i = 1; i <= n; i++) {
    cin >> g[i];
    g[i] = '.' + g[i];
    for (int j = 1; j <= n; j++) {
      if (g[i][j] == 'H') humans.push_back({i, j});
      else if (g[i][j] == 'G') ghosts.push_back({i, j});
    }
  }

  for (int id = 0; id <= 50; id++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dis[id][i][j] = inf;
      }
    }
  }

  int id = 1;
  for (auto [i, j] : ghosts) {
    bfs(i, j, id++);
    // cout << i << ' ' << j << '\n';
  }

  int l = 1, r = inf, ans = inf;
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
  cout << "Case " << ++cs << ": ";
  if (ans >= inf) cout << "Vuter Dol Kupokat\n";
  else {
    ans = ans * 2 + 2;
    cout << ans << '\n';
  }
  // cout << ok(4) << '\n';
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