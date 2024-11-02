#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;

ll get(int n) {
  return (1ll * n * (n + 1)) / 2;
}

ll get(int l, int r) {
  return get(r) - get(l - 1);
}

ll f(int x) {
  return abs(get(k, x) - get(x + 1, n + k - 1));
}

void solve() {
  cin >> n >> k;
  int l = k, r = n + k - 1;
  ll ans = 0;
  while (l <= r) {
    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;
    if (f(mid1) <= f(mid2)) {
      ans = f(mid1);
      r = mid2 - 1;
    }
    else {
      l = mid1 + 1;
    }
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
// https://codeforces.com/contest/2009/problem/E