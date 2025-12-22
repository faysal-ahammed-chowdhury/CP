#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, inf = 1e9;
vector<int> g[N];
int n, k;

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
}

int cnt;
int dfs(int u, int p, int rad) {
  int mn = inf, mx = -inf;
  bool leaf = true;
  for (auto v : g[u]) {
    if (v != p) {
      leaf = false;
      int cur = dfs(v, u, rad);
      mn = min(mn, cur + 1);
      mx = max(mx, cur + 1);
    }
  }
  if (leaf) {
    mn = 0, mx = 0;
  }
  if (mn <= -1) {
    if (mx <= -1) return mn;
    else if (abs(mn) - 1 >= mx) return mn;
    else {
      if (mx == rad) {
        cnt++;
        return -(rad + 1);
      }

      return mx;
    }
  }
  if (mx == rad) {
    cnt++;
    return -(rad + 1);
  }

  return mx;
}

bool ok(int rad) {
  cnt = 0;
  int cur = dfs(1, 0, rad);
  if (cur >= 0) cnt++;
  if (cnt <= k) return true;
  return false;
}

void solve() {
  cin >> n >> k;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  if (n == k) {
    cout << 0;
    return;
  }

  int l = 1, r = n - 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  assert(ans != -1);
  cout << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
    if (t) cout << '\n';
  }

  return 0;
}