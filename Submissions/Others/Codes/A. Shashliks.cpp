#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int k, a, b, x, y; cin >> k >> a >> b >> x >> y;
  if (x > y) {
    swap(x, y);
    swap(a, b);
  }
  if (x == y) {
    if (a > b) swap(a, b);
  }

  int ans = 0;
  if (k >= a) {
    int cnt = (k - a) / x;
    ans += cnt;
    k -= cnt * x;
    if (k >= a) {
      ans++;
      k -= x;
    }
  }
  if (k >= b) {
    int cnt = (k - b) / y;
    ans += cnt;
    k -= cnt * y;
    if (k >= b) {
      ans++;
    }
  }
  cout << max(0, ans) << '\n';
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