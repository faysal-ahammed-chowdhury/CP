#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  string s; cin >> s;
  s = 'a' + s;
  int a[n + 1];
  memset(a, 0, sizeof(a));
  for (int i = 2; i <= n; i++) {
    if (s[i] == s[i - 1]) a[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }

  while (q--) {
    int l, r; cin >> l >> r;
    cout << a[r] - a[l] << '\n';
  }

  return 0;
}