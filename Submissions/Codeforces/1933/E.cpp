#include <bits/stdc++.h>
using namespace std;

#define int long long
int get(int n) {
  return (n * (n + 1)) / 2;
}

void solve() {
  int n; cin >> n;
  int a[n +  1];
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  int q; cin >> q;
  while (q--) {
    int l, u; cin >> l >> u;
    int x = a[l - 1] + u;
    auto it = lower_bound(a + 1, a + n + 1, x);
    if (it - a == n + 1) {
      cout << n << ' ';
    }
    else {
      int r = it - a;
      int r2 = r - 1;
      if (r == l) {
        cout << r << ' ';
        continue;
      }
      int sum1 = a[r] - a[l - 1];
      int sum2 = a[r2] - a[l - 1];
      int neg = sum1 - (u + 1);
      neg = max(neg, 0ll);
      int ans1 = get(u) - get(neg);
      int ans2 = get(u) - get(u - sum2);
      if (ans1 > ans2) {
        cout << r << ' ';
      }
      else {
        cout << r2 << ' ';
      }
    }
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}