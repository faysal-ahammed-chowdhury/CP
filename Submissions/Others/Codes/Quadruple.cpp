#include <bits/stdc++.h>
using namespace std;

#define int long long
int get(int x, int n) {
  int hi = min(x - 1, n);
  int lo = x - hi;
  return hi - lo + 1;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int mn = 2, mx = n + n, ans = 0;
  for (int i = mn; i <= mx; i++) {
    int x = i - k;
    // cout << x << '\n';
    if (x >= mn and x <= mx) {
      // cout << i << ' ' << x << '\n';
      ans += get(i, n) * get(x, n);
    }
  }
  cout << ans << '\n';

  return 0;
}