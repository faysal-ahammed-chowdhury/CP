#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
long long a[N];

void solve() {
  int n, u; cin >> n >> u;
  for (int i = 1; i <= n; i++) {
    a[i] = 0;
  }
  while (u--) {
    int l, r, val; cin >> l >> r >> val;
    l++, r++;
    a[l] += val;
    a[r + 1] -= val;
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }

  int q; cin >> q;
  while (q--) {
    int i; cin >> i;
    i++;
    cout << a[i] << '\n';
  }
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