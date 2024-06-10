#include <bits/stdc++.h>
using namespace std;

#define i128 __int128

void solve() {
  long long n; cin >> n;
  long long ans = 1;
  i128 x;

  i128 p = 8;
  while (true) {
    i128 r = (p + 1) * (p + 1) - 1;
    if (r > n) break;
    ans++;
    p *= 10;
    p += 18;
  }

  p = 9;
  while (true) {
    i128 l = p * (p + 1);
    i128 r = (p + 1) * (p + 1) - 1;
    if (l > n) break;
    x = r < n ? r : n;
    ans += x - l + 1;
    p *= 10;
    p += 9;
  }

  p = 10;
  while (true) {
    i128 l = p * p;
    i128 r = l + p - 1;
    if (l > n) break;
    x = r < n ? r : n;
    ans += x - l + 1;
    p *= 10;
  }

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