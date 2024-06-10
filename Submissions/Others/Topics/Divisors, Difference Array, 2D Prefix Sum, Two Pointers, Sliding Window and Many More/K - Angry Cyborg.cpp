#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
long long a[N], prefix[N];

void solve() {
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    prefix[i] = a[i] = 0;
  }
  while (q--) {
    int l, r; cin >> l >> r;
    a[l]++;
    a[r + 1]--;
    prefix[r + 1] -= (r - l + 1);
  }

  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    prefix[i] += prefix[i - 1] + a[i];
  }

  for (int i = 1; i <= n; i++) {
    cout << prefix[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}