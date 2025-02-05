#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2005, K = 20;
const ll inf = 1e18;
int n, s, q, F[N];
vector<pair<int, int>> g[N];
ll dp[N][N], tree[N][K];

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = dp[s][i - 1];
  }

  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = min(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]);
    }
  }
}

ll query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return min(tree[l][k], tree[r - (1 << k) + 1][k]);
}

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    for (int j = 0; j <= n; j++) {
      dp[i][j] = inf;
    }
  }
}

void dfs(int u, int p) {
  bool leaf = true;
  for (auto [v, w] : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    if (u == s) {
      for (int i = 0; i <= n - 2; i++) {
        ll cost = w + dp[v][i] - F[u];
        dp[u][i] = max(0ll, min(dp[u][i], cost));
      }
    }
    else {
      for (int i = 0; i <= n - 2; i++) {
        ll cost = w + dp[v][i]; // no stop
        dp[u][i] = max(0ll, min(dp[u][i], cost));

        if (i > 0) {
          cost = w + dp[v][i - 1] - F[u]; // stop
          dp[u][i] = max(0ll, min(dp[u][i], cost));
        }
      }
    }
    leaf = false;
  }

  if (leaf) dp[u][0] = 0;
}

void solve() {
  cin >> n >> s >> q;
  clr(n);
  for (int i = 1; i <= n; i++) cin >> F[i];
  for (int i = 1; i < n; i++) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  dfs(s, 0);
  build(n);

  // for (int i = 0; i <= n - 2; i++) {
  //   cout << dp[s][i] << ' ';
  // }
  // return;

  while (q--) {
    int x; cin >> x;
    int l = 0, r = n - 2, stop = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      ll mn = query(1, mid + 1);
      if (mn <= x) {
        stop = mid;
        r = mid - 1;
      }
      else l = mid + 1;
    }

    if (stop == -1) cout << "impossible\n";
    else cout << stop << '\n';
  }
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