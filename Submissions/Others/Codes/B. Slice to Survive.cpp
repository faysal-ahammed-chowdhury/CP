#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(int n) {
  // if (n == 1) return 0;
  // return 1 + f(n / 2);
  return ceil(log2(n));
}

void solve() {
  int n, m, a, b; cin >> n >> m >> a >> b;
  int ans = 1 + f(a) + f(m);
  ans = min(ans, 1 + f(n) + f(b));
  ans = min(ans, 1 + f(n - a + 1) + f(m));
  ans = min(ans, 1 + f(n) + f(m - b + 1));
  cout << ans << '\n';
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