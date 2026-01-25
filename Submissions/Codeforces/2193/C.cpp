#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, q; cin >> n >> q;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    a[i] = max(a[i], b[i]);
  }

  for (int i = n - 1; i >= 1; i--) {
    a[i] = max(a[i], a[i + 1]);
  }

  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }

  while (q--) {
    int l, r; cin >> l >> r;
    cout << a[r] - a[l - 1] << ' ';
  } cout << '\n';
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