#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(int n, ll row) {
  if (n == 0) {
    if (row == 2) return 2;
    return 4 - row + 1;
  } 
  ll tot = (1ll << (n + 2));
  ll half = tot / 2;
  if (row <= half) {
    return 2 * f(n - 1, row);
  }
  return f(n - 1, row - half);
}

int cs;
void solve() {
  ll k, n; cin >> k >> n;
  ll mx = (1ll << (n + 2));

  cout << "Case " << ++cs << ": ";
  if (k > mx) {
    cout << -1 << '\n';
    return;
  }
  k = mx - k + 1;
  cout << f(n, k) << '\n';
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