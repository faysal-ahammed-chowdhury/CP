#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
long long a[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[0] = 0;
  sort (a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }

  while (q--) {
    long long x; cin >> x;
    auto it = upper_bound(a + 1, a + n + 1, x);
    int idx = (*it == x ? it - a : it - a - 1);
    cout << idx << '\n';
  }

  return 0;
}