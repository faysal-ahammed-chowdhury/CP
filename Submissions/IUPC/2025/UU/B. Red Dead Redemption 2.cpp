#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 9, MAXV = 5e6 + 9, mod = 998244353;
int spf[MAXV];
vector<int> g[N];
int col[N];
bool ok;

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

void spf_sieve() {
  for (int i = 2; i < MAXV; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < MAXV; i++) {
    if (spf[i] == i) {
      for (int j = i; j < MAXV; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

void dfs(int u, int c) {
  col[u] = c;
  // cout << u << ' ' << col[u] << '\n';
  for (auto v : g[u]) {
    if (col[v] == 0) {
      dfs(v, c == 1 ? 2 : 1);
    }
    else {
      ok &= col[u] != col[v];
    }
  }
}

void clr(int n) {
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    col[i] = 0;
  }
}

void solve() {
  int n; cin >> n;
  clr(n);
  int a[n + 1];
  map<int, vector<int>> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int x = a[i];
    while (x > 1) {
      int p = spf[x];
      mp[p].push_back(i);
      while (x % p == 0) {
        x /= p;
      }
    }
  }

  bool flag = false;
  for (auto [p, vec] : mp) {
    if (vec.size() > 2) {
      cout << 0 << '\n';
      return;
    }
    if (vec.size() == 2) {
      flag = true;
      int x = vec.front();
      int y = vec.back();
      g[x].push_back(y);
      g[y].push_back(x);
      // cout << x << ' ' << y << '\n';
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << a[i] << ' ';
  //   for (auto v : g[a[i]]) {
  //     cout << v << ' ';
  //   }
  //   cout << '\n';
  // }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (col[i] != 0) continue;
    ok = true;
    dfs(i, 1);
    if (!ok) {
      cout << 0 << '\n';
      return;
    }
    cnt++;
  }
  int ans = power(2, cnt, mod);
  if (!flag) {
    ans = power(2, cnt, mod);
    ans -= 2;
    if (ans < 0) ans += mod;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}