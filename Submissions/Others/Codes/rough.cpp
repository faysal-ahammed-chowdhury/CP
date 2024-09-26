#include <bits/stdc++.h>
using namespace std;
#define int long long

// if we need phi(x) multiple times, then memorize it
map<int, int> dp;
int phi(int n) {
  if (dp.count(n)) return dp[n];
  int ans = n, m = n;
  for (int i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      while (m % i == 0) m /= i;
      ans = ans / i * (i - 1);
    }
  }
  if (m > 1) ans = ans / m * (m - 1);
  return dp[n] = ans;
}

int cs;
void solve() {
  int n, q; cin >> n >> q;
  cout << "Case " << ++cs << ": ";
  while (q--) {
    int m; cin >> m;
    if (n % m == 0) {
      int x = n / m;
      cout << phi(x) << ' ';
    }
    else cout << 0 << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}