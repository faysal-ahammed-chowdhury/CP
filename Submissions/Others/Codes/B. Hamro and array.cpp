#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
    if (i & 1) {
      a[i] = -a[i];
    }
    else {
      b[i] = -b[i];
    }
  }

  ll pref_a[n + 1], pref_b[n + 1];
  pref_a[0] = 0, pref_b[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref_a[i] = pref_a[i - 1] + a[i];
    pref_b[i] = pref_b[i - 1] + b[i];
  }

  while (q--) {
    int l, r; cin >> l >> r;
    if (a[l] >= 0) {
      cout << pref_a[r] - pref_a[l - 1] << '\n';
    }
    else {
      cout << pref_b[r] - pref_b[l - 1] << '\n';
    }
  }

  return 0;
}