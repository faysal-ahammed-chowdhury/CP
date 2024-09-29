#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 505, S = 16;
const ll inf = 1e18;
int n, m, ss;
vector<array<int, 2>> g[N];
ll dis[N][N];
vector<int> stops(N);
pair<int, ll> dp[(1 << S) + 3][S];

void dijkstra(int s) {
  vector<bool> vis(n + 1, false);
  dis[s][s] = 0;
  priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (auto [v, w] : g[u]) {
      if (dis[s][v] > d + w) {
        dis[s][v] = d + w;
        pq.push({d + w, v});
      }
    }
  }
}

pair<int, ll> f(int mask, int last) {
  if (dp[mask][last].first != -1) return dp[mask][last];
  ll ans1 = 0, ans2 = dis[stops[last]][n];
  bool flag = true;
  for (int i = 0; i < stops.size(); i++) {
    int v = stops[i];
    if (CHECK(mask, i) == false and dis[stops[last]][v] < inf) {
      flag = false;
      int new_mask = mask | (1 << i);
      auto cur = f(new_mask, i);
      if (cur.first + 1 == ans1) {
        ans2 = min(ans2, cur.second + dis[stops[last]][v]);
      }
      else if (cur.first + 1 > ans1 and cur.second < inf) {
        ans1 = cur.first + 1;
        ans2 = cur.second + dis[stops[last]][v];
      }
    }
  }
  return dp[mask][last] = {ans1, ans2};
}

int cs;
void solve() {
  cin >> n >> m >> ss;

  stops.clear();
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    for (int j = 0; j <= n; j++) {
      dis[i][j] = inf;
    }
  }

  bool has_stops_in_1 = false;
  for (int i = 1; i <= ss; i++) {
    int x; cin >> x;
    stops.push_back(++x);
    has_stops_in_1 |= x == 1;
  }
  if (!has_stops_in_1) stops.push_back(1);
  sort(stops.begin(), stops.end());
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    ++u, ++v;
    g[u].push_back({v, w});
  }

  for (int i = 1; i <= n; i++) {
    dijkstra(i);
  }

  memset(dp, -1, sizeof dp);
  auto [ans1, ans2] = f((1 << 0), 0);
  ans1 += has_stops_in_1;
  cout << "Case " << ++cs << ": ";
  if (ans2 >= inf) cout << "Impossible\n";
  else cout << ans1 << ' ' << ans2 << '\n';
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