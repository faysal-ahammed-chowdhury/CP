#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1005;
int n, k, lvl[N], dp[N][N];
vector<int> g[N];
int a[N];

void clr(int n) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    a[i] = 0;
  }
}

void dfs(int u, int p) {
  lvl[u] = lvl[p] + 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
}

int f(int i, int cnt) {
  if (i > n) return cnt;
  int &ans = dp[i][cnt];
  if (ans != -1) return ans;
  ans = f(i + 1, cnt);
  if (cnt >= a[i]) ans = min(ans, f(i + 1, cnt - a[i]));
  return ans;
}

void solve() {
  cin >> n >> k;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int p; cin >> p;
    g[i].push_back(p);
    g[p].push_back(i);
  }

  dfs(1, 0);
  int ans = n;
  for (int i = 2; i <= n; i++) {
    if (g[i].size() == 1) {
      ans = min(ans, lvl[i]);
    }
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (lvl[i] <= ans) {
      a[lvl[i]]++;
      cnt++;
    }
  }
  cnt = n - cnt;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = -1;
    }
  }

  int x = f(1, k);
  if (x > cnt) ans--;
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