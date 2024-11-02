#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
int n, m, dp[105][(1 << 16) + 5];
vector<int> v[105];

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

int f(int i, int mask) {
  if (i > m) {
    if (__builtin_popcount(mask) == n) return 1;
    return 0;
  }
  int &ans = dp[i][mask];
  if (ans != -1) return ans;
  ans = f(i + 1, mask);
  for (auto x : v[i]) {
    if (CHECK(mask, x) == false) {
      ans += f(i + 1, mask | (1 << x));
      ans %= mod;
    }
  }
  return ans;
}

void solve() {
  for (int i = 1; i <= 100; i++) {
    v[i].clear();
  }
  cin >> n;
  string a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> m;
  string b[m + 1];
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      bool ok = true;
      for (int k = 0; k < 4; k++) {
        if (a[i][k] == '?') continue;
        ok &= a[i][k] == b[j][k];
      }
      if (ok) {
        v[j].push_back(i);
      }
    }
  }

  // for (int j = 1; j <= m; j++) {
  //   cout << j << ": ";
  //   for (auto x : v[j]) {
  //     cout << x << ' ';
  //   }
  //   cout << '\n';
  // }

  memset(dp, -1, sizeof dp);
  cout << f(1, 0) << '\n';
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