#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  int mx = n;
  if (n % 2 == 0) {
    int msb = __lg(n);
    mx = (1ll << (msb + 1)) - 1;
  }

  int x = 0;
  cout << mx << '\n';
  if ((n & 1) or (__builtin_popcount(n) == 1)) {
    x = 1;
    cout << "2 1 3 ";
    for (int i = 4; i <= n; i++) {
      cout << i << ' ';
      if (i & 1) x &= i;
      else x |= i;
    }
    cout << '\n';
  }
  else {
    int msb = __lg(n);
    int x1 = 1ll << (msb);
    int x2 = x1 + 1;
    int x3 = x1 - 1;
    int i = 1, cnt = 1;
    while (i <= n - 3) {
      if (cnt == x1 or cnt == x2 or cnt == x3) {
        cnt++;
        continue;
      }
      cout << cnt << ' ';
      if (i & 1) x &= cnt;
      else x |= cnt;
      i++, cnt++;
    }
    cout << x1 << ' ' << x2 << ' ' << x3 << '\n';
    x |= x1;
    x &= x2;
    x |= x3;
  }
  assert(mx == x);
  // cout << x << '\n';
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