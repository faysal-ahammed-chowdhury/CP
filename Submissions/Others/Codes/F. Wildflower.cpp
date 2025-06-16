#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, mod = 1e9 + 7;
vector<int> g[N];

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
}

int leaf_cnt, left_cnt, right_cnt;

int dfs(int u, int p) {
  bool leaf = true;
  int sz = 1;
  vector<int> vec;
  for (auto v : g[u]) {
    if (v != p) {
      leaf = false;
      int x = dfs(v, u);
      vec.push_back(x);
      sz += x;
    }
  }
  if (vec.size() == 2) {
    left_cnt = vec.front();
    right_cnt = vec.back();
  }
  if (leaf) leaf_cnt++;
  return sz;
}

void solve() {
  int n; cin >> n;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  leaf_cnt = 0;
  dfs(1, 0);

  if (leaf_cnt > 2) cout << 0 << '\n';
  else if (leaf_cnt == 1) cout << power(2, n, mod) << '\n';
  else {
    if (left_cnt < right_cnt) swap(left_cnt, right_cnt);
    if (left_cnt == right_cnt) {
      int rem = n - (left_cnt * 2);
      int ans = power(2, rem, mod);
      ans = (ans + ans) % mod;
      cout << ans << '\n';
    }
    else {
      int rem = n - (right_cnt * 2);
      int ans = power(2, rem, mod);
      ans += power(2, rem - 1, mod);
      ans %= mod;
      cout << ans << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}