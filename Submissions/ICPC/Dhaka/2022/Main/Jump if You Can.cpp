#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 550;
const ll inf = 1e18;
vector<array<int, 2>> g[N];
int n, m, src, dest, mx_d, ext_d;
ll dis[N][N];
bool vis[N][N];

bool ok(int mx_energy) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= mx_energy; j++) {
      dis[i][j] = inf;
      vis[i][j] = false;
    }
  }
  dis[src][mx_energy] = 0;
  priority_queue<array<int, 3>> pq;
  pq.push({0, mx_energy, src});
  while (!pq.empty()) {
    auto [d, energy, u] = pq.top(); pq.pop();
    d = -d;
    int mn = inf, node = -1;
    if (energy > 0) {
      if (vis[u][energy]) continue;
      vis[u][energy] = true;
      for (auto [v, w] : g[u]) {
        mn = min(mn, w);
        if (mn == w) node = v;

        if (dis[v][energy - 1] >= d + w) {
          dis[v][energy - 1] = d + w;
          pq.push({ -dis[v][energy - 1], energy - 1, v});

          if (dis[v][mx_energy] >= d + ext_d + w + ext_d) {
            dis[v][mx_energy] = d + ext_d + w + ext_d;
            pq.push({ -dis[v][mx_energy], mx_energy, v});
          }
        }
      }

      if (node != -1) {
        if (dis[u][mx_energy] >= d + ext_d + mn) {
          dis[u][mx_energy] = d + ext_d + mn;
          pq.push({ -dis[u][mx_energy], mx_energy, u});
        }
      }
    }
  }

  for (int i = 1; i <= mx_energy; i++) {
    if (dis[dest][i] <= mx_d) return true;
  }
  return false;
}

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
}

int cs;
void solve() {
  cin >> n >> m >> src >> dest >> mx_d >> ext_d;
  clr(n);
  int tmp = m;
  while (tmp--) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  int l = 1, r = m + 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }

  cout << "Case " << ++cs << ": ";
  if (ans == -1) cout << "Impossible\n";
  else cout << ans << '\n';
  // cout << ok(1) << '\n';
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