#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 9, K = 20;
vector<int> g[N];
int n, a[N], disc[N], finish[N], timer, val[N];
int tree[N][K];

void clr(int n) {
  timer = 0;
  for (int i = 0; i <= n; i++) {
    val[i] = 0;
    disc[i] = 0;
    finish[i] = 0;
    g[i].clear();
    for (int k = 0; k < K; k++) {
      tree[i][k] = 0;
    }
  }
}


int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = val[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = max(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int query(int l, int r) {
  if (l > r) return 0;
  int k = log2_floor(r - l + 1);
  return max(tree[l][k], tree[r - (1 << k) + 1][k]);
}

void dfs(int u, int p) {
  disc[u] = ++timer;
  val[disc[u]] = a[u];
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  finish[u] = timer;
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  timer = 0;
  dfs(1, 0);
  build(n);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = disc[i], r = finish[i];
    if (max(query(1, l - 1), query(r + 1, n)) > a[i] and a[i] > a[ans]) ans = i;
  }

  cout << ans << '\n';
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